#! /usr/bin/env bash

source /opt/ros/humble/setup.bash 
source /rover/install/setup.bash

# start arducam capture for each ardumcam device currently connected
for i in $(ls /dev/Arducam | grep CAM); do
    ros2 run arducam arducam_video --ros-args -p cam_index:=${i:3:10}
done

