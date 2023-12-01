// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaac_ros_visual_slam_interfaces:srv/GetAllPoses.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__STRUCT_H_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetAllPoses in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request
{
  /// Max number of poses to query
  int32_t max_count;
} isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request.
typedef struct isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request__Sequence
{
  isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/GetAllPoses in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response
{
  bool success;
  /// List of optimized poses
  geometry_msgs__msg__PoseStamped__Sequence poses;
} isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response.
typedef struct isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response__Sequence
{
  isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__STRUCT_H_
