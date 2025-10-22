#!/usr/bin/env bash

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

# install rosdep if not already
if ! apt -qq list python3-rosdep 2>/dev/null | grep -q installed; then
    echo "Installing rosdep"
    sudo apt update
    sudo apt install -y python3-rosdep
fi

# initialize rosdep if not already
if [ ! -f /etc/ros/rosdep/sources.list.d/20-default.list ]; then
    sudo rosdep init
fi

rosdep update
# --ignore-src: ignore deps that can be found in src
# -r: continue despite errors
# -y: assume yes to all prompts
rosdep install --from-paths "${WS_DIR}/src" --ignore-src -r -y