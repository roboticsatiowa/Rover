#syntax=docker/dockerfile:1

FROM ros:jazzy-ros-base-noble

SHELL ["/bin/bash", "-c"]

# This is technically redundant but installing most of the big dependencies here reduces build times significantly via caching
RUN apt-get update && apt-get install -y \
    ros-jazzy-usb-cam \
    ros-jazzy-cv-bridge \
    ros-jazzy-ros-gz \
    ros-jazzy-gz-ros2-control \
    ros-jazzy-ros2-control \
    ros-jazzy-ros2-controllers \
    ros-jazzy-controller-manager \
    ros-jazzy-hardware-interface \
    ros-jazzy-joint-limits \
    ros-jazzy-ros2-control-test-assets \
    ros-jazzy-foxglove-bridge \
    ros-jazzy-realsense2-camera \
    ros-jazzy-rtabmap-ros \
    ros-jazzy-ublox 

COPY ./src /ros/src
WORKDIR /ros
RUN apt-get update && rosdep update --rosdistro jazzy && rosdep install --from-paths src -i src/uirover_meta -y
RUN source /opt/ros/jazzy/setup.bash && colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release

ENTRYPOINT ["/bin/bash", "-c"]
CMD ["source /opt/ros/jazzy/setup.bash && source /ros/install/setup.bash && ros2 launch uirover_bringup rover.launch.py"]
