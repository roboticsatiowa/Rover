# generated from ament_cmake_export_include_directories/cmake/ament_cmake_export_include_directories-extras.cmake.in

set(_exported_include_dirs "${isaac_ros_nitros_DIR}/../../../include;/workspaces/isaac_ros-dev/install/isaac_ros_gxf/share/isaac_ros_gxf/gxf/include/gxf;/workspaces/isaac_ros-dev/install/isaac_ros_gxf/share/isaac_ros_gxf/gxf/include/gxf/gxf_optimizer;/workspaces/isaac_ros-dev/install/isaac_ros_gxf/share/isaac_ros_gxf/gxf/include;/workspaces/isaac_ros-dev/install/isaac_ros_gxf/share/isaac_ros_gxf/cmake/../gxf/include/gxf/isaac_messages;/workspaces/isaac_ros-dev/install/isaac_ros_gxf/share/isaac_ros_gxf/cmake/../gxf/include/gxf/message_compositor")

# append include directories to isaac_ros_nitros_INCLUDE_DIRS
# warn about not existing paths
if(NOT _exported_include_dirs STREQUAL "")
  find_package(ament_cmake_core QUIET REQUIRED)
  foreach(_exported_include_dir ${_exported_include_dirs})
    if(NOT IS_DIRECTORY "${_exported_include_dir}")
      message(WARNING "Package 'isaac_ros_nitros' exports the include directory '${_exported_include_dir}' which doesn't exist")
    endif()
    normalize_path(_exported_include_dir "${_exported_include_dir}")
    list(APPEND isaac_ros_nitros_INCLUDE_DIRS "${_exported_include_dir}")
  endforeach()
endif()
