import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import cv2.aruco as aruco

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

        # Define the ArUco dictionary
        self.aruco_dict = aruco.Dictionary_get(aruco.DICT_4x4_100)
        # CHANGE FOR COMPETITION IF DIFFERENT DICTIONARY IS USED
        self.aruco_params = aruco.DetectorParameters_create()

    def image_callback_camera1(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        self.aruco_detection(cv_image, "Camera 1")

    def image_callback_camera2(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        self.aruco_detection(cv_image, "Camera 2")

    def aruco_detection(self, img, camera_name):
        # Convert to grayscale
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # Detect ArUco markers
        corners, ids, rejectedImgPoints = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.aruco_params)

        # Draw detected markers
        aruco.drawDetectedMarkers(img, corners, ids)

        # Here you can add more processing, like estimating pose, etc.
        
        # For now, let's just print the IDs
        if ids is not None:
            for i in range(len(ids)):
                print(f"Detected ArUco marker ID: {ids[i][0]} on {camera_name}")

        # You might want to visualize the result; you can use cv2.imshow here or publish the processed image to a new ROS topic

def main(args=None):
    rclpy.init(args=args)
    aruco_detector = ArucoDetectionNode()
    rclpy.spin(aruco_detector)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
