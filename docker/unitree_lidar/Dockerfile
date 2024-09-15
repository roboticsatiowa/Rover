# syntax=docker/dockerfile:1

FROM build-base:latest AS build

COPY ./src/arducam /rover/src/arducam
WORKDIR /rover
RUN colcon build

RUN git clone https://github.com/unitreerobotics/unilidar_sdk

FROM ros:humble-ros-core-jammy

SHELL [ "/bin/bash", "-c" ]



# Copy built files
COPY --from=build /rover/install /rover/install
COPY --from=build /rover/build /rover/build
COPY ./docker/camera_pipeline/entrypoint.sh /rover/entrypoint
