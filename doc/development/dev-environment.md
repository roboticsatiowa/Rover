# Development Environment Setup

> How to configure your local machine for Rover development, including IDE integration, build tooling, and environment variables.

## Overview

The workspace is a standard ROS2 colcon workspace targeting Ubuntu 24.04 (Noble) with ROS2 Jazzy. The build system generates a `compile_commands.json` file that enables accurate IntelliSense, go-to-definition, and diagnostics in VSCode. Most setup steps are automated by scripts in `tools/ros/`.

## Prerequisites

- Ubuntu 24.04 (Noble) — required; `tools/ros/install_ros.sh` will exit if this is not met
- Internet access for initial dependency installation

## Initial Setup

Run these scripts once in order:

```bash
# 1. Install ROS2 Jazzy
./tools/ros/install_ros.sh

# 2. Restart your terminal, then install non-ROS dependencies
./tools/ros/install_dependencies.sh

# 3. Resolve ROS package dependencies
./tools/ros/rosdep.sh

# 4. Build the workspace
./tools/ros/build.sh
```

See [Tools: ros/](tooling/ros/README.md) for details on what each script does.

## The Build Script & Colcon Mixins

`tools/ros/build.sh` wraps `colcon build` with a fixed set of arguments:

| Flag | Effect |
|------|--------|
| `--mixin compile-commands` | Generates `build/compile_commands.json` for IDE integration |
| `--symlink-install` | Symlinks installed files so Python scripts and launch files update without a rebuild |
| `--parallel-workers 0` | Uses all available CPU cores |
| `--continue-on-error` | Keeps building other packages when one fails |
| `--cmake-args -DCMAKE_BUILD_TYPE=Debug` | Added only when `--debug` flag is passed |

The mixin system is bootstrapped automatically by the build script: it adds the `default` mixin repository and runs `colcon mixin update default` on first run. You should not need to run `colcon mixin` commands manually.

**Debug builds:**

```bash
./tools/ros/build.sh --debug
```

## compile_commands.json

After a successful build, `build/compile_commands.json` is generated. This file tells your IDE exactly how each translation unit was compiled — include paths, defines, flags — which is what makes IntelliSense accurate for ROS2 and system headers.

The file is regenerated on every build. If IntelliSense is stale or broken, rebuild.

## VSCode Setup

### Pointing VSCode at compile_commands.json

The workspace already includes `.vscode/c_cpp_properties.json` configured correctly:

```json
"compileCommands": "${workspaceFolder}/build/compile_commands.json"
```

No manual configuration is needed. If you are starting from scratch or the file is missing, add the above field to the `Linux` configuration in `.vscode/c_cpp_properties.json`.

### Recommended Extensions

These are the extensions listed in `.devcontainer/devcontainer.json` and `.vscode/extensions.json`:

| Extension | ID | Purpose |
|-----------|----|---------|
| C/C++ Extension Pack | `ms-vscode.cpptools-extension-pack` | IntelliSense, debugging, CMake |
| ROS | `ms-iot.vscode-ros` | ROS2 node/topic introspection, launch file support |
| Python | `ms-python.python` | Python language support |
| Ruff | `charliermarsh.ruff` | Python linter/formatter |
| URDF | `smilerobotics.urdf` | URDF preview |
| XML | `redhat.vscode-xml` | URDF/SRDF/xacro editing |
| ShellCheck | `timonwong.shellcheck` | Shell script linting |
| Even Better TOML | `tamasfe.even-better-toml` | TOML support (Cargo, config files) |
| Markdown All in One | `yzhang.markdown-all-in-one` | Markdown editing and preview |
| Docker | `ms-azuretools.vscode-docker` | Docker container management |

### File Associations

`.devcontainer/devcontainer.json` configures these associations so XML-based ROS formats get proper highlighting:

```json
"files.associations": {
    "*.rviz": "yaml",
    "*.srdf": "xml",
    "*.urdf": "xml",
    "*.xacro": "xml"
}
```

Add these to your user or workspace `settings.json` if working outside the dev container.

### VSCode Tasks

Pre-configured tasks are available via `Terminal → Run Task` or `Ctrl+Shift+B` (default build task):

| Task | Command |
|------|---------|
| **ROS build** (default) | `tools/ros/build.sh` |
| **ROS clean** | `tools/ros/clean.sh` |
| **ROS run sim** | Launches Gazebo simulator |
| **ROS run rover** | Launches full rover stack |
| **ROS view urdf** | Opens URDF preview in RViz2 |

## Environment Variables

`tools/ros/build.sh` appends the following to `install/setup.bash` on every build. Source this file after building to apply them:

```bash
source install/setup.bash
```

| Variable | Value | Purpose |
|----------|-------|---------|
| `RCUTILS_COLORIZED_OUTPUT` | `1` | Colorized ROS2 log output |
| `ROS_DOMAIN_ID` | `0` | ROS2 DDS domain — all nodes must share a domain to communicate |
| `ROS_AUTOMATIC_DISCOVERY_RANGE` | `LOCALHOST` | Restricts DDS discovery to localhost; cross-machine comms go through Zenoh |
| `RMW_IMPLEMENTATION` | `rmw_zenoh_cpp` | Sets Zenoh as the ROS2 middleware |
| `ZENOH_ROUTER_CONFIG_URI` | `<ws>/zenoh_basestation.config.json5` | Default Zenoh config (set to rover config when running on rover) |

`install_ros.sh` also appends to `~/.bashrc`:

```bash
source /opt/ros/jazzy/setup.bash
export ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST
```

`install_dependencies.sh` appends the PlatformIO binary path:

```bash
export PATH=$HOME/.platformio/penv/bin:$PATH
```

## Troubleshooting

**IntelliSense shows errors on ROS2 headers** — `build/compile_commands.json` is missing or stale. Run `./tools/ros/build.sh` and reload VSCode.

**`colcon` command not found** — The build script installs `python3-colcon-common-extensions` automatically, but this requires `sudo`. Ensure you have sudo access and re-run the build.

**Mixin update fails during build** — If the machine is offline, `colcon mixin update default` will fail. If the mixin file already exists at `~/.colcon/mixin/default/compile-commands.mixin`, the script skips the update and proceeds normally.

**`source install/setup.bash` fails** — The install directory is only created after a successful build. Run `./tools/ros/build.sh` first.

## See Also

- [Setup](../getting-started/setup.md)
- [Docker](docker.md)
- [Tools: ros/](tooling/ros/README.md)
- [Tools: misc/](tooling/misc/README.md)
- [Testing](testing.md)
