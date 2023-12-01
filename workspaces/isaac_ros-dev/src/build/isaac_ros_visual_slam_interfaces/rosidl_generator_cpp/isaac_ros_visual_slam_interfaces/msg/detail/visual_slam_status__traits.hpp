// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__TRAITS_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaac_ros_visual_slam_interfaces/msg/detail/visual_slam_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VisualSlamStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: vo_state
  {
    out << "vo_state: ";
    rosidl_generator_traits::value_to_yaml(msg.vo_state, out);
    out << ", ";
  }

  // member: node_callback_execution_time
  {
    out << "node_callback_execution_time: ";
    rosidl_generator_traits::value_to_yaml(msg.node_callback_execution_time, out);
    out << ", ";
  }

  // member: track_execution_time
  {
    out << "track_execution_time: ";
    rosidl_generator_traits::value_to_yaml(msg.track_execution_time, out);
    out << ", ";
  }

  // member: track_execution_time_mean
  {
    out << "track_execution_time_mean: ";
    rosidl_generator_traits::value_to_yaml(msg.track_execution_time_mean, out);
    out << ", ";
  }

  // member: track_execution_time_max
  {
    out << "track_execution_time_max: ";
    rosidl_generator_traits::value_to_yaml(msg.track_execution_time_max, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisualSlamStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: vo_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vo_state: ";
    rosidl_generator_traits::value_to_yaml(msg.vo_state, out);
    out << "\n";
  }

  // member: node_callback_execution_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_callback_execution_time: ";
    rosidl_generator_traits::value_to_yaml(msg.node_callback_execution_time, out);
    out << "\n";
  }

  // member: track_execution_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_execution_time: ";
    rosidl_generator_traits::value_to_yaml(msg.track_execution_time, out);
    out << "\n";
  }

  // member: track_execution_time_mean
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_execution_time_mean: ";
    rosidl_generator_traits::value_to_yaml(msg.track_execution_time_mean, out);
    out << "\n";
  }

  // member: track_execution_time_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_execution_time_max: ";
    rosidl_generator_traits::value_to_yaml(msg.track_execution_time_max, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisualSlamStatus & msg, bool use_flow_style = false)
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

}  // namespace isaac_ros_visual_slam_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use isaac_ros_visual_slam_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaac_ros_visual_slam_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaac_ros_visual_slam_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg)
{
  return isaac_ros_visual_slam_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus>()
{
  return "isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus";
}

template<>
inline const char * name<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus>()
{
  return "isaac_ros_visual_slam_interfaces/msg/VisualSlamStatus";
}

template<>
struct has_fixed_size<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__TRAITS_HPP_
