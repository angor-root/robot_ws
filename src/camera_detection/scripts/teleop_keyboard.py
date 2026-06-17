#!/usr/bin/env python3
"""
Teleoperador incremental para robot diferencial.
Controles:
  w/s : aumentar/disminuir velocidad lineal
  e/d : aumentar/disminuir velocidad angular
  i   : avanzar con la velocidad actual
  k   : retroceder con la velocidad actual
  j   : girar izquierda con la velocidad angular actual
  l   : girar derecha con la velocidad angular actual
  espacio : parar
  q   : salir
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

        # Velocidades actuales (en unidades del robot: m/s, rad/s)
        self.linear = 0.0
        self.angular = 0.0

        # Incrementos
        self.linear_step = 0.05   # 5 cm/s por pulsación
        self.angular_step = 0.1   # ~5.7°/s por pulsación

        # Límites
        self.max_linear = 0.3
        self.max_angular = 1.0

        self.print_help()

    def print_help(self):
        msg = """
Teleoperador incremental.
  Lineal:  w (+) / s (-)  (actual: {lin:.2f} m/s)
  Angular: e (+) / d (-)  (actual: {ang:.2f} rad/s)
  Movimiento: i (avanzar), k (retroceder), j (izq), l (der)
  Espacio: parar
  q: salir
        """.format(lin=self.linear, ang=self.angular)
        self.get_logger().info(msg)

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

    def spin(self):
        try:
            while rclpy.ok():
                key = self.get_key()
                if not key:
                    rclpy.spin_once(self, timeout_sec=0.05)
                    continue

                if key == 'w':
                    self.linear = min(self.linear + self.linear_step, self.max_linear)
                elif key == 's':
                    self.linear = max(self.linear - self.linear_step, 0.0)
                elif key == 'e':
                    self.angular = min(self.angular + self.angular_step, self.max_angular)
                elif key == 'd':
                    self.angular = max(self.angular - self.angular_step, 0.0)
                elif key == 'i':
                    self.publish_twist(self.linear, 0.0)
                elif key == 'k':
                    self.publish_twist(-self.linear, 0.0)
                elif key == 'j':
                    self.publish_twist(0.0, self.angular)
                elif key == 'l':
                    self.publish_twist(0.0, -self.angular)
                elif key == ' ':
                    self.publish_twist(0.0, 0.0)
                elif key == 'q':
                    self.get_logger().info("Saliendo...")
                    break
                else:
                    pass

                # Mostrar estado actual
                if key in ('w', 's', 'e', 'd'):
                    self.get_logger().info(
                        f"Velocidades: lineal={self.linear:.2f}, angular={self.angular:.2f}"
                    )

        except KeyboardInterrupt:
            pass
        finally:
            # Detener al salir
            self.publish_twist(0.0, 0.0)

    def publish_twist(self, linear, angular):
        twist = Twist()
        twist.linear.x = linear
        twist.angular.z = angular
        self.pub.publish(twist)
        self.get_logger().info(f"Enviado: lin={linear:.2f}, ang={angular:.2f}")

def main(args=None):
    rclpy.init(args=args)
    node = IncrementalTeleop()
    node.spin()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()