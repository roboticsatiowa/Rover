#!/usr/bin/env bash
set -eo pipefail
shopt -s globstar nullglob

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

# colcon has a very weird cli so instead we manually concatenate all the logs in the event of a failure.
# This results in a much more readable output.
function print_stderr_logs () {
    for file in $WS_DIR/log/latest/**/stderr.log;
    do
        # check if file is empty
        if [ ! -s "$file" ]; then
            continue
        fi
        echo
        echo
        echo "ERROR $file:"
        cat "$file"
    done
}

# Auto detect and install mandatory colcon packages if not already installed
UPDATED=false
if dpkg-query -W python3-colcon-common-extensions &> /dev/null; then
    echo "colcon-common-extensions is already installed"
else
    echo "Installing colcon-common-extensions"
    
    if [ "$UPDATED" = false ]; then
        sudo apt update
        UPDATED=true
    fi
    sudo apt install -y python3-colcon-common-extensions
fi
if dpkg-query -W python3-colcon-mixin &> /dev/null; then
    echo "colcon-mixin is already installed"
else
    echo "Installing colcon-mixin"
    
    if [ "$UPDATED" = false ]; then
        sudo apt update
        UPDATED=true
    fi
    sudo apt install -y python3-colcon-mixin
fi
MIXIN_URL="https://raw.githubusercontent.com/colcon/colcon-mixin-repository/master/index.yaml"
if ! colcon mixin list 2>/dev/null | grep -q "$MIXIN_URL"; then
    colcon mixin add default "$MIXIN_URL"
fi

# desktop_notification- console_stderr- disable annoying features of colcon
# --continue-on-error continues building other packages even if one fails
# --parallel-workers 0 uses all available CPU cores
# --symlink-install symlinks files so we don't have to rebuild after every change
# --mixin compile-commands generates WS_DIR/build/compile_commands.json for vscode and other IDEs
COLCON_ARGS="--mixin compile-commands \
--continue-on-error \
--parallel-workers 0 \
--symlink-install \
--event-handlers desktop_notification- console_stderr-"

(cd $WS_DIR && colcon build $COLCON_ARGS || print_stderr_logs)

# Enable colored output for ROS2 command line tools
echo "export RCUTILS_COLORIZED_OUTPUT=1" >> "${WS_DIR}/install/setup.bash"

# Ideally we would automatically source the setup.bash file after building, but this is causing bash tab completion to completetly crash gnome-terminal.
# Not sure why, but in case this ever gets fixed, here is the line to do it:
## shellcheck source=/dev/null
#. "${WS_DIR}/install/setup.bash"