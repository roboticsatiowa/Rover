import rclpy
from rclpy.node import Node
import can
from random import randint
from time import sleep

ADDRESS_CMD = 0x06
REBOOT_CMD = 0x16
CLEAR_ERRORS_CMD = 0x18

BROADCAST_NODE_ID = 0x3f
MAX_NODE_ID = 0x3e

DISCOVERY_MESSAGE_INTERVAL = 0.6
TIMEOUT = 3.0

REBOOT_ACTION_REBOOT = 0
REBOOT_ACTION_SAVE = 1
REBOOT_ACTION_ERASE = 2

class Odrive():
    def __init__(self, serial_num, name):
        self.serial_num = serial_num
        self.name = name
        
        self.id = randint(0, 64) # 6 bit node id
        self.is_addressed = False
    
    def send(self, bus, cmd, data):
        msg = can.Message(
            arbitration_id=(self.id << 5) | cmd,
            data=data,
            is_extended_id=False
        )
        bus.send(msg)

    def recv(self, bus, msg):
        if not self.is_addressed and msg.arbitration_id == 0x7E6 and msg.is_remote_frame:
            self.send(bus, 0x06, self.serial_num.to_bytes(7))
            self.is_addressed = True
            return
        
        


    

class MockOdriveNetwork(Node):
    def __init__(self):
        super().__init__('minimal_publisher')

        self.bus = can.interface.Bus(interface="socketcan", channel="vcan0")

        self.odrives = []
        for i in range (6):
            self.odrives.append(Odrive(0xC0FFEE00 + i, "j{i}"))
        
        self.update_loop()
    
    def update_loop(self):
        while True:
            msg = self.bus.recv()
            if not msg:
                continue

            for od in self.odrives:
                od.recv(self.bus, msg)
        


def main(args=None):
    rclpy.init(args=args)
    minimal_publisher = MockOdriveNetwork()
    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()