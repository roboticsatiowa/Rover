#!/bin/bash

source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 launch rover_launch launch_all.launch.py &

exec "$@"
