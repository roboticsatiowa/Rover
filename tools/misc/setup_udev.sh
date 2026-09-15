#!/usr/bin/env bash
#
# This script symlinks the udev rules to the correct location
# Udev rules allow various serial devices to have predictable names
# without this, the serial devices will be assigned names like /dev/ttyACM0
# and /dev/ttyACM1, which can change order between reboots. without it, any 
# hard-coded paths to serial devices will break.

set -eo pipefail

# ensure permissions are correct
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

UDEV_DIR="$SCRIPT_DIR"/../../udev

# check if udev rules are already symlinked
if [ ! -L /etc/udev/rules.d/99-uirover-udev.rules ]; then
  ln -s "$UDEV_DIR"/99-uirover-udev.rules /etc/udev/rules.d/99-uirover-udev.rules || exit 1
fi

if [ ! -L /etc/udev/rules.d/99-realsense-d4xx-mipi-dfu.rules ]; then
  ln -s "$UDEV_DIR"/99-realsense-d4xx-mipi-dfu.rules /etc/udev/rules.d/99-realsense-d4xx-mipi-dfu.rules || exit 1
fi

if [ ! -L /etc/udev/rules.d/99-realsense-libusb.rules ]; then
  ln -s "$UDEV_DIR"/99-realsense-libusb.rules /etc/udev/rules.d/99-realsense-libusb.rules || exit 1
fi

if [ ! -L /etc/security/limits.d/99-uirover-rt-limits.conf ]; then
  ln -s "$UDEV_DIR"/99-uirover-rt-limits.conf /etc/security/limits.d/99-uirover-rt-limits.conf || exit 1
fi

udevadm control --reload-rules || exit 1

echo "Success"
