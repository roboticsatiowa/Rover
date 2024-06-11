#!/usr/bin/env bash

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
ln -s "$SCRIPT_DIR"/../udev.rules /etc/udev/rules.d/99-uirover.rules