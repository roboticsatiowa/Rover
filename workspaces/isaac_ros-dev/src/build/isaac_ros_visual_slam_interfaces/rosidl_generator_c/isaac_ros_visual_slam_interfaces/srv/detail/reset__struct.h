// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaac_ros_visual_slam_interfaces:srv/Reset.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__STRUCT_H_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Reset in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__srv__Reset_Request
{
  uint8_t structure_needs_at_least_one_member;
} isaac_ros_visual_slam_interfaces__srv__Reset_Request;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__srv__Reset_Request.
typedef struct isaac_ros_visual_slam_interfaces__srv__Reset_Request__Sequence
{
  isaac_ros_visual_slam_interfaces__srv__Reset_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__srv__Reset_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Reset in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__srv__Reset_Response
{
  bool success;
} isaac_ros_visual_slam_interfaces__srv__Reset_Response;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__srv__Reset_Response.
typedef struct isaac_ros_visual_slam_interfaces__srv__Reset_Response__Sequence
{
  isaac_ros_visual_slam_interfaces__srv__Reset_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__srv__Reset_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__STRUCT_H_
