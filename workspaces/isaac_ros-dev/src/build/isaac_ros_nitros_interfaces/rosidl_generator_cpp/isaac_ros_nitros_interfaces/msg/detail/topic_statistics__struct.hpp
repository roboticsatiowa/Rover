// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__STRUCT_HPP_
#define ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaac_ros_nitros_interfaces__msg__TopicStatistics __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_nitros_interfaces__msg__TopicStatistics __declspec(deprecated)
#endif

namespace isaac_ros_nitros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TopicStatistics_
{
  using Type = TopicStatistics_<ContainerAllocator>;

  explicit TopicStatistics_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
      this->node_namespace = "";
      this->topic_name = "";
      this->is_subscriber = false;
      this->frame_rate = 0.0f;
      this->mean_abs_jitter = 0l;
      this->max_abs_jitter = 0l;
    }
  }

  explicit TopicStatistics_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : node_name(_alloc),
    node_namespace(_alloc),
    topic_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
      this->node_namespace = "";
      this->topic_name = "";
      this->is_subscriber = false;
      this->frame_rate = 0.0f;
      this->mean_abs_jitter = 0l;
      this->max_abs_jitter = 0l;
    }
  }

  // field types and members
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_name_type node_name;
  using _node_namespace_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_namespace_type node_namespace;
  using _topic_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _topic_name_type topic_name;
  using _is_subscriber_type =
    bool;
  _is_subscriber_type is_subscriber;
  using _frame_rate_type =
    float;
  _frame_rate_type frame_rate;
  using _mean_abs_jitter_type =
    int32_t;
  _mean_abs_jitter_type mean_abs_jitter;
  using _max_abs_jitter_type =
    int32_t;
  _max_abs_jitter_type max_abs_jitter;

  // setters for named parameter idiom
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }
  Type & set__node_namespace(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_namespace = _arg;
    return *this;
  }
  Type & set__topic_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->topic_name = _arg;
    return *this;
  }
  Type & set__is_subscriber(
    const bool & _arg)
  {
    this->is_subscriber = _arg;
    return *this;
  }
  Type & set__frame_rate(
    const float & _arg)
  {
    this->frame_rate = _arg;
    return *this;
  }
  Type & set__mean_abs_jitter(
    const int32_t & _arg)
  {
    this->mean_abs_jitter = _arg;
    return *this;
  }
  Type & set__max_abs_jitter(
    const int32_t & _arg)
  {
    this->max_abs_jitter = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_nitros_interfaces__msg__TopicStatistics
    std::shared_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_nitros_interfaces__msg__TopicStatistics
    std::shared_ptr<isaac_ros_nitros_interfaces::msg::TopicStatistics_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TopicStatistics_ & other) const
  {
    if (this->node_name != other.node_name) {
      return false;
    }
    if (this->node_namespace != other.node_namespace) {
      return false;
    }
    if (this->topic_name != other.topic_name) {
      return false;
    }
    if (this->is_subscriber != other.is_subscriber) {
      return false;
    }
    if (this->frame_rate != other.frame_rate) {
      return false;
    }
    if (this->mean_abs_jitter != other.mean_abs_jitter) {
      return false;
    }
    if (this->max_abs_jitter != other.max_abs_jitter) {
      return false;
    }
    return true;
  }
  bool operator!=(const TopicStatistics_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TopicStatistics_

// alias to use template instance with default allocator
using TopicStatistics =
  isaac_ros_nitros_interfaces::msg::TopicStatistics_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace isaac_ros_nitros_interfaces

#endif  // ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__STRUCT_HPP_
