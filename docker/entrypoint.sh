#!/bin/bash

source /opt/ros/humble/setup.bash
source /home/robotics/Rover/install/setup.bash

ros2 launch rover_launch launch_all.launch.py

exec "$@"
