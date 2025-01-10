#!/usr/bin/env bash
set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

sudo apt update

if [ ! -d /etc/ros/rosdep/sources.list.d ]; then
    sudo apt install -y python3-rosdep
    sudo rosdep init
fi

rosdep update --rosdistro jazzy
rosdep install --from-paths $WS_DIR/src --ignore-src -y

# other dependencies
sudo apt install -y python3-colcon-common-extensions python3-colcon-clean 

# GStreamer
sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio

# Foxglove Studio
if [ ! -f /usr/bin/foxglove-studio ]; then
    wget https://get.foxglove.dev/desktop/latest/foxglove-studio-latest-linux-amd64.deb
    sudo apt install ./foxglove-studio-latest-linux-amd64.deb
    rm -f ./foxglove-studio-latest-linux-amd64.deb
fi