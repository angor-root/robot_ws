#!/usr/bin/env python3
"""Publica frames MJPEG directamente desde la cámara como CompressedImage."""

import cv2
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import numpy as np

class MjpegCamera(Node):
    def __init__(self):
        super().__init__('mjpeg_camera')
        self.pub = self.create_publisher(CompressedImage, '/image_raw/compressed', 10)
        self.cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.cap.set(cv2.CAP_PROP_FPS, 30)
        self.timer = self.create_timer(0.033, self.timer_callback)  # ~30 Hz
        self.get_logger().info("MJPEG camera node started")

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warn("Failed to grab frame")
            return
        # Comprimir a JPEG (la cámara ya entrega MJPEG, pero OpenCV lo decodifica a BGR)
        # Volvemos a codificar a JPEG para publicar CompressedImage
        _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 85])
        msg = CompressedImage()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.format = "jpeg"
        msg.data = buffer.tobytes()
        self.pub.publish(msg)

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = MjpegCamera()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()