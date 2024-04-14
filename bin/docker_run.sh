#!/usr/bin/env bash
set -eo pipefail

SCRIPT_DIR=$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
CURRENT_DIR=$(pwd)

cd "$SCRIPT_DIR/.."
mkdir -p bag

# run container
docker compose run rover bash


cd "$CURRENT_DIR"