#!/usr/bin/env python3
"""
Nodo puente UART entre ROS 2 y myRIO (protocolo ASCII).

Comandos (RPi -> myRIO):
  V<lin.x> <lin.y> <ang.z>\\n  (velocidad lineal en X e Y, angular en Z)
  R<pos>\\n                   (posición normalizada de la cremallera, 0.0-1.0)
  G<0/1>\\n                   (gripper: 0 abrir, 1 cerrar)
  E\\n                        (emergencia/reset)
  P\\n                        (ping)

Estado (myRIO -> RPi):
  A<dist_izq>B<dist_der>C<dist_tof>DE<0/1>F<0/1>G<0/1>\\r\\n
  Se recibe periódicamente (cada ~100 ms). El bridge lo publica en topics.

Características:
- Heartbeat automático: considera desconexión si no hay datos en 'status_timeout' segundos.
- Robusto frente a tramas corruptas o desconexiones del puerto serie.
- Escalable: añadir nuevos comandos solo requiere extender los callbacks.
"""

import time
import re
import serial
import threading

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool, Int8, UInt8, String, Float32


class UARTBridge(Node):
    def __init__(self):
        super().__init__('uart_bridge')

        # Parámetros ROS (sobrescribibles)
        self.declare_parameter('port', '/dev/ttyAMA1')
        self.declare_parameter('baudrate', 115200)
        self.declare_parameter('status_timeout', 0.5)

        port = self.get_parameter('port').value
        baud = self.get_parameter('baudrate').value
        self.timeout = self.get_parameter('status_timeout').value

        # Configuración del puerto serie
        try:
            self.ser = serial.Serial(port, baud, timeout=0.02)
        except serial.SerialException as e:
            self.get_logger().error(f"No se pudo abrir el puerto {port}: {e}")
            raise

        # Estado interno
        self.last_status_time = time.time()
        self.connected = False
        self.fault_published = False
        self.rx_buffer = ""

        # ---- Publicadores ----
        self.pub_ultra_left   = self.create_publisher(Float32, '/ultrasonic/left', 10)
        self.pub_ultra_right  = self.create_publisher(Float32, '/ultrasonic/right', 10)
        self.pub_rack_tof     = self.create_publisher(Float32, '/rack/tof', 10)
        self.pub_rack_extended = self.create_publisher(Bool, '/rack_extended', 10)
        self.pub_rack_retracted = self.create_publisher(Bool, '/rack_retracted', 10)
        self.pub_aligned      = self.create_publisher(Bool, '/distance_aligned', 10)
        self.pub_fault        = self.create_publisher(String, '/fault_myrio', 10)

        # ---- Suscriptores ----
        self.sub_cmd_vel  = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_cb, 10)
        self.sub_rack     = self.create_subscription(Int8, '/rack_cmd', self.rack_cb, 10)
        self.sub_gripper  = self.create_subscription(Bool, '/gripper_cmd', self.gripper_cb, 10)
        self.sub_flags    = self.create_subscription(UInt8, '/robot_flags', self.flags_cb, 10)

        # ---- Hilo de recepción UART ----
        self.rx_thread = threading.Thread(target=self.rx_loop, daemon=True)
        self.rx_thread.start()

        # ---- Timer de monitorización de comunicación ----
        self.create_timer(0.2, self.check_connection)

        self.get_logger().info("UART Bridge iniciado correctamente.")

    # ------------------------------------------------------------------
    # Envío de comandos
    # ------------------------------------------------------------------
    def _send_line(self, line: str):
        """Envía una línea de texto por el puerto serie, añadiendo '\\n'.
           Es thread-safe gracias al Lock."""
        with threading.Lock():
            try:
                self.ser.write((line + '\n').encode('ascii'))
                self.ser.flush()
            except serial.SerialException:
                self.get_logger().error("Error al escribir en el puerto serie")

    def cmd_vel_cb(self, msg: Twist):
        """Convierte Twist a comando V. Se envían las tres componentes relevantes:
           linear.x, linear.y, angular.z."""
        lin_x = msg.linear.x
        lin_y = msg.linear.y
        ang_z = msg.angular.z
        # Formato: V<lin.x> <lin.y> <ang.z> (2 decimales para no saturar la trama)
        self._send_line(f"V{lin_x:.2f} {lin_y:.2f} {ang_z:.2f}")

    def rack_cb(self, msg: Int8):
        """Comando de cremallera: 0 -> retraída, 1 -> extendida."""
        pos = max(0.0, min(1.0, float(msg.data)))
        self._send_line(f"R{pos:.2f}")

    def gripper_cb(self, msg: Bool):
        """Comando de gripper: True -> cerrar, False -> abrir."""
        val = 1 if msg.data else 0
        self._send_line(f"G{val}")

    def flags_cb(self, msg: UInt8):
        """Si el bit0 de robot_flags está a 1, se envía comando de emergencia 'E'."""
        if msg.data & 0x01:
            self._send_line("E")

    # ------------------------------------------------------------------
    # Recepción de tramas de estado
    # ------------------------------------------------------------------
    def rx_loop(self):
        """Hilo dedicado a leer del puerto serie y ensamblar líneas completas."""
        while rclpy.ok():
            try:
                byte = self.ser.read().decode('ascii', errors='ignore')
            except serial.SerialException:
                time.sleep(0.1)
                continue

            if not byte:
                continue

            if byte == '\n':
                line = self.rx_buffer.strip()
                self.rx_buffer = ""
                if line:
                    self._process_status(line)
            else:
                self.rx_buffer += byte

    def _process_status(self, line: str):
        """Parsea la línea de estado y publica los valores en los topics correspondientes."""
        # Actualizar el timestamp de heartbeat
        self.last_status_time = time.time()
        if not self.connected:
            self.connected = True
            self.get_logger().info("Comunicación con myRIO establecida.")
            self.fault_published = False

        # Expresión regular para extraer campos: A...B...C...D, y opcionales E, F, G
        match = re.match(
            r'^A([-+]?\d+\.?\d*)B([-+]?\d+\.?\d*)C([-+]?\d+\.?\d*)D'
            r'(?:E([01]))?(?:F([01]))?(?:G([01]))?$',
            line
        )

        if not match:
            self.get_logger().warn(f"Trama de estado no reconocida: '{line}'")
            return

        try:
            # Sensores de distancia
            dist_left  = float(match.group(1))
            dist_right = float(match.group(2))
            dist_tof   = float(match.group(3))
            self.pub_ultra_left.publish(Float32(data=dist_left))
            self.pub_ultra_right.publish(Float32(data=dist_right))
            self.pub_rack_tof.publish(Float32(data=dist_tof))

            # Flags de estado (opcionales pero esperados)
            ext   = match.group(4)  # fin de carrera extendido
            ret   = match.group(5)  # fin de carrera retraído
            align = match.group(6)  # alineación con la tubería

            if ext is not None:
                self.pub_rack_extended.publish(Bool(data=(ext == '1')))
            if ret is not None:
                self.pub_rack_retracted.publish(Bool(data=(ret == '1')))
            if align is not None:
                self.pub_aligned.publish(Bool(data=(align == '1')))

        except ValueError as e:
            self.get_logger().warn(f"Error al convertir valores en '{line}': {e}")

    # ------------------------------------------------------------------
    # Heartbeat y gestión de desconexión
    # ------------------------------------------------------------------
    def check_connection(self):
        """Verifica si el tiempo sin recibir datos supera el umbral.
           Si hay timeout, publica un mensaje de fallo una sola vez."""
        now = time.time()
        if (now - self.last_status_time) > self.timeout:
            if self.connected:
                self.connected = False
                self.get_logger().error("Timeout de comunicación con myRIO.")
            if not self.fault_published:
                self.pub_fault.publish(String(data="LOST_COMMUNICATION"))
                self.fault_published = True
        else:
            if not self.connected:
                self.connected = True
                self.get_logger().info("Comunicación reestablecida.")
                self.fault_published = False

    def destroy_node(self):
        """Cierra el puerto serie al destruir el nodo."""
        if self.ser.is_open:
            self.ser.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = UARTBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()