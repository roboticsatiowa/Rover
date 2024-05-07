#!/usr/bin/env bash
# DRY programming lmfao. Not here.
set -eo pipefail

getopts "y" yestoall || true

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
cd "${SCRIPT_DIR}"

# check if running as root
if [ "$EUID" -eq 0 ]; then
    echo "ERROR: This script should not be run as root"
    exit 1
fi

# check if distro is ubuntu
if [ "$(lsb_release -is)" != "Ubuntu" ]; then
    echo "ERROR: Must be running Ubuntu to install this project"
    exit 1
fi

# Check Ubuntu version is 22.04
if [ "$(lsb_release -cs)" != "jammy" ]; then
    echo "WARNING: You are running: Ubuntu $(lsb_release -rs). This project is designed for Ubuntu 22.04"
    read -r -p "Proceed at your own risk. Do you want to continue? [y/N] " CONTINUE
    if [ "$CONTINUE" != "y" ]; then
        echo "Exiting..."
        exit 1
    fi
    exit 1

else 
    echo "Ubuntu 22.04 detected. Proceeding with installation..."
fi

# Install ROS2 Humble

# check if ros distro is already installed but not humble
if [ -n "$ROS_DISTRO" ] && [ "$ROS_DISTRO" != "humble" ]; then
    echo "ERROR: Another ROS distro (${ROS_DISTRO}) detected. Multiple ROS distros may cause conflicts."
    read -r -p "Do you want to continue? [y/N] " CONTINUE
    if [ "$CONTINUE" != "y" ]; then
        echo "Exiting..."
        exit 1
    fi
fi

if [ -z "$ROS_DISTRO" ]; then
    if [ $yestoall ]; then
        INSTALL="y"
    else
        read -r -p "No ROS distro detected. Do you want to install ROS2 Humble? [Y/n] " INSTALL
    fi
    if [ "${INSTALL:-'y'}" == "y" ]; then
        sudo apt update -y
        sudo apt upgrade -y
        sudo apt install locales -y
        sudo locale-gen en_US en_US.UTF-8 
        sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 -y
        sudo apt install software-properties-common -y
        sudo add-apt-repository universe -y
        sudo apt update -y
        sudo apt install curl -y
        sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
        echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list >/dev/null
        sudo apt update -y
        sudo apt upgrade -y
        sudo apt install ros-humble-desktop -y
        source /opt/ros/humble/setup.bash
    fi
fi

# Misc dependencies
sudo apt install python3-venv python3-rosdep2 python3-colcon-common-extensions ros-humble-rosbag2 ros-humble-ament-cmake -y

# install package dependencies
rosdep update
rosdep install --from-paths src --ignore-src -r -y

# add ROS2 Humble sources to bashrc

if [ $yestoall ]; then
    ADD_SOURCE="y"
else
    read -r -p "Add ROS2 Humble sources to bashrc? (Recommended) [Y/n] " ADD_SOURCE
fi
if [ "${ADD_SOURCE:-"y"}" == "y" ]; then
    grep -q "source /opt/ros/humble/setup.bash" "${HOME}/.bashrc" || echo "source /opt/ros/humble/setup.bash" >> "${HOME}/.bashrc"
fi

# add Domain ID to bashrc
if [ $yestoall ]; then
    ADD_DOMAIN="y"
else
    read -r -p "Add Domain ID to bashrc? (Recommended) [Y/n] " ADD_DOMAIN
fi
if [ "${ADD_DOMAIN:-"y"}" == "y" ]; then
    grep -q "export ROS_DOMAIN_ID=69" "${HOME}/.bashrc" || echo "export ROS_DOMAIN_ID=69" >> "${HOME}/.bashrc"
fi

# build the workspace
if [ $yestoall ]; then
    BUILD="y"
else
    read -r -p "Build the workspace? [Y/n] " BUILD
fi
if [ "${BUILD:-"y"}" == "y" ]; then
    colcon build
fi

# source workspace from bashrc
if [ $yestoall ]; then
    SOURCE_WORKSPACE="y"
else
    read -r -p "Source workspace from bashrc? (Only recommended on actual rover) [Y/n] " SOURCE_WORKSPACE
fi
if [ "${SOURCE_WORKSPACE:-"y"}" == "y" ]; then
    grep -q "source ${SCRIPT_DIR}/install/setup.bash" "${HOME}/.bashrc" || echo "source ${SCRIPT_DIR}/install/setup.bash" >> "${HOME}/.bashrc"
fi

# Additional information

echo "Installation complete."; echo; echo

echo "Next steps:"
echo "    - To build the workspace, run: colcon build"
echo "    - to source the workspace, run: source install/setup.bash"
echo "    - To launch a package from the workspace, run: ros2 launch <package_name> <launch_file>"
echo "    - To run a node from the workspace, run: ros2 run <package_name> <node_name>"
echo "    - Refer to ./bin/remote_launch.sh for information on what happens when rover is launched"

echo; echo

bash # start a new bash shell to source the workspace

# End of file