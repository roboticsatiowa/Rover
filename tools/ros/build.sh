#!/usr/bin/env bash
set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

(cd $WS_DIR && colcon build --symlink-install --event-handlers desktop_notification- console_stderr-)

echo
echo "Stderr has been surpressed. Complete logs can be found at ${WS_DIR}/log/latest/events.log"