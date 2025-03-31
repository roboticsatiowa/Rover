#!/usr/bin/env bash
set -eo pipefail
shopt -s globstar nullglob

WS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." &> /dev/null && pwd )" # workspace directory

# colcon has a very weird cli so instead we manually concatenate all the logs in the event of a faliure.
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

# clean up generated urdf before building. Sometimes when building the urdf is not properly generated if the file already exists.
# This workaround forces the urdf to freshly generated each build
rm -f "${WS_DIR}"/src/uirover_description/urdf/*.urdf

# desktop_notification- console_stderr- disable annoying features of colcon
(cd $WS_DIR && colcon build --cmake-args -DCMAKE_BUILD_TYPE=Debug --parallel-workers 0 --symlink-install --event-handlers desktop_notification- console_stderr- || print_stderr_logs)


# Ideally we would automatically source the setup.bash file after building, but this is causing bash tab completion to completetly crash gnome-terminal.
# Not sure why, but in case this ever gets fixed, here is the line to do it:
## shellcheck source=/dev/null
#. "${WS_DIR}/install/setup.bash"