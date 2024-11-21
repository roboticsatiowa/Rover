# syntax=docker/dockerfile:1

FROM ros:jazzy-ros-base

SHELL ["/bin/bash", "-c"]

COPY . /ros/src
WORKDIR /ros
RUN source /opt/ros/jazzy/setup.bash && colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release

ENTRYPOINT [ "ros2", "launch", "uirover_bringup" ]
CMD [ "all.launch.py" ]