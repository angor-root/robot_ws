#!/usr/bin/env python3
"""
Teleoperador incremental con envío automático.
Controles:
  w : aumentar velocidad lineal → AVANZA inmediatamente
  s : disminuir velocidad lineal → retrocede si se vuelve negativa
  a : aumentar velocidad angular (giro izquierda)
  d : disminuir velocidad angular (giro derecha)
  espacio : parar (pone velocidad a 0)
  q : salir
Cada pulsación ajusta la velocidad y publica el comando.
"""

import sys
import termios
import tty
import select
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class IncrementalTeleop(Node):
    def __init__(self):
        super().__init__('incremental_teleop')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)

        self.linear  = 0.0
        self.angular = 0.0

        self.linear_step  = 0.05   # m/s
        self.angular_step = 0.1    # rad/s

        self.max_linear  = 0.3
        self.max_angular = 1.0

        self.get_logger().info(
            "Teleoperador incremental activo.\n"
            "  w/s: subir/bajar velocidad lineal (avance/retroceso)\n"
            "  a/d: subir/bajar velocidad angular (giro izq/der)\n"
            "  espacio: parar\n"
            "  q: salir\n"
            "Cada pulsación publica el comando."
        )

    def get_key(self):
        fd = sys.stdin.fileno()
        old = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            dr, _, _ = select.select([sys.stdin], [], [], 0.1)
            if dr:
                return sys.stdin.read(1)
            return None
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old)

    def publish_current(self):
        twist = Twist()
        twist.linear.x  = self.linear
        twist.angular.z = self.angular
        self.pub.publish(twist)
        self.get_logger().info(
            f"Enviado: lin={self.linear:+.2f} m/s, ang={self.angular:+.2f} rad/s"
        )

    def spin(self):
        try:
            while rclpy.ok():
                key = self.get_key()
                if not key:
                    rclpy.spin_once(self, timeout_sec=0.05)
                    continue

                if key == 'w':
                    self.linear = min(self.linear + self.linear_step, self.max_linear)
                    self.publish_current()
                elif key == 's':
                    self.linear = max(self.linear - self.linear_step, -self.max_linear)
                    self.publish_current()
                elif key == 'a':
                    self.angular = min(self.angular + self.angular_step, self.max_angular)
                    self.publish_current()
                elif key == 'd':
                    self.angular = max(self.angular - self.angular_step, -self.max_angular)
                    self.publish_current()
                elif key == ' ':
                    self.linear  = 0.0
                    self.angular = 0.0
                    self.publish_current()
                elif key == 'q':
                    self.get_logger().info("Saliendo...")
                    break

        except KeyboardInterrupt:
            pass
        finally:
            # Parada segura al salir
            twist = Twist()
            self.pub.publish(twist)
            self.get_logger().info("Robot detenido.")

def main(args=None):
    rclpy.init(args=args)
    node = IncrementalTeleop()
    node.spin()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()