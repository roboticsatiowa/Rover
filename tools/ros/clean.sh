#!/usr/bin/env bash

set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

# clean up generated urdf before building. Sometimes when building the urdf is not properly generated if the file already exists.
# This workaround forces the urdf to freshly generated each build
rm -f "${WS_DIR}"/src/uirover_description/urdf/*.urdf

(cd "$WS_DIR" && colcon clean workspace -y)
(cd "$WS_DIR/src" && colcon clean workspace -y) # sometimes its easy to accidentally build in the src directory. This will clean that up too
