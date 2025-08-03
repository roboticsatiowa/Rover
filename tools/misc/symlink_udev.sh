#!/usr/bin/env bash
#
# @(#)$Id$
#
# Author: Ethan Holter
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

# check if udev rules are already symlinked
if [ -L /etc/udev/rules.d/99-uirover.rules ]; then
  echo "udev rules already symlinked"
  exit
fi

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ln -s "$SCRIPT_DIR"/udev.rules /etc/udev/rules.d/99-uirover.rules || exit 1
udevadm control --reload-rules || exit 1

echo "Success"
