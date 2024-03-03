import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class ImageDecompressor(Node):
    def __init__(self):
        super().__init__('image_decompressor')
        self.subscription = self.create_subscription(
            Image,
            '/camera2/image_raw',  # Topic to subscribe to
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.publisher = self.create_publisher(
            Image,
            '/camera2/image_decompressed',  # New topic for decompressed images
            10)
        self.bridge = CvBridge()

    def listener_callback(self, msg):
        # Convert ROS Image message to OpenCV format
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        # Your decompression and conversion code here
        # For example, if the image is in MJPEG format, you would decode it using OpenCV
        # decompressed_image = cv2.imdecode(cv_image, cv2.IMREAD_COLOR)

        # Publish the decompressed image
        decompressed_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding='bgr8')
        decompressed_msg.header = msg.header  # Copy header to maintain timestamp and frame_id
        self.publisher.publish(decompressed_msg)

def main(args=None):
    rclpy.init(args=args)
    image_decompressor = ImageDecompressor()
    rclpy.spin(image_decompressor)
    image_decompressor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
