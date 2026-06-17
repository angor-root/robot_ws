#!/usr/bin/env python3
"""
Nodo puente UART SOLO ENVÍO hacia myRIO.
Sin recepción, sin heartbeat, sin timeout.
Protocolo: 8E2, 9600 baudios.
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

        self.declare_parameter('port', '/dev/ttyAMA1')
        self.declare_parameter('baudrate', 9600)

        port = self.get_parameter('port').value
        baud = self.get_parameter('baudrate').value

        # Abrir puerto serie solo para escritura
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

        # Suscriptores (solo entrada)
        self.sub_cmd_vel  = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_cb, 10)
        self.sub_rack     = self.create_subscription(Int8, '/rack_cmd', self.rack_cb, 10)
        self.sub_gripper  = self.create_subscription(Bool, '/gripper_cmd', self.gripper_cb, 10)
        self.sub_flags    = self.create_subscription(UInt8, '/robot_flags', self.flags_cb, 10)

        self.get_logger().info("UART Bridge (solo envío) iniciado.")

    # ------------------------------------------------------------------
    # Envío de comandos (thread-safe)
    # ------------------------------------------------------------------
    def _send_line(self, line: str):
        with threading.Lock():
            try:
                self.ser.write((line + '\n').encode('ascii'))
                self.ser.flush()
            except serial.SerialException:
                self.get_logger().error("Error al escribir en UART")

    def cmd_vel_cb(self, msg: Twist):
        lin_x = msg.linear.x
        lin_y = msg.linear.y
        ang_z = msg.angular.z
        self._send_line(f"a{lin_x:.2f}b{lin_y:.2f}c{ang_z:.2f}d")

    def rack_cb(self, msg: Int8):
        pos = max(0.0, min(1.0, float(msg.data)))
        self._send_line(f"R{pos:.2f}")

    def gripper_cb(self, msg: Bool):
        val = 1 if msg.data else 0
        self._send_line(f"G{val}")

    def flags_cb(self, msg: UInt8):
        if msg.data & 0x01:
            self._send_line("E")

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