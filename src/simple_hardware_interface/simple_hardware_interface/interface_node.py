import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial
from time import sleep

from button_maps.PS5 import *

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

        i = 0
        while true:
            try:
                self.serial_out = serial.Serial(f"/dev/ttyACM{i%5}", 115200, timeout=1)
                break
            except Exception as e:
                self.get_logger().error(f"{e}\nFailed to open serial port {PORT_NAME}. Retrying...")
                sleep(5)


        self.control_mode = 0

        self.joystick_subscription = self.create_subscription(
            Joy,
            'joy',
            self.joystick_callback,
            10)
    
    # Move wheels
    def drive_mode(self, msg):
        try:
            if self.axis_changed(msg, L_JOY_Y):
                self.serial_out.write(bytes(f'l 0 {msg.axes[L_JOY_Y] * -255}\r', 'utf-8'))
            if self.axis_changed(msg, R_JOY_Y):
                self.serial_out.write(bytes(f'l 1 {msg.axes[R_JOY_Y] * -255}\r', 'utf-8'))
        except Exception as e:
            self.get_logger().error(f"Error writing to serial port: {e}")
            
    # Move arm and other actuators
    def arm_mode(self, msg):
        try:
            # we must only send the command if the value has changed. Otherwise the serial connection will be become bogged down
            if self.axis_changed(msg, L_JOY_Y):
                self.serial_out.write(bytes(f'h 0 {msg.axes[L_JOY_Y] * 255}\r', 'utf-8'))
            if self.axis_changed(msg, R_JOY_Y):
                self.serial_out.write(bytes(f'h 1 {msg.axes[R_JOY_Y] * 255}\r', 'utf-8'))
            if self.axis_changed(msg, L_JOY_X):
                self.serial_out.write(bytes(f'o 0 {msg.axes[L_JOY_X] * 255}\r', 'utf-8'))
            if self.axis_changed(msg, R_JOY_X):
                self.serial_out.write(bytes(f'o 2 {msg.axes[R_JOY_X] * 255}\r', 'utf-8'))
        except Exception as e:
            self.get_logger().error(f"Error writing to serial port: {e}")

        
    def joystick_callback(self, msg):

        # First iteration protection
        if self.prev_msg is None:
            self.prev_msg = msg
            return
        
        # Control mode
        if self.control_mode == 0:
            self.drive_mode(msg)
        elif self.control_mode == 1:
            self.arm_mode(msg)
        
        # Mode toggle
        if self.button_pressed(msg, OPTIONS_BUTTON):
            self.control_mode = (self.control_mode + 1) % 2
            self.get_logger().info(f"Switching to control mode {self.control_mode}")

        # Headlight toggle
        if self.button_pressed(msg, CREATE_BUTTON):
            self.serial_out.write(b'z\r')
            self.get_logger().info("Toggling headlights")


        self.prev_msg = msg

        try:
            self.serial_out.flush()
        except Exception as e:
            self.get_logger().error(f"Error flushing serial port: {e}")
            if not self.serial_out.is_open:
                self.get_logger().error("Serial port closed. Exiting node.")
                rclpy.shutdown()
            sleep(1)




def main(args=None):
    rclpy.init(args=args)
    #TODO send startup message to teensy
    node = InterfaceNode()
    rclpy.spin(node)
    #TODO send shutdown message to teensy
    rclpy.shutdown()

    
if __name__ == '__main__':
    main()
