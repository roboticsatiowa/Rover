from re import T
from socket import timeout
from time import sleep
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy, BatteryState
import serial
import rclpy.qos

from button_maps.PS5 import *

device_path = "/dev/ttyTEENSY"

class InterfaceNode(Node):
    prev_msg = None
    prev_msg_time = None
    control_mode = 0

    def button_pressed(self, msg, button):
        return self.prev_msg.buttons[button] == 0 and msg.buttons[button] == 1
    
    def button_released(self, msg, button):
        return self.prev_msg.buttons[button] == 1 and msg.buttons[button] == 0
    
    def axis_changed(self, msg, axis):
        return self.prev_msg.axes[axis] != msg.axes[axis]

    def __init__(self):

        super(InterfaceNode, self).__init__('uirover_hardware')

        self.declare_parameter('timeout', 1)

        self.timeout = self.get_parameter("timeout").get_parameter_value().integer_value

        try:
            self.serial_out = serial.Serial(device_path, 115200, timeout=1)
            self.get_logger().info(f"Successfully opened serial port {device_path}")
        except Exception as e:
            self.get_logger().error(f"{e}\nFailed to open serial port {device_path}. Retrying...")
            raise e
        
        if self.serial_out is None:
            self.get_logger().error("Failed to open serial port. Exiting...")
            rclpy.shutdown()


        self.control_mode = 0

        self.joystick_subscription = self.create_subscription(
            Joy,
            'joy',
            self.joystick_callback,
            10)
    
        self.battery_publisher = self.create_publisher(
            BatteryState,
            '/battery_state',
            10)
        
        self.create_timer(1, self.clock_1hz)
        self.create_timer(0.1, self.heartbeat_check)

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

    # X o 0: Base Motor
    # X o 1: hand inclination
    # o 2: hand
    # o 3: hand rotation
    # h 0: elbow
    # h 1: shoulder
    def arm_mode(self, msg):
        try:
            # we must only send the command if the value has changed. Otherwise the serial connection will be become bogged down
            if self.axis_changed(msg, R_JOY_Y):
                self.serial_out.write(bytes(f'o 1 {msg.axes[R_JOY_Y] * -255}\r', 'utf-8'))
            if self.axis_changed(msg, L_JOY_X):
                self.serial_out.write(bytes(f'o 3 {msg.axes[L_JOY_X] * -255}\r', 'utf-8'))
            
            if not (msg.axes[L_TRIGGER] != 1 and msg.axes[R_TRIGGER] != 1):
                if self.axis_changed(msg, R_TRIGGER):
                    self.serial_out.write(bytes(f'o 0 {((msg.axes[R_TRIGGER]-1)/2) * -255}\r', 'utf-8'))
                if self.axis_changed(msg, L_TRIGGER):
                    self.serial_out.write(bytes(f'o 0 {((msg.axes[L_TRIGGER]-1)/2) * 255}\r', 'utf-8'))

            if not (msg.buttons[CIRCLE_BUTTON] != 0 and msg.buttons[SQUARE_BUTTON] != 0):
                if self.button_pressed(msg, CIRCLE_BUTTON):
                    self.serial_out.write(b'o 2 255\r')
                if self.button_pressed(msg, SQUARE_BUTTON):
                    self.serial_out.write(b'o 2 -255\r')

            if self.button_released(msg, CIRCLE_BUTTON):
                self.serial_out.write(b'o 2 0\r')
            if self.button_released(msg, SQUARE_BUTTON):
                self.serial_out.write(b'o 2 0\r')

            if not (msg.buttons[TRIANGLE_BUTTON] != 0 and msg.buttons[X_BUTTON] != 0):
                if self.button_pressed(msg, TRIANGLE_BUTTON):
                    self.serial_out.write(b'h 1 255\r')
                if self.button_pressed(msg, X_BUTTON):
                    self.serial_out.write(b'h 1 -255\r')
            
            if self.button_released(msg, TRIANGLE_BUTTON):
                self.serial_out.write(b'h 1 0\r')
            if self.button_released(msg, X_BUTTON):
                self.serial_out.write(b'h 1 0\r')

            if not (msg.buttons[DPAD_UP] != 0 and msg.buttons[DPAD_DOWN] != 0):
                if self.button_pressed(msg, DPAD_UP):
                    self.serial_out.write(b'h 0 -255\r')
                if self.button_pressed(msg, DPAD_DOWN):
                    self.serial_out.write(b'h 0 255\r')
            
            if self.button_released(msg, DPAD_UP):
                self.serial_out.write(b'h 0 0\r')
            if self.button_released(msg, DPAD_DOWN):
                self.serial_out.write(b'h 0 0\r')            
        except Exception as e:
            self.get_logger().error(f"Error writing to serial port: {e}")

        
    def joystick_callback(self, msg):
        self.prev_msg_time = self.get_clock().now()

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
            self.serial_out.close()
            rclpy.shutdown()

    def clock_1hz(self):
        self.serial_out.read_all()
        self.serial_out.write(b'g\r')
        sleep(0.1)
        response = self.serial_out.read_all()
        try:
            response = float(response)
        except Exception:
            self.get_logger().error("Recieved illegal battery voltage: %s" % str(response))
            return

        battery_state_msg = BatteryState(
            voltage=response,
            power_supply_technology=3
        )

        self.battery_publisher.publish(battery_state_msg)
    
    def heartbeat_check(self):
        if self.prev_msg_time is None:
            return
        
        if self.get_clock().now().to_msg().sec - self.prev_msg_time.to_msg().sec > self.timeout:
            self.serial_out.write(b'd\r')
            self.prev_msg_time = None



def main(args=None):
    rclpy.init(args=args)
    #TODO send startup message to teensy
    node = InterfaceNode()
    rclpy.spin(node)
    #TODO send shutdown message to teensy
    rclpy.shutdown()

    
if __name__ == '__main__':
    main()
