from sympy import E
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial
from time import sleep

class InterfaceNode(Node):
    prev_msg = None
    control_mode = 0

    def button_pressed(self, msg, button):
        return self.prev_msg.buttons[button] == 0 and msg.buttons[button] == 1
    
    def button_released(self, msg, button):
        return self.prev_msg.buttons[button] == 1 and msg.buttons[button] == 0
    
    def axis_changed(self, msg, axis):
        return self.prev_msg.axes[axis] != msg.axes[axis]

    def __init__(self):

        super(InterfaceNode, self).__init__('simple_hardware_interface')

        PORT_NAME = '/dev/ttyACM0'
        
        while True:
            try:
                self.serial_out = serial.Serial(PORT_NAME, 115200, timeout=1)
                break
            except Exception as e:
                self.get_logger().error(f"{e}\nFailed to open serial port {PORT_NAME}. Retrying...")
                sleep(10)


        self.control_mode = 0

        self.joystick_subscription = self.create_subscription(
            Joy,
            'joy',
            self.joystick_callback,
            10)
    
    # Move wheels
    def drive_mode(self, msg):
        pass
    
    # Move arm and other actuators
    def arm_mode(self, msg):
        try:
            if self.axis_changed(msg, 1):
                self.serial_out.write(bytes(f'h 0 {msg.axes[1] * 255}\r', 'utf-8'))
            if self.axis_changed(msg, 4):
                self.serial_out.write(bytes(f'h 1 {msg.axes[3] * 255}\r', 'utf-8'))
            if self.axis_changed(msg, 0):
                self.serial_out.write(bytes(f'o 0 {msg.axes[0] * 255}\r', 'utf-8'))
            if self.axis_changed(msg, 3):
                self.serial_out.write(bytes(f'o 2 {msg.axes[2] * 255}\r', 'utf-8'))
        except Exception as e:
            self.get_logger().error(f"Error writing to serial port: {e}")

    # Move cameras and other sensors
    def sensor_mode(self, msg):
        pass
        

        
    def joystick_callback(self, msg):

        if self.prev_msg is None:
            self.prev_msg = msg
            return

        if self.control_mode == 0:
            self.drive_mode(msg)
        elif self.control_mode == 1:
            self.arm_mode(msg)

        # currently unreachable. may be implemented later
        elif self.control_mode == 2:
            self.sensor_mode(msg)
        
        # Mode toggle
        if self.button_pressed(msg, 9):
            self.control_mode = (self.control_mode + 1) % 2
            self.get_logger().info(f"Switching to control mode {self.control_mode}")

        # Headlight toggle
        if self.button_pressed(msg, 8):
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
