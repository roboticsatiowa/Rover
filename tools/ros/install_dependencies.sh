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
sudo apt install -y python3-colcon-common-extensions python3-colcon-clean libopencv-dev zenoh-bridge-ros2dds python3-pip python3-catkin-pkg python3-venv

# gstreamer
sudo apt install -y libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio

# PlatformIO
if ! command -v platformio > /dev/null;  then
    curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
    python3 get-platformio.py
    rm -f get-platformio.py
    grep -q "export PATH=$HOME/.platformio/penv/bin:\$PATH" ~/.bashrc || echo "export PATH=$HOME/.platformio/penv/bin:\$PATH" >> ~/.bashrc
    curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules
fi

# Foxglove Studio
if [ ! -f /usr/bin/foxglove-studio ]; then
    wget https://get.foxglove.dev/desktop/latest/foxglove-studio-latest-linux-amd64.deb
    sudo apt install -y ./foxglove-studio-latest-linux-amd64.deb
    rm -f ./foxglove-studio-latest-linux-amd64.deb
fi

echo
echo
echo "Success"
echo "Please restart your terminal or run 'source ~/.bashrc' to apply changes"

