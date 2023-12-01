// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from isaac_ros_visual_slam_interfaces:action/LoadMapAndLocalize.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal(_init);
}

void LoadMapAndLocalize_Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal *>(message_memory);
  typed_message->~LoadMapAndLocalize_Goal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_Goal_message_member_array[2] = {
  {
    "map_url",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal, map_url),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "localize_near_point",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal, localize_near_point),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_Goal_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_Goal",  // message name
  2,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal),
  LoadMapAndLocalize_Goal_message_member_array,  // message members
  LoadMapAndLocalize_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_Goal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Goal)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result(_init);
}

void LoadMapAndLocalize_Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result *>(message_memory);
  typed_message->~LoadMapAndLocalize_Result();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_Result_message_member_array[2] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_Result_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_Result",  // message name
  2,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result),
  LoadMapAndLocalize_Result_message_member_array,  // message members
  LoadMapAndLocalize_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_Result_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Result)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_Feedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback(_init);
}

void LoadMapAndLocalize_Feedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback *>(message_memory);
  typed_message->~LoadMapAndLocalize_Feedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_Feedback_message_member_array[1] = {
  {
    "progress",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback, progress),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_Feedback_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_Feedback",  // message name
  1,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback),
  LoadMapAndLocalize_Feedback_message_member_array,  // message members
  LoadMapAndLocalize_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_Feedback_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_Feedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Feedback)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_SendGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request(_init);
}

void LoadMapAndLocalize_SendGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request *>(message_memory);
  typed_message->~LoadMapAndLocalize_SendGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "goal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request, goal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_SendGoal_Request_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request),
  LoadMapAndLocalize_SendGoal_Request_message_member_array,  // message members
  LoadMapAndLocalize_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_SendGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Request)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_SendGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response(_init);
}

void LoadMapAndLocalize_SendGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response *>(message_memory);
  typed_message->~LoadMapAndLocalize_SendGoal_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response, accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_SendGoal_Response_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response),
  LoadMapAndLocalize_SendGoal_Response_message_member_array,  // message members
  LoadMapAndLocalize_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_SendGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Response)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers LoadMapAndLocalize_SendGoal_service_members = {
  "isaac_ros_visual_slam_interfaces::action",  // service namespace
  "LoadMapAndLocalize_SendGoal",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t LoadMapAndLocalize_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_SendGoal_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_GetResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request(_init);
}

void LoadMapAndLocalize_GetResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request *>(message_memory);
  typed_message->~LoadMapAndLocalize_GetResult_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_GetResult_Request_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request),
  LoadMapAndLocalize_GetResult_Request_message_member_array,  // message members
  LoadMapAndLocalize_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_GetResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Request)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_GetResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response(_init);
}

void LoadMapAndLocalize_GetResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response *>(message_memory);
  typed_message->~LoadMapAndLocalize_GetResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_GetResult_Response_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response),
  LoadMapAndLocalize_GetResult_Response_message_member_array,  // message members
  LoadMapAndLocalize_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_GetResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Response)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers LoadMapAndLocalize_GetResult_service_members = {
  "isaac_ros_visual_slam_interfaces::action",  // service namespace
  "LoadMapAndLocalize_GetResult",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t LoadMapAndLocalize_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_GetResult_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_GetResult_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void LoadMapAndLocalize_FeedbackMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage(_init);
}

void LoadMapAndLocalize_FeedbackMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage *>(message_memory);
  typed_message->~LoadMapAndLocalize_FeedbackMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LoadMapAndLocalize_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "feedback",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage, feedback),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LoadMapAndLocalize_FeedbackMessage_message_members = {
  "isaac_ros_visual_slam_interfaces::action",  // message namespace
  "LoadMapAndLocalize_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage),
  LoadMapAndLocalize_FeedbackMessage_message_member_array,  // message members
  LoadMapAndLocalize_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  LoadMapAndLocalize_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LoadMapAndLocalize_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LoadMapAndLocalize_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage>()
{
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_FeedbackMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_FeedbackMessage)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_introspection_cpp::LoadMapAndLocalize_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
