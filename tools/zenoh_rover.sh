#!/usr/bin/env bash

zenoh-bridge-ros2dds \
    --ros-localhost-only \
    --no-multicast-scouting \
    --pub-max-frequency ".*=5" \
    -l udp/0.0.0.0:7447 \