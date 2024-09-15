# syntax=docker/dockerfile:1

FROM build-base:latest AS build

COPY ./src/arducam /rover/src/arducam
WORKDIR /rover
RUN colcon build

FROM ros:humble-ros-core-jammy

SHELL [ "/bin/bash", "-c" ]

# Runtime dependencies. Mostly for OpenCV
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3-pip \
    ffmpeg \
    libsm6 \
    libxext6 \
    ros-humble-cv-bridge \
    && rm -rf /var/lib/apt/lists/* \
    && pip3 install --no-cache-dir opencv-python sympy

# Copy built files
COPY --from=build /rover/install /rover/install
COPY --from=build /rover/build /rover/build
COPY ./docker/camera_pipeline/entrypoint.sh /rover/entrypoint
