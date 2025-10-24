#!/usr/bin/env bash

# https://control.ros.org/rolling/doc/ros2_control/controller_manager/doc/userdoc.html
# The normal linux kernel is optimized for computational throughput and therefore is not well suited for hardware control.
# This script adds custom limits to /etc/security/limits.d/ to allow users of the 'realtime' group to increase their
# CPU scheduling priority. This gives ROS2 control more consistent behavior and reduces jitter in control loops.
# For the best possible performance a 'real-time' kernel should be installed. Nvidia provides guides for this 
# here: https://docs.nvidia.com/jetson/archives/r36.2/DeveloperGuide/SD/Kernel/KernelCustomization.html
#
#
# IMPORTANT: It may not be advisable to install a realtime kernel on your personal machine. Proceed with caution

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if ! cat "/etc/group" | grep -q realtime; then
    sudo groupadd realtime
    echo "Created realtime group"
else
    echo "realtime group already exists"
fi

if ! groups "$(whoami)" | grep -q realtime; then
    sudo usermod -aG realtime "$(whoami)"
    echo "Added $(whoami) to realtime group"
else
    echo "$(whoami) already in realtime group"
fi

if sudo cp "${SCRIPT_DIR}/99-uirover-rt-limits.conf" /etc/security/limits.d/; then
    echo "Succesfully added security rules. Reboot to apply changes"
else
    echo "ERROR: Failed to add security rules"
fi

