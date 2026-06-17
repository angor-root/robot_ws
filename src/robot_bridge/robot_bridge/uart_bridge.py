#!/usr/bin/env python3
"""
Puente UART hacia myRIO.
Formato de trama enviada: A#B#C#D#E#F\\r\\n
  A : 1 si hay comando de velocidad, 0 si no
  B : velocidad lineal en mm/s (entero)
  C : velocidad angular en mrad/s (entero)
  D, E, F : reservados (0)
Configuración del puerto: 8E2, 9600 baudios.
"""

import serial
import threading

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool, Int8, UInt8

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

        self.lin_x = 0.0
        self.ang_z = 0.0

        self.sub_cmd_vel  = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_cb, 10)
        self.sub_rack     = self.create_subscription(Int8, '/rack_cmd', self.rack_cb, 10)
        self.sub_gripper  = self.create_subscription(Bool, '/gripper_cmd', self.gripper_cb, 10)
        self.sub_flags    = self.create_subscription(UInt8, '/robot_flags', self.flags_cb, 10)

        # Reenviar cada 250 ms
        self.timer = self.create_timer(0.25, self.send_velocity)

        self.get_logger().info("UART Bridge (A#B#C#D#E#F) iniciado.")

    def _send_line(self, line: str):
        with threading.Lock():
            try:
                self.ser.write(line.encode('ascii'))
                self.ser.flush()
            except serial.SerialException:
                self.get_logger().error("Error al escribir en UART")

    def cmd_vel_cb(self, msg: Twist):
        self.lin_x = msg.linear.x
        self.ang_z = msg.angular.z
        self.send_velocity()

    def send_velocity(self):
        # A = 1 si hay movimiento
        a = 1 if (self.lin_x != 0.0 or self.ang_z != 0.0) else 0
        # Convertir a enteros (mm/s, mrad/s)
        v_int = int(round(self.lin_x * 1000))
        w_int = int(round(self.ang_z * 1000))
        trama = f"{a}#{v_int}#{w_int}#0#0#0\r\n"

        self._send_line(trama)
        self.get_logger().info(f"Enviado: {trama.strip()}")

    def rack_cb(self, msg: Int8):
        pos = max(0.0, min(1.0, float(msg.data)))
        self._send_line(f"R{pos:.2f}\r\n")

    def gripper_cb(self, msg: Bool):
        val = 1 if msg.data else 0
        self._send_line(f"G{val}\r\n")

    def flags_cb(self, msg: UInt8):
        if msg.data & 0x01:
            self._send_line("E\r\n")

    def destroy_node(self):
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