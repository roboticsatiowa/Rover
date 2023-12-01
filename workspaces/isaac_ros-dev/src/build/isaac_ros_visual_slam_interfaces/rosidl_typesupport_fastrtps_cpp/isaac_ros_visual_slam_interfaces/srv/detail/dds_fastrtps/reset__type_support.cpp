// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/Reset.idl
// generated code does not contain a copyright notice
#include "isaac_ros_visual_slam_interfaces/srv/detail/reset__rosidl_typesupport_fastrtps_cpp.hpp"
#include "isaac_ros_visual_slam_interfaces/srv/detail/reset__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
cdr_serialize(
  const isaac_ros_visual_slam_interfaces::srv::Reset_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  isaac_ros_visual_slam_interfaces::srv::Reset_Request & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
get_serialized_size(
  const isaac_ros_visual_slam_interfaces::srv::Reset_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
max_serialized_size_Reset_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Reset_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const isaac_ros_visual_slam_interfaces::srv::Reset_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Reset_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<isaac_ros_visual_slam_interfaces::srv::Reset_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Reset_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const isaac_ros_visual_slam_interfaces::srv::Reset_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Reset_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Reset_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Reset_Request__callbacks = {
  "isaac_ros_visual_slam_interfaces::srv",
  "Reset_Request",
  _Reset_Request__cdr_serialize,
  _Reset_Request__cdr_deserialize,
  _Reset_Request__get_serialized_size,
  _Reset_Request__max_serialized_size
};

static rosidl_message_type_support_t _Reset_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Reset_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_isaac_ros_visual_slam_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::srv::Reset_Request>()
{
  return &isaac_ros_visual_slam_interfaces::srv::typesupport_fastrtps_cpp::_Reset_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, isaac_ros_visual_slam_interfaces, srv, Reset_Request)() {
  return &isaac_ros_visual_slam_interfaces::srv::typesupport_fastrtps_cpp::_Reset_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
cdr_serialize(
  const isaac_ros_visual_slam_interfaces::srv::Reset_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  isaac_ros_visual_slam_interfaces::srv::Reset_Response & ros_message)
{
  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
get_serialized_size(
  const isaac_ros_visual_slam_interfaces::srv::Reset_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_visual_slam_interfaces
max_serialized_size_Reset_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Reset_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const isaac_ros_visual_slam_interfaces::srv::Reset_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Reset_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<isaac_ros_visual_slam_interfaces::srv::Reset_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Reset_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const isaac_ros_visual_slam_interfaces::srv::Reset_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Reset_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Reset_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Reset_Response__callbacks = {
  "isaac_ros_visual_slam_interfaces::srv",
  "Reset_Response",
  _Reset_Response__cdr_serialize,
  _Reset_Response__cdr_deserialize,
  _Reset_Response__get_serialized_size,
  _Reset_Response__max_serialized_size
};

static rosidl_message_type_support_t _Reset_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Reset_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_isaac_ros_visual_slam_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_visual_slam_interfaces::srv::Reset_Response>()
{
  return &isaac_ros_visual_slam_interfaces::srv::typesupport_fastrtps_cpp::_Reset_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, isaac_ros_visual_slam_interfaces, srv, Reset_Response)() {
  return &isaac_ros_visual_slam_interfaces::srv::typesupport_fastrtps_cpp::_Reset_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _Reset__callbacks = {
  "isaac_ros_visual_slam_interfaces::srv",
  "Reset",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, isaac_ros_visual_slam_interfaces, srv, Reset_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, isaac_ros_visual_slam_interfaces, srv, Reset_Response)(),
};

static rosidl_service_type_support_t _Reset__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Reset__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_isaac_ros_visual_slam_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<isaac_ros_visual_slam_interfaces::srv::Reset>()
{
  return &isaac_ros_visual_slam_interfaces::srv::typesupport_fastrtps_cpp::_Reset__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, isaac_ros_visual_slam_interfaces, srv, Reset)() {
  return &isaac_ros_visual_slam_interfaces::srv::typesupport_fastrtps_cpp::_Reset__handle;
}

#ifdef __cplusplus
}
#endif
