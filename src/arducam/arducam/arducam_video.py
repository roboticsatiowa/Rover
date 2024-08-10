from sympy import det
import rclpy
from rclpy.node import Node
import rclpy.qos
from sensor_msgs.msg import CompressedImage  # noqa: F811
import cv2
from cv_bridge import CvBridge


class ArducamVideoPublisher(Node):
    framerate = 10  # frames per second

    def __init__(self):
        super().__init__("arducam_video_capture")

        self.declare_parameter('cam_index', 0)

        cam_index = self.get_parameter("cam_index").get_parameter_value().integer_value

        # qos sensor data uses best effort delivery, which is best for video
        self.publisher_ = self.create_publisher(
            CompressedImage, f"video_cam_{cam_index}", qos_profile=rclpy.qos.qos_profile_sensor_data
        )
        timer_period = 30 # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.bridge = CvBridge()

        # cv2 videocapture setup
        # Note: 1920x1080 @ 30fps with MJPEG compression is explicitly supported
        # by our hardware and may not work with other cameras
        self.vid = cv2.VideoCapture(cam_index, cv2.CAP_V4L2)
        self.vid.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc("M", "J", "P", "G"))
        self.vid.set(cv2.CAP_PROP_FRAME_WIDTH, 480)
        self.vid.set(cv2.CAP_PROP_FRAME_HEIGHT, 320)
        self.vid.set(cv2.CAP_PROP_FPS, self.framerate)

        # Aruco detection setup
        dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_6X6_1000)
        parameters = cv2.aruco.DetectorParameters()
        self.detector = cv2.aruco.ArucoDetector(dictionary, parameters)

        # misc
        self.missed_frames = 0

    def timer_callback(self):
        ret, frame = self.vid.read()
        if self.missed_frames > 50:
            raise IOError("Connection to camera timed out")

        if not ret:
            self.missed_frames += 1
            return

        corners, ids, rejectedImgPoints = self.detector.detectMarkers(frame)
        frame = cv2.aruco.drawDetectedMarkers(frame, corners, ids)

        self.publisher_.publish(self.bridge.cv2_to_compressed_imgmsg(frame))
        self.missed_frames = 0


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = ArducamVideoPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
