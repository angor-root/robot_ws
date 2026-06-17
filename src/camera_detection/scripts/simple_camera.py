#!/usr/bin/env python3
"""Publica imágenes a 10 Hz desde la cámara, baja resolución."""

import cv2
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class SimpleCamera(Node):
    def __init__(self):
        super().__init__('simple_camera')
        self.pub = self.create_publisher(Image, '/image_raw', 10)
        self.bridge = CvBridge()
        self.cap = cv2.VideoCapture(0, cv2.CAP_V4L2)   # /dev/video0
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)
        self.cap.set(cv2.CAP_PROP_FPS, 10)
        # Publicar ~10 veces por segundo (0.1 s)
        self.timer = self.create_timer(0.1, self.callback)
        self.get_logger().info("Cámara simple (10 Hz, 320x240) iniciada")

    def callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warn("No se pudo capturar frame")
            return
        # Redimensionar para asegurar 320x240
        frame = cv2.resize(frame, (320, 240))
        msg = self.bridge.cv2_to_imgmsg(frame, 'bgr8')
        msg.header.frame_id = "camera_link"   # evita warnings de frame ''
        self.pub.publish(msg)

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = SimpleCamera()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()