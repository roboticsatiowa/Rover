#syntax=docker/dockerfile:1

FROM ros:jazzy-ros-base-noble

SHELL ["/bin/bash", "-c"]

# This is technically redundant but installing most of the big dependencies here reduces build times significantly via caching
RUN apt-get update && apt-get install -y \
    ros-jazzy-controller-manager \
    ros-jazzy-cv-bridge \
    ros-jazzy-foxglove-bridge \
    ros-jazzy-gz-ros2-control \
    ros-jazzy-hardware-interface \
    ros-jazzy-joint-limits \
    ros-jazzy-joy \
    ros-jazzy-realsense2-camera \
    ros-jazzy-ros-gz \
    ros-jazzy-ros2-control \
    ros-jazzy-ros2-control-test-assets \
    ros-jazzy-ros2-controllers \
    ros-jazzy-rtabmap-ros \
    ros-jazzy-teleop-twist-joy \
    ros-jazzy-ublox \
    ros-jazzy-usb-cam

RUN apt-get update && apt-get install -y \
    libgstreamer1.0-dev \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-tools

RUN echo "deb [trusted=yes] https://download.eclipse.org/zenoh/debian-repo/ /" | tee -a /etc/apt/sources.list > /dev/null
RUN apt-get update && apt-get install -y \
    zenoh-bridge-ros2dds \
    ros-jazzy-rmw-cyclonedds-cpp

    
ENV RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
WORKDIR /rover
SHELL ["/bin/bash", "-c"]
ENTRYPOINT ["bash", "-c", "source /opt/ros/jazzy/setup.bash && source /rover/install/setup.bas
