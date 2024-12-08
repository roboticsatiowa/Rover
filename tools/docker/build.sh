#! /usr/bin/env bash

set -eo pipefail

WS_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )

(cd $WS_DIR && docker build . -t uirover:latest)