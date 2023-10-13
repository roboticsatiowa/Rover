#!/bin/bash

docker build . --platform=linux/arm64/v8 -t "ros2-humble-isaac"
