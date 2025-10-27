#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

if [ "$(lsb_release -cs)" != "noble" ]; then
  echo "ERROR: Ubuntu noble is required. You have $(lsb_release -cs)"
  exit 1
fi

# install ROS https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html
sudo apt install software-properties-common
sudo add-apt-repository universe -y
sudo apt update && sudo apt install curl -y
export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}')
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo ${UBUNTU_CODENAME:-${VERSION_CODENAME}})_all.deb"
sudo dpkg -i /tmp/ros2-apt-source.deb
sudo apt update
sudo apt upgrade
sudo apt install ros-dev-tools ros-jazzy-desktop python3-colcon-argcomplete -y

# source ROS2 on opening terminal. Sorry if you're upset with me screwing with your bashrc  ¯\_(ツ)_/¯
grep -qxF "source /opt/ros/jazzy/setup.bash" ~/.bashrc || echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc

# locks ROS to localhost. Prevents accidental interactions with other ROS systems on the same network. 
# Any ROS2 communication across machines should be done explicitly (i.e. with zenoh_bridge)
grep -qxF "export ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST" ~/.bashrc || echo "export ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST" >> ~/.bashrc

echo
echo
echo
echo "========================================"
echo "ROS2 Jazzy installation complete!"
echo "Restart your terminal or run 'source ~/.bashrc'"
echo "========================================"