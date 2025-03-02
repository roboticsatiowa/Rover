#! /usr/bin/env bash
set -eo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# ANSI color codes
ORANGE='\e[0;33m'
RED='\e[0;31m'
NC='\e[0m' # No Color

# ensure platformio is installed
if ! command -v platformio 2>&1 > /dev/null;  then
    echo -e "${RED}ERROR: PlatformIO is not installed. Please install run 'tools/ros/install_dependencies.sh' to install it.${NC}"
    exit 1
fi

if [ ! -f /etc/udev/rules.d/99-uirover.rules ]; then
    echo -e "${RED}ERROR: udev rules are set up. Please run 'tools/symlink_udev.sh' to symlink them.${NC}"
    exit 1
fi

(cd "$SCRIPT_DIR/../../teensy" && platformio run) || exit 1