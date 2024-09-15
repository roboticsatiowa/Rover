# syntax=docker/dockerfile:1

FROM build-base:latest AS build

COPY ./src/simple_hardware_interface /rover/src/simple_hardware_interface
WORKDIR /rover
RUN colcon build

FROM ros:humble-ros-core-jammy

SHELL [ "/bin/bash", "-c" ]

# Copy built files
COPY --from=build /rover/install /rover/install
COPY --from=build /rover/build /rover/build
COPY ./docker/camera_pipeline/entrypoint.sh /rover/entrypoint