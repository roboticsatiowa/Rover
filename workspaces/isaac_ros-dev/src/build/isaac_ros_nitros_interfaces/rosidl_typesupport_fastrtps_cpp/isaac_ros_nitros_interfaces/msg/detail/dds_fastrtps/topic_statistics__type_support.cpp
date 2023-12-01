// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__rosidl_typesupport_fastrtps_cpp.hpp"
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__struct.hpp"

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

namespace isaac_ros_nitros_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_nitros_interfaces
cdr_serialize(
  const isaac_ros_nitros_interfaces::msg::TopicStatistics & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: node_name
  cdr << ros_message.node_name;
  // Member: node_namespace
  cdr << ros_message.node_namespace;
  // Member: topic_name
  cdr << ros_message.topic_name;
  // Member: is_subscriber
  cdr << (ros_message.is_subscriber ? true : false);
  // Member: frame_rate
  cdr << ros_message.frame_rate;
  // Member: mean_abs_jitter
  cdr << ros_message.mean_abs_jitter;
  // Member: max_abs_jitter
  cdr << ros_message.max_abs_jitter;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_nitros_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  isaac_ros_nitros_interfaces::msg::TopicStatistics & ros_message)
{
  // Member: node_name
  cdr >> ros_message.node_name;

  // Member: node_namespace
  cdr >> ros_message.node_namespace;

  // Member: topic_name
  cdr >> ros_message.topic_name;

  // Member: is_subscriber
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_subscriber = tmp ? true : false;
  }

  // Member: frame_rate
  cdr >> ros_message.frame_rate;

  // Member: mean_abs_jitter
  cdr >> ros_message.mean_abs_jitter;

  // Member: max_abs_jitter
  cdr >> ros_message.max_abs_jitter;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_nitros_interfaces
get_serialized_size(
  const isaac_ros_nitros_interfaces::msg::TopicStatistics & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: node_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.node_name.size() + 1);
  // Member: node_namespace
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.node_namespace.size() + 1);
  // Member: topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.topic_name.size() + 1);
  // Member: is_subscriber
  {
    size_t item_size = sizeof(ros_message.is_subscriber);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: frame_rate
  {
    size_t item_size = sizeof(ros_message.frame_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mean_abs_jitter
  {
    size_t item_size = sizeof(ros_message.mean_abs_jitter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_abs_jitter
  {
    size_t item_size = sizeof(ros_message.max_abs_jitter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_isaac_ros_nitros_interfaces
max_serialized_size_TopicStatistics(
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


  // Member: node_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: node_namespace
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: topic_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: is_subscriber
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: frame_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: mean_abs_jitter
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_abs_jitter
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TopicStatistics__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const isaac_ros_nitros_interfaces::msg::TopicStatistics *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TopicStatistics__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<isaac_ros_nitros_interfaces::msg::TopicStatistics *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TopicStatistics__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const isaac_ros_nitros_interfaces::msg::TopicStatistics *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TopicStatistics__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TopicStatistics(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TopicStatistics__callbacks = {
  "isaac_ros_nitros_interfaces::msg",
  "TopicStatistics",
  _TopicStatistics__cdr_serialize,
  _TopicStatistics__cdr_deserialize,
  _TopicStatistics__get_serialized_size,
  _TopicStatistics__max_serialized_size
};

static rosidl_message_type_support_t _TopicStatistics__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TopicStatistics__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace isaac_ros_nitros_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_isaac_ros_nitros_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<isaac_ros_nitros_interfaces::msg::TopicStatistics>()
{
  return &isaac_ros_nitros_interfaces::msg::typesupport_fastrtps_cpp::_TopicStatistics__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, isaac_ros_nitros_interfaces, msg, TopicStatistics)() {
  return &isaac_ros_nitros_interfaces::msg::typesupport_fastrtps_cpp::_TopicStatistics__handle;
}

#ifdef __cplusplus
}
#endif
