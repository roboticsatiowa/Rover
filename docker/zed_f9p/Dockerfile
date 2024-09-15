# syntax=docker/dockerfile:1

FROM build-base:latest

WORKDIR /rover
RUN colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release