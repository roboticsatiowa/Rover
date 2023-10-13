#!/bin/bash
set -e

# setup ros2 environment
source "/opt/ros/$ROS_DISTRO/setup.bash" --
export ROS_DOMAIN_ID=1
exec "$@"
