// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__TRAITS_HPP_
#define ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaac_ros_nitros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TopicStatistics & msg,
  std::ostream & out)
{
  out << "{";
  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << ", ";
  }

  // member: node_namespace
  {
    out << "node_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.node_namespace, out);
    out << ", ";
  }

  // member: topic_name
  {
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
    out << ", ";
  }

  // member: is_subscriber
  {
    out << "is_subscriber: ";
    rosidl_generator_traits::value_to_yaml(msg.is_subscriber, out);
    out << ", ";
  }

  // member: frame_rate
  {
    out << "frame_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_rate, out);
    out << ", ";
  }

  // member: mean_abs_jitter
  {
    out << "mean_abs_jitter: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_abs_jitter, out);
    out << ", ";
  }

  // member: max_abs_jitter
  {
    out << "max_abs_jitter: ";
    rosidl_generator_traits::value_to_yaml(msg.max_abs_jitter, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TopicStatistics & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }

  // member: node_namespace
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.node_namespace, out);
    out << "\n";
  }

  // member: topic_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
    out << "\n";
  }

  // member: is_subscriber
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_subscriber: ";
    rosidl_generator_traits::value_to_yaml(msg.is_subscriber, out);
    out << "\n";
  }

  // member: frame_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_rate, out);
    out << "\n";
  }

  // member: mean_abs_jitter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_abs_jitter: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_abs_jitter, out);
    out << "\n";
  }

  // member: max_abs_jitter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_abs_jitter: ";
    rosidl_generator_traits::value_to_yaml(msg.max_abs_jitter, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TopicStatistics & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace isaac_ros_nitros_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use isaac_ros_nitros_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaac_ros_nitros_interfaces::msg::TopicStatistics & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaac_ros_nitros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaac_ros_nitros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
{
  return isaac_ros_nitros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<isaac_ros_nitros_interfaces::msg::TopicStatistics>()
{
  return "isaac_ros_nitros_interfaces::msg::TopicStatistics";
}

template<>
inline const char * name<isaac_ros_nitros_interfaces::msg::TopicStatistics>()
{
  return "isaac_ros_nitros_interfaces/msg/TopicStatistics";
}

template<>
struct has_fixed_size<isaac_ros_nitros_interfaces::msg::TopicStatistics>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaac_ros_nitros_interfaces::msg::TopicStatistics>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaac_ros_nitros_interfaces::msg::TopicStatistics>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__TRAITS_HPP_
