// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from isaac_ros_visual_slam_interfaces:action/SaveMap.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__SAVE_MAP__STRUCT_H_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__SAVE_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'map_url'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_Goal
{
  /// Localhost file path to save the map
  rosidl_runtime_c__String map_url;
} isaac_ros_visual_slam_interfaces__action__SaveMap_Goal;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_Goal.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_Goal__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_Result
{
  bool success;
  rosidl_runtime_c__String error;
} isaac_ros_visual_slam_interfaces__action__SaveMap_Result;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_Result.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_Result__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback
{
  int32_t progress;
} isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "isaac_ros_visual_slam_interfaces/action/detail/save_map__struct.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  isaac_ros_visual_slam_interfaces__action__SaveMap_Goal goal;
} isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Request;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Request.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Request__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Response;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Response.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Response__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Request;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Request.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Request__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/save_map__struct.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Response
{
  int8_t status;
  isaac_ros_visual_slam_interfaces__action__SaveMap_Result result;
} isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Response;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Response.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Response__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/save_map__struct.h"

/// Struct defined in action/SaveMap in the package isaac_ros_visual_slam_interfaces.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  isaac_ros_visual_slam_interfaces__action__SaveMap_Feedback feedback;
} isaac_ros_visual_slam_interfaces__action__SaveMap_FeedbackMessage;

// Struct for a sequence of isaac_ros_visual_slam_interfaces__action__SaveMap_FeedbackMessage.
typedef struct isaac_ros_visual_slam_interfaces__action__SaveMap_FeedbackMessage__Sequence
{
  isaac_ros_visual_slam_interfaces__action__SaveMap_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} isaac_ros_visual_slam_interfaces__action__SaveMap_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__SAVE_MAP__STRUCT_H_
