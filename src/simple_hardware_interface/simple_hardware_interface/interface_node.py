import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial
from time import sleep

class InterfaceNode(Node):
    def __init__(self):
        super(InterfaceNode, self).__init__('simple_hardware_interface')

        #NOTE port name may need to be changed

        PORT_NAME = '/dev/ttyACM0'
        
        attempts_remaining = 5
        while attempts_remaining > 0:
            attempts_remaining -= 1
            try:
                self.serial_out = serial.Serial(PORT_NAME, 9600, timeout=1)
                break
            except:
                self.get_logger().warn(f"Failed to open serial port {PORT_NAME}. Retrying...")
                sleep(5)

        if attempts_remaining == 0:
            self.get_logger().error("Maximum attempts reached. Exiting node")
            self.destroy_node()


        self.control_mode = 0

        self.joystick_subscription = self.create_subscription(
            Joy,
            'joy',
            self.joystick_callback,
            10)
    
        

        
    def joystick_callback(self, msg):
        
        axes = msg.axes
        buttons = msg.buttons
    
        self.serial_out.write(b'h 0 ' + bytes(str(axes[1] * 255), 'utf-8') + b'\r')
        self.serial_out.write(b'h 1 ' + bytes(str(axes[4] * 255), 'utf-8') + b'\r')
        





def main(args=None):
    rclpy.init(args=args)
    #TODO send startup message to teensy
    node = InterfaceNode()
    rclpy.spin(node)
    #TODO send shutdown message to teensy
    rclpy.shutdown()
if __name__ == '__main__':
    main()
