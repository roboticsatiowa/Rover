#syntax=docker/dockerfile:1

FROM ros:jazzy-ros-base-noble

SHELL ["/bin/bash", "-c"]


COPY ./src /ros/src
WORKDIR /ros
RUN apt-get update && rosdep update --rosdistro jazzy && rosdep install --from-paths src -i src/uirover_meta -y
RUN source /opt/ros/jazzy/setup.bash && colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release

ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/jazzy/setup.bash && source /ros/install/setup.bash && ros2 launch uirover_bringup rover.launch.py" ]