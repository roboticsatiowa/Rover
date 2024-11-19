#!/usr/bin/env bash

set -eo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

rm -rf "${SCRIPT_DIR}/../../build" "${SCRIPT_DIR}/../../install" "${SCRIPT_DIR}/../../log"