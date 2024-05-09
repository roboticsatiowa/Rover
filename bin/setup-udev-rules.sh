#!/usr/bin/env bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
UDEV_RULES_DIR="/etc/udev/rules.d/"

ln -s "${SCRIPT_DIR}/udev-robotics.rules" "${UDEV_RULES_DIR}/udev-robotics.rules"