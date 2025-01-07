#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# ensure ubuntu noble (24.04) is installed
if ! command -v lsb_release &> /dev/null; then
  echo "ERROR: lsb_release is not installed. This likely means you are not running Ubuntu and ROS2 Jazzy is not supported on your system."
  echo "It is also possible (but unlikely) you are simply missing that package. In this case, you can install it with 'sudo apt install lsb-release'"
  exit 1
fi

if [ "$(lsb_release -cs)" != "noble" ]; then
  echo "ERROR: Ubuntu noble is required. You have $(lsb_release -cs)"
  exit 1
fi

# install ROS
sudo apt install software-properties-common curl -y
sudo add-apt-repository universe -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
sudo apt update -y && sudo apt upgrade -y
sudo apt install ros-dev-tools ros-jazzy-desktop python3-colcon-argcomplete -y

# source ROS2 on opening terminal. Done by default since its assumed anyone with a level of expertise where they would not want this would also know how to remove it.
# most people would probably not know what this is, so its better just not to ask.
grep -qxF "source /opt/ros/jazzy/setup.bash" ~/.bashrc || echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc

# shellcheck source=/dev/null
. /opt/ros/jazzy/setup.bash

# install project dependencies
# shellcheck source=/dev/null
. "$SCRIPT_DIR/install_dependencies.sh"