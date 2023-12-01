// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaac_ros_visual_slam_interfaces:srv/SetOdometryPose.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__STRUCT_H_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/SetOdometryPose in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request
{
  geometry_msgs__msg__Pose pose;
} isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request.
typedef struct isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request__Sequence
{
  isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetOdometryPose in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response
{
  bool success;
} isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response.
typedef struct isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response__Sequence
{
  isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__STRUCT_H_
