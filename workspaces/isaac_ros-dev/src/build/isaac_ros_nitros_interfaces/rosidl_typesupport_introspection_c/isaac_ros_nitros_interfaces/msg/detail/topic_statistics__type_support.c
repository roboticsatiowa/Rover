// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__rosidl_typesupport_introspection_c.h"
#include "isaac_ros_nitros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__functions.h"
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__struct.h"


// Include directives for member types
// Member `node_name`
// Member `node_namespace`
// Member `topic_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  isaac_ros_nitros_interfaces__msg__TopicStatistics__init(message_memory);
}

void isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_fini_function(void * message_memory)
{
  isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_member_array[7] = {
  {
    "node_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, node_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_namespace",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, node_namespace),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "topic_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, topic_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_subscriber",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, is_subscriber),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_rate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, frame_rate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mean_abs_jitter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, mean_abs_jitter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_abs_jitter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_nitros_interfaces__msg__TopicStatistics, max_abs_jitter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_members = {
  "isaac_ros_nitros_interfaces__msg",  // message namespace
  "TopicStatistics",  // message name
  7,  // number of fields
  sizeof(isaac_ros_nitros_interfaces__msg__TopicStatistics),
  isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_member_array,  // message members
  isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_init_function,  // function to initialize message memory (memory has to be allocated)
  isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_type_support_handle = {
  0,
  &isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaac_ros_nitros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_nitros_interfaces, msg, TopicStatistics)() {
  if (!isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_type_support_handle.typesupport_identifier) {
    isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &isaac_ros_nitros_interfaces__msg__TopicStatistics__rosidl_typesupport_introspection_c__TopicStatistics_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
