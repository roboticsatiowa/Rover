# syntax=docker/dockerfile:1

FROM build-base:latest AS build

COPY ./src/arducam /rover/src/arducam
WORKDIR /rover
RUN colcon build

RUN git clone https://github.com/unitreerobotics/unilidar_sdk.git

# TODO for Eli
# start here. this is a youtube tutorial on the docker basics: https://www.youtube.com/watch?v=gAkwW2tuIqE
# here is an overview of how dockerfiles syntax works: https://docs.docker.com/build/concepts/dockerfile/
# here is a more complete reference for all commands:  https://docs.docker.com/engine/reference/builder/
# I would recommend checking those resources out before continuing.

# unilidar instructions here: https://github.com/unitreerobotics/unilidar_sdk/blob/main/unitree_lidar_ros2/src/unitree_lidar_ros2/README.md

# install PCL-1.10 (PCL = Point Cloud Library) - look here: https://pointclouds.org/downloads/#linux
# build using colcon build
# there will probably be a few errors, most likely due to missing dependencies. copy pasting the error into google will usually give you the package name you need to install
# use camera_pipeline as an example of how to install dependencies
# repeat until it builds successfully
# modify the entrypoint.sh to launch the correct launch file. use camera_pipeline as an example

FROM ros:humble-ros-core-jammy

SHELL [ "/bin/bash", "-c" ]


# you probably wont need to modify this section. if there are any dependencies needed to RUN the code (not build it), you can add them here. 
# the syntax is the same as before. delete this comment when you're done.

# Copy built files
COPY --from=build /rover/install /rover/install
COPY --from=build /rover/build /rover/build
COPY ./docker/camera_pipeline/entrypoint.sh /rover/entrypoint
