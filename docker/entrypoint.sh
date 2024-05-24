#!/bin/bash

source /opt/ros/humble/setup.bash
source /home/robotics/Rover/install/setup.bash

sudo chmod 777 /dev/video*
fastdds discovery --server-id 0 &
ros2 launch rover_launch launch_all.launch.py

exec "$@"
