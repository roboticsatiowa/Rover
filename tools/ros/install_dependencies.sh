#!/usr/bin/env bash
set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory



if ! grep -q "https://download.eclipse.org/zenoh/debian-repo/" /etc/apt/sources.list; then
    echo "deb [trusted=yes] https://download.eclipse.org/zenoh/debian-repo/ /" | sudo tee -a /etc/apt/sources.list > /dev/null
fi
sudo apt update

if [ ! -d /etc/ros/rosdep/sources.list.d ]; then
    sudo apt install -y python3-rosdep
    sudo rosdep init
fi

rosdep update --rosdistro jazzy
rosdep install --from-paths "${WS_DIR}/src" --ignore-src -y


# other dependencies
sudo apt install -y python3-colcon-common-extensions python3-colcon-clean libopencv-dev zenoh-bridge-ros2dds

python3-

# Foxglove Studio
if [ ! -f /usr/bin/foxglove-studio ]; then
    wget https://get.foxglove.dev/desktop/latest/foxglove-studio-latest-linux-amd64.deb
    sudo apt install -y ./foxglove-studio-latest-linux-amd64.deb
    rm -f ./foxglove-studio-latest-linux-amd64.deb
fi