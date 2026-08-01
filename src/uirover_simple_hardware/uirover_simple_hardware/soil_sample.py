from re import T
from socket import timeout
from time import sleep
import struct
import can
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy, BatteryState
import serial
import rclpy.qos

class SoilNode(Node):
    """
    ROS 2 driver skeleton for the USB 8-in-1 soil tester.

    Measurements expected from the tester:
        - Nitrogen
        - Phosphorus
        - Potassium
        - Moisture
        - Temperature
        - Conductivity
        - pH
        - Fertility

    The tester's packet format must still be identified before these
    values can be decoded.
    """

    def __init__(self):
        # Initialize the node
        super(SoilNode, self).__init__('uirover_simple_hardware')

        self.declare_parameter('timeout', 1)

        self.timeout = self.get_parameter("timeout").get_parameter_value().integer_value

        self.get_logger().info('Hello, ROS 2! My node has started.')


def heartbeat_check(self):
        if self.prev_msg_time is None:
            return
        
        if self.get_clock().now().to_msg().sec - self.prev_msg_time.to_msg().sec > self.timeout:
            self.serial_out.write(b'd\r')
            self.set_base_velocity(0.0)
            self.prev_msg_time = None


def main(args=None):
    # Initialize the rclpy communications
    rclpy.init(args=args)
    
    # Create the node instance
    node = SoilNode()
    
    # Pause the program thread to keep the node alive and listening
    rclpy.spin(node)
    
    # Explicitly destroy the node and clean up communications
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()
