#!/usr/bin/env bash

set -eo pipefail

# ensure permissions are correct
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

ln -s $(realpath "$SCRIPT_DIR"/../../systemd/rover.service) /etc/systemd/system/rover.service
