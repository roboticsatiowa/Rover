// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__STRUCT_H_
#define ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'node_name'
// Member 'node_namespace'
// Member 'topic_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TopicStatistics in the package isaac_ros_nitros_interfaces.
/**
  * Statistics data for a ROS Node
 */
typedef struct isaac_ros_nitros_interfaces__msg__TopicStatistics
{
  /// Name of the ROS Node associated with the topic
  rosidl_runtime_c__String node_name;
  /// Namspace of the ROS topic
  rosidl_runtime_c__String node_namespace;
  /// Name of the topic
  rosidl_runtime_c__String topic_name;
  /// true if subscriber and false if publisher
  bool is_subscriber;
  /// Windowed mean frame rate
  float frame_rate;
  /// jitter is the difference between the time between msgs(dt)
  /// calculated from fps specified in NITROS statistics ROS param
  /// and measured using system clock
  /// Units is microseconds
  /// mean absolute jitter
  int32_t mean_abs_jitter;
  /// maximum absolute jitter
  int32_t max_abs_jitter;
} isaac_ros_nitros_interfaces__msg__TopicStatistics;

// Struct for a sequence of isaac_ros_nitros_interfaces__msg__TopicStatistics.
typedef struct isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence
{
  isaac_ros_nitros_interfaces__msg__TopicStatistics * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__STRUCT_H_
