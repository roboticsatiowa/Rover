#!/usr/bin/env bash

(docker kill rover-container &> /dev/null && echo "Container killed successfully" ) || echo "No container to kill" 