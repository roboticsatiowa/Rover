// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__STRUCT_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VisualSlamStatus_
{
  using Type = VisualSlamStatus_<ContainerAllocator>;

  explicit VisualSlamStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vo_state = 0;
      this->node_callback_execution_time = 0.0;
      this->track_execution_time = 0.0;
      this->track_execution_time_mean = 0.0;
      this->track_execution_time_max = 0.0;
    }
  }

  explicit VisualSlamStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vo_state = 0;
      this->node_callback_execution_time = 0.0;
      this->track_execution_time = 0.0;
      this->track_execution_time_mean = 0.0;
      this->track_execution_time_max = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _vo_state_type =
    uint8_t;
  _vo_state_type vo_state;
  using _node_callback_execution_time_type =
    double;
  _node_callback_execution_time_type node_callback_execution_time;
  using _track_execution_time_type =
    double;
  _track_execution_time_type track_execution_time;
  using _track_execution_time_mean_type =
    double;
  _track_execution_time_mean_type track_execution_time_mean;
  using _track_execution_time_max_type =
    double;
  _track_execution_time_max_type track_execution_time_max;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__vo_state(
    const uint8_t & _arg)
  {
    this->vo_state = _arg;
    return *this;
  }
  Type & set__node_callback_execution_time(
    const double & _arg)
  {
    this->node_callback_execution_time = _arg;
    return *this;
  }
  Type & set__track_execution_time(
    const double & _arg)
  {
    this->track_execution_time = _arg;
    return *this;
  }
  Type & set__track_execution_time_mean(
    const double & _arg)
  {
    this->track_execution_time_mean = _arg;
    return *this;
  }
  Type & set__track_execution_time_max(
    const double & _arg)
  {
    this->track_execution_time_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus
    std::shared_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus
    std::shared_ptr<isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisualSlamStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->vo_state != other.vo_state) {
      return false;
    }
    if (this->node_callback_execution_time != other.node_callback_execution_time) {
      return false;
    }
    if (this->track_execution_time != other.track_execution_time) {
      return false;
    }
    if (this->track_execution_time_mean != other.track_execution_time_mean) {
      return false;
    }
    if (this->track_execution_time_max != other.track_execution_time_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisualSlamStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisualSlamStatus_

// alias to use template instance with default allocator
using VisualSlamStatus =
  isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__STRUCT_HPP_
