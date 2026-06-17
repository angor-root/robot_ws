#!/usr/bin/env python3
"""
Teleoperador por teclado para robot diferencial.
Publica en /cmd_vel. Teclas: w/s (avance/retroceso), a/d (giro), espacio (parar).
"""

import sys
import termios
import tty
import select
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class TeleopKeyboard(Node):
    def __init__(self):
        super().__init__('teleop_keyboard')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.twist = Twist()

        # Parámetros de velocidad
        self.linear_speed = 0.15   # m/s
        self.angular_speed = 0.5   # rad/s

        self.get_logger().info("Teleoperador iniciado. Usa w/s/a/d, espacio para parar, q para salir.")

    def get_key(self):
        """Lee una tecla sin bloqueo."""
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            dr, _, _ = select.select([sys.stdin], [], [], 0.1)
            if dr:
                return sys.stdin.read(1)
            return None
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

    def spin(self):
        """Bucle principal: lee teclas y publica comandos."""
        try:
            while rclpy.ok():
                key = self.get_key()
                if key:
                    if key == 'w':
                        self.twist.linear.x = self.linear_speed
                        self.twist.angular.z = 0.0
                    elif key == 's':
                        self.twist.linear.x = -self.linear_speed
                        self.twist.angular.z = 0.0
                    elif key == 'a':
                        self.twist.linear.x = 0.0
                        self.twist.angular.z = self.angular_speed
                    elif key == 'd':
                        self.twist.linear.x = 0.0
                        self.twist.angular.z = -self.angular_speed
                    elif key == ' ':
                        self.twist.linear.x = 0.0
                        self.twist.angular.z = 0.0
                    elif key == 'q':
                        self.get_logger().info("Saliendo del teleoperador.")
                        break
                    else:
                        continue

                    self.pub.publish(self.twist)
                    self.get_logger().info(f"Enviado: lin={self.twist.linear.x:.2f}, ang={self.twist.angular.z:.2f}")

                # Pequeña pausa para no saturar el CPU
                rclpy.spin_once(self, timeout_sec=0.01)

        except KeyboardInterrupt:
            pass
        finally:
            # Parar el robot al salir
            self.twist.linear.x = 0.0
            self.twist.angular.z = 0.0
            self.pub.publish(self.twist)

def main(args=None):
    rclpy.init(args=args)
    node = TeleopKeyboard()
    node.spin()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()