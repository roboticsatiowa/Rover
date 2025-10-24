#!/usr/bin/env bash
set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

# other dependencies
sudo apt install -y libopencv-dev python3-pip python3-catkin-pkg python3-venv mapproxy
pip install catkin-pkg # for some reason the apt package alone doesn't work. catkin-pkg must be install through pip

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

echo
echo
echo "Success"
echo "Please restart your terminal or run 'source ~/.bashrc' to apply changes"

