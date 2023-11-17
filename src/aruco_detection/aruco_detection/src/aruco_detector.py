import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class ArucoDetectionNode(Node):
    def __init__(self):
        super().__init__('aruco_detector')
        self.bridge = CvBridge()  # Initialize the CvBridge

        # Subscription to Camera 1
        self.subscription_camera1 = self.create_subscription(
            Image,
            '/camera1/image_raw',
            self.image_callback_camera1,
            10)

        # Subscription to Camera 2
        self.subscription_camera2 = self.create_subscription(
            Image,
            '/camera2/image_raw',
            self.image_callback_camera2,
            10)

    def image_callback_camera1(self, msg):
        # Convert the ROS Image message to an OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        # Process the image from Camera 1
        # ...

    def image_callback_camera2(self, msg):
        # Convert the ROS Image message to an OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        # Process the image from Camera 2
        # ...

    def aruco_detection(self, img):
        cv2.ArucoDetector.detectMarkers(img)
        pass

def main(args=None):
    rclpy.init(args=args)
    aruco_detector = ArucoDetectionNode()
    rclpy.spin(aruco_detector)
    rclpy.shutdown()

if __name__ == '__main__':
    main()