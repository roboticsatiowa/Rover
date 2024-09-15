# syntax=docker/dockerfile:1

FROM ros:humble-ros-core-jammy AS build-base

RUN apt-get update && apt-get install -y \
    ros-dev-tools \
    && rm -rf /var/lib/apt/lists/*