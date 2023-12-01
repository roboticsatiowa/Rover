// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/GetAllPoses.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__TRAITS_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "isaac_ros_visual_slam_interfaces/srv/detail/get_all_poses__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetAllPoses_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: max_count
  {
    out << "max_count: ";
    rosidl_generator_traits::value_to_yaml(msg.max_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetAllPoses_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: max_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_count: ";
    rosidl_generator_traits::value_to_yaml(msg.max_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetAllPoses_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use isaac_ros_visual_slam_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaac_ros_visual_slam_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaac_ros_visual_slam_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request & msg)
{
  return isaac_ros_visual_slam_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>()
{
  return "isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request";
}

template<>
inline const char * name<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>()
{
  return "isaac_ros_visual_slam_interfaces/srv/GetAllPoses_Request";
}

template<>
struct has_fixed_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetAllPoses_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: poses
  {
    if (msg.poses.size() == 0) {
      out << "poses: []";
    } else {
      out << "poses: [";
      size_t pending_items = msg.poses.size();
      for (auto item : msg.poses) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetAllPoses_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: poses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses.size() == 0) {
      out << "poses: []\n";
    } else {
      out << "poses:\n";
      for (auto item : msg.poses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetAllPoses_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use isaac_ros_visual_slam_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  isaac_ros_visual_slam_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use isaac_ros_visual_slam_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response & msg)
{
  return isaac_ros_visual_slam_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>()
{
  return "isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response";
}

template<>
inline const char * name<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>()
{
  return "isaac_ros_visual_slam_interfaces/srv/GetAllPoses_Response";
}

template<>
struct has_fixed_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<isaac_ros_visual_slam_interfaces::srv::GetAllPoses>()
{
  return "isaac_ros_visual_slam_interfaces::srv::GetAllPoses";
}

template<>
inline const char * name<isaac_ros_visual_slam_interfaces::srv::GetAllPoses>()
{
  return "isaac_ros_visual_slam_interfaces/srv/GetAllPoses";
}

template<>
struct has_fixed_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses>
  : std::integral_constant<
    bool,
    has_fixed_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>::value &&
    has_fixed_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>::value
  >
{
};

template<>
struct has_bounded_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses>
  : std::integral_constant<
    bool,
    has_bounded_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>::value &&
    has_bounded_size<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>::value
  >
{
};

template<>
struct is_service<isaac_ros_visual_slam_interfaces::srv::GetAllPoses>
  : std::true_type
{
};

template<>
struct is_service_request<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>
  : std::true_type
{
};

template<>
struct is_service_response<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__TRAITS_HPP_
