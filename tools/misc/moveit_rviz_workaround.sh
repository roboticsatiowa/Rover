#!/usr/bin/env bash

# this script fixes an issue with the moveit2 setup assistant caused by a version incompatibility with rviz
# see https://github.com/moveit/moveit2/issues/3546


wget http://ec2-35-174-230-37.compute-1.amazonaws.com/jazzy/2025-05-23/ubuntu/pool/main/r/ros-jazzy-rviz-common/ros-jazzy-rviz-common_14.1.11-1noble.20250520.201719_amd64.deb
sudo dpkg -i ros-jazzy-rviz-common_14.1.11-1noble.20250520.201719_amd64.deb
rm ros-jazzy-rviz-common_14.1.11-1noble.20250520.201719_amd64.deb