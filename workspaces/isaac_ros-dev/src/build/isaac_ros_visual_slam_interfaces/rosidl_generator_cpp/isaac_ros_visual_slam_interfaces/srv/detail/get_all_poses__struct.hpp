// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/GetAllPoses.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__STRUCT_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetAllPoses_Request_
{
  using Type = GetAllPoses_Request_<ContainerAllocator>;

  explicit GetAllPoses_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_count = 0l;
    }
  }

  explicit GetAllPoses_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_count = 0l;
    }
  }

  // field types and members
  using _max_count_type =
    int32_t;
  _max_count_type max_count;

  // setters for named parameter idiom
  Type & set__max_count(
    const int32_t & _arg)
  {
    this->max_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetAllPoses_Request_ & other) const
  {
    if (this->max_count != other.max_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetAllPoses_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetAllPoses_Request_

// alias to use template instance with default allocator
using GetAllPoses_Request =
  isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetAllPoses_Response_
{
  using Type = GetAllPoses_Response_<ContainerAllocator>;

  explicit GetAllPoses_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit GetAllPoses_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  using _poses_type =
    std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>>;
  _poses_type poses;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__poses(
    const std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>> & _arg)
  {
    this->poses = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__GetAllPoses_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetAllPoses_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->poses != other.poses) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetAllPoses_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetAllPoses_Response_

// alias to use template instance with default allocator
using GetAllPoses_Response =
  isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

struct GetAllPoses
{
  using Request = isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request;
  using Response = isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response;
};

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__STRUCT_HPP_
