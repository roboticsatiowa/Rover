#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("test_node")
        self.get_logger().info("Testing, Testing, 1 2 3")


def main(args=None):
    rclpy.init(args=args)
    node = MyNode() #creates the node
    rclpy.spin(node)
    rclpy.shutdown


#to call the excutable
if __name__ == '__main__':
    main()