#syntax=docker/dockerfile:1

FROM ros:jazzy-ros-base-noble

SHELL ["/bin/bash", "-c"]

# ROS Dependencies
RUN apt-get update && apt-get install -y \
    ros-jazzy-controller-manager \
    ros-jazzy-cv-bridge \
    ros-jazzy-foxglove-bridge \
    ros-jazzy-gz-ros2-control \
    ros-jazzy-hardware-interface \
    ros-jazzy-joint-limits \
    ros-jazzy-joy \
    ros-jazzy-realsense2-camera \
    ros-jazzy-rmw-zenoh-cpp \
    ros-jazzy-ros-gz \
    ros-jazzy-ros2-control \
    ros-jazzy-ros2-control-test-assets \
    ros-jazzy-ros2-controllers \
    ros-jazzy-rtabmap-ros \
    ros-jazzy-teleop-twist-joy \
    ros-jazzy-ublox \
    ros-jazzy-usb-cam \
    && rm -rf /var/lib/apt/lists/*

# Gstreamer
RUN apt-get update && apt-get install -y \
    libgstreamer1.0-dev \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-tools \
    && rm -rf /var/lib/apt/lists/*
    
RUN echo "source /opt/ros/jazzy/setup.bash" >> /root/.bashrc

ENV RMW_IMPLEMENTATION=rmw_zenoh_cpp
ENV ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST
ENV ZENOH_SESSION_CONFIG_URI=/rover/zenoh_rover.config.json5

WORKDIR /rover
ENTRYPOINT ["bash", "-c"] 
CMD ["/rover/docker_entrypoint"]
