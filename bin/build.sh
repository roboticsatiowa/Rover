#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
    
(cd "$SCRIPT_DIR"/../ && colcon build)
. "$SCRIPT_DIR"/../install/setup.sh
