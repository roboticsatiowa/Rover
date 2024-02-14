import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial
from time import sleep

class InterfaceNode(Node):
    prev_msg = None
    control_mode = 0

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
    
    def drive_mode(self, msg):
        pass
    
    def arm_mode(self, msg):
        try:
            self.serial_out.write(b'h 0 ' + bytes(str(msg.axes[1] * 255), 'utf-8') + b'\r')
            self.serial_out.write(b'h 1 ' + bytes(str(msg.axes[4] * 255), 'utf-8') + b'\r')
            self.serial_out.write(b'o 0 ' + bytes(str(msg.axes[0] * 255), 'utf-8') + b'\r')
            self.serial_out.write(b'o 1 ' + bytes(str(msg.axes[3] * 255), 'utf-8') + b'\r')
        except Exception as e:
            self.get_logger().error(f"Error writing to serial port: {e}")

    def sensor_mode(self, msg):
        pass
        

        
    def joystick_callback(self, msg):

        if self.prev_msg == None:
            self.prev_msg = msg
            return

        if self.control_mode == 0:
            self.drive_mode(msg)
        elif self.control_mode == 1:
            self.arm_mode(msg)
        elif self.control_mode == 2:
            self.sensor_mode(msg)
        
        # Mode toggle
        if self.prev_msg.buttons[7] == 0 and msg.buttons[7] == 1:
            self.control_mode = (self.control_mode + 1) % 3
            self.get_logger().info(f"Switching to control mode {self.control_mode}")

        if self.prev_msg.buttons[6] == 0 and msg.buttons[6] == 1:
            self.serial_out.write(b'z\r')
            self.get_logger().info("Toggling headlights")

        self.prev_msg = msg

        self.serial_out.flush()





def main(args=None):
    rclpy.init(args=args)
    #TODO send startup message to teensy
    node = InterfaceNode()
    rclpy.spin(node)
    #TODO send shutdown message to teensy
    rclpy.shutdown()
if __name__ == '__main__':
    main()
