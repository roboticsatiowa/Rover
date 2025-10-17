#!/usr/bin/env bash

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

# --ignore-src: ignore deps that can be found in src
# -r: continue despite errors
# -y: assume yes to all prompts
rosdep install --from-paths "${WS_DIR}/src" --ignore-src -r -y