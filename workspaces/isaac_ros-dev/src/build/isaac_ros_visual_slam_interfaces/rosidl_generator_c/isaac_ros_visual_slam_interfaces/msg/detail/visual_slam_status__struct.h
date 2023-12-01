// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__STRUCT_H_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/VisualSlamStatus in the package isaac_ros_visual_slam_interfaces.
/**
  * This is a status message which gives insights about tracker status and execution time which can help in diagnostics and profiling.
  * The frame id in the header is used as the reference frame of both the transforms below.
 */
typedef struct isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus
{
  std_msgs__msg__Header header;
  /// Pure visual odometry return code:
  /// 0 - Unknown state
  /// 1 - Success
  /// 2 - Failed
  /// 3 - Success but invalidated by IMU
  uint8_t vo_state;
  /// The total time it takes to process the input frames to output messages in seconds.
  double node_callback_execution_time;
  /// Time it takes to get current pose out of cuVSLAM using pure visual slam tracking in seconds.
  double track_execution_time;
  /// Mean time to get poses out of cuVSLAM using pure visual slam tracking in seconds.
  double track_execution_time_mean;
  /// Max time to get poses out of cuVSLAM using pure visual slam tracking in seconds.
  double track_execution_time_max;
} isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus.
typedef struct isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence
{
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__STRUCT_H_
