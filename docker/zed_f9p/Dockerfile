# syntax=docker/dockerfile:1

FROM build-base:latest

# use bash instead of sh. allows us to use 'source' command.
SHELL [ "/bin/bash", "-c" ]

WORKDIR /rover
RUN git clone https://github.com/gokulp01/ros2-ublox-zedf9p
ADD ./docker/zed_f9p/zed_f9p.yaml /rover/src/ros2-ublox-zedf9p/ublox_gps/config/zed_f9p.yaml

RUN source /opt/ros/humble/setup.bash && colcon build