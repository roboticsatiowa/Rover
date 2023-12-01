// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/SetOdometryPose.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__STRUCT_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetOdometryPose_Request_
{
  using Type = SetOdometryPose_Request_<ContainerAllocator>;

  explicit SetOdometryPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    (void)_init;
  }

  explicit SetOdometryPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetOdometryPose_Request_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetOdometryPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetOdometryPose_Request_

// alias to use template instance with default allocator
using SetOdometryPose_Request =
  isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces


#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetOdometryPose_Response_
{
  using Type = SetOdometryPose_Response_<ContainerAllocator>;

  explicit SetOdometryPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetOdometryPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__srv__SetOdometryPose_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetOdometryPose_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetOdometryPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetOdometryPose_Response_

// alias to use template instance with default allocator
using SetOdometryPose_Response =
  isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

struct SetOdometryPose
{
  using Request = isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request;
  using Response = isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response;
};

}  // namespace srv

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__STRUCT_HPP_
