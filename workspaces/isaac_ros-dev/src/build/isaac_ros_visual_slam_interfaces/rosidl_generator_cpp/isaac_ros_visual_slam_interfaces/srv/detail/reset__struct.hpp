// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/Reset.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__STRUCT_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Request __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Reset_Request_
{
  using Type = Reset_Request_<ContainerAllocator>;

  explicit Reset_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Reset_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Reset_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Reset_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Reset_Request_

// alias to use template instance with default allocator
using Reset_Request =
  isaac_ros_visual_slam_interfaces::srv::Reset_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces


#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Response __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Reset_Response_
{
  using Type = Reset_Response_<ContainerAllocator>;

  explicit Reset_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Reset_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__Reset_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::Reset_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Reset_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Reset_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Reset_Response_

// alias to use template instance with default allocator
using Reset_Response =
  isaac_ros_visual_slam_interfaces::srv::Reset_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

struct Reset
{
  using Request = isaac_ros_visual_slam_interfaces::srv::Reset_Request;
  using Response = isaac_ros_visual_slam_interfaces::srv::Reset_Response;
};

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__STRUCT_HPP_
