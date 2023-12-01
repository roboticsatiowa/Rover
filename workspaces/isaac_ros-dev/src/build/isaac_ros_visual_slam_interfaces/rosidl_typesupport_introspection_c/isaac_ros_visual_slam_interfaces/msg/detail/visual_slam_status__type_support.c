// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "isaac_ros_visual_slam_interfaces/msg/detail/visual_slam_status__rosidl_typesupport_introspection_c.h"
#include "isaac_ros_visual_slam_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "isaac_ros_visual_slam_interfaces/msg/detail/visual_slam_status__functions.h"
#include "isaac_ros_visual_slam_interfaces/msg/detail/visual_slam_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__init(message_memory);
}

void isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_fini_function(void * message_memory)
{
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vo_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus, vo_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_callback_execution_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus, node_callback_execution_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "track_execution_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus, track_execution_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "track_execution_time_mean",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus, track_execution_time_mean),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "track_execution_time_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus, track_execution_time_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_members = {
  "isaac_ros_visual_slam_interfaces__msg",  // message namespace
  "VisualSlamStatus",  // message name
  6,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus),
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_member_array,  // message members
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_type_support_handle = {
  0,
  &isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_isaac_ros_visual_slam_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, msg, VisualSlamStatus)() {
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_type_support_handle.typesupport_identifier) {
    isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__rosidl_typesupport_introspection_c__VisualSlamStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
