#!/usr/bin/env python3
"""
Puente UART hacia myRIO.
Formato de trama enviada: A#B#C#D#E#F\\r\\n
  A: 1 si hay comando de velocidad, 0 si no
  B: velocidad lineal (solo x, m/s)
  C: velocidad angular (rad/s)
  D, E, F: reservados (0)
Configuración del puerto: 8E2, 9600 baudios.
"""

import serial
import threading
import time

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class UARTBridge(Node):
    def __init__(self):
        super().__init__('uart_bridge')

        self.declare_parameter('port', '/dev/serial0')
        self.declare_parameter('baudrate', 9600)

        port = self.get_parameter('port').value
        baud = self.get_parameter('baudrate').value

        try:
            self.ser = serial.Serial(
                port=port,
                baudrate=baud,
                timeout=0,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_EVEN,
                stopbits=serial.STOPBITS_TWO
            )
        except serial.SerialException as e:
            self.get_logger().error(f"No se pudo abrir {port}: {e}")
            raise

        # Variables de velocidad actuales
        self.lin_x = 0.0
        self.ang_z = 0.0

        # Suscriptor al tópico de velocidad
        self.sub_cmd_vel = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_cb, 10)

        # Timer para reenvío periódico (cada 250 ms)
        self.timer = self.create_timer(0.25, self.send_velocity)

        self.get_logger().info("UART Bridge (formato A#B#C#D#E#F) iniciado.")

    def cmd_vel_cb(self, msg: Twist):
        """Actualiza las velocidades y envía inmediatamente."""
        self.lin_x = msg.linear.x
        self.ang_z = msg.angular.z
        self.send_velocity()

    def send_velocity(self):
        """Construye la trama y la envía por el puerto serie."""
        # A = 1 si hay velocidad (lineal o angular) distinta de cero
        a = 1 if (self.lin_x != 0.0 or self.ang_z != 0.0) else 0
        # Formatear con 2 decimales, relleno de ceros para D,E,F
        trama = f"{a}#{self.lin_x:.2f}#{self.ang_z:.2f}#0#0#0\r\n"

        with threading.Lock():
            try:
                self.ser.write(trama.encode('ascii'))
                self.ser.flush()
                self.get_logger().info(f"Enviado: {trama.strip()}")
            except serial.SerialException:
                self.get_logger().error("Error al escribir en UART")

    def destroy_node(self):
        if self.ser.is_open:
            self.ser.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = UARTBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()