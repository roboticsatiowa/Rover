import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class ImageCompressor(Node):
    def __init__(self):
        super().__init__('image_decompressor')
        self.subscription = self.create_subscription(
            Image,
            '/narrow_stereo/image_raw',  # Topic to subscribe to
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.publisher = self.create_publisher(
            Image,
            '/camera2/recompressed', )  # New topic for decompressed images
            

   

def main(args=None):
    rclpy.init(args=args)
    image_compressor = ImageCompressor()
    rclpy.spin(image_compressor)
    image_compressor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
