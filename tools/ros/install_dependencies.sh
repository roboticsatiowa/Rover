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
rosdep install --from-paths $WS_DIR/src --ignore-src -y


# other dependencies
sudo apt install -y python3-colcon-common-extensions python3-colcon-clean zenoh-bridge-dds
sudo snap install foxglove-studio