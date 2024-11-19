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

        # Publishers for processed images
        self.publisher_camera1 = self.create_publisher(Image, '/camera1/processed_image', 10)
        self.publisher_camera2 = self.create_publisher(Image, '/camera2/processed_image', 10)

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
        self.aruco_dict = aruco.Dictionary_get(aruco.DICT_4X4_100)
        self.aruco_params = aruco.DetectorParameters_create()

    def image_callback_camera1(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        processed_image = self.uirover_aruco(cv_image, "Camera 1")
        # Publish processed image
        self.publisher_camera1.publish(self.bridge.cv2_to_imgmsg(processed_image, "bgr8"))

    def image_callback_camera2(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        processed_image = self.uirover_aruco(cv_image, "Camera 2")
        # Publish processed image
        self.publisher_camera2.publish(self.bridge.cv2_to_imgmsg(processed_image, "bgr8"))

    def uirover_aruco(self, img, camera_name):
        # Convert to grayscale
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # Detect ArUco markers
        corners, ids, rejectedImgPoints = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.aruco_params)

        # Draw detected markers
        aruco.drawDetectedMarkers(img, corners, ids)

        # Here you can add more processing, like estimating pose, etc.
        if ids is not None:
            fontFace = cv2.FONT_HERSHEY_SIMPLEX
            fontScale = 1.5  # Increase font size as needed
            thickness = 3  # Adjust thickness as needed
            for i in range(len(ids)):
                c = corners[i][0]
                center = tuple(c.mean(axis=0).astype(int))
                cv2.putText(img, str(ids[i][0]), center, fontFace, fontScale, (0, 255, 0), thickness)
                print(f"Detected ArUco marker ID: {ids[i][0]} on {camera_name}")

        # Return the processed image with markers drawn
        return img

def main(args=None):
    rclpy.init(args=args)
    aruco_detector = ArucoDetectionNode()
    rclpy.spin(aruco_detector)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
