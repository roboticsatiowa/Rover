#!/usr/bin/env bash

set -eo pipefail

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

rm -rf "${WS_DIR}/build" "${WS_DIR}/install" "${WS_DIR}/log"
rm -rf "${WS_DIR}/src/build" "${WS_DIR}/src/install" "${WS_DIR}/src/log" # sometimes easy to build in src dir by mistake. might as well clean it up too
