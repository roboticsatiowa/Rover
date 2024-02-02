import rclpy
from rclpy.node import Node

class InterfaceNode(Node):
    def __init__(self):
        super().__init__('simple_hardware_interface')

        self.joystick_subscription = self.create_subscription(
            Joy,
            'joy',
            self.joystick_callback,
            10)
        
    def joystick_callback(self, msg):
        rclpy.loginfo('Joystick message received: ' + msg)
    


def main(args=None):
    rclpy.init(args=args)
    node = Node()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
