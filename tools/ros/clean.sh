#!/usr/bin/env bash

set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

(cd "$WS_DIR" && colcon clean workspace -y)
(cd "$WS_DIR/src" && colcon clean workspace -y) # sometimes its easy to accidentally build in the src directory. This will clean that up too
