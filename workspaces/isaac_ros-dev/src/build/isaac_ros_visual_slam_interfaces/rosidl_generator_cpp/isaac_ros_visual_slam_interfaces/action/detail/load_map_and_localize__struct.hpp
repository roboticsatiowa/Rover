// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from isaac_ros_visual_slam_interfaces:action/LoadMapAndLocalize.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__LOAD_MAP_AND_LOCALIZE__STRUCT_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__LOAD_MAP_AND_LOCALIZE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'localize_near_point'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_Goal_
{
  using Type = LoadMapAndLocalize_Goal_<ContainerAllocator>;

  explicit LoadMapAndLocalize_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : localize_near_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->map_url = "";
    }
  }

  explicit LoadMapAndLocalize_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : map_url(_alloc),
    localize_near_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->map_url = "";
    }
  }

  // field types and members
  using _map_url_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _map_url_type map_url;
  using _localize_near_point_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _localize_near_point_type localize_near_point;

  // setters for named parameter idiom
  Type & set__map_url(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->map_url = _arg;
    return *this;
  }
  Type & set__localize_near_point(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->localize_near_point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_Goal_ & other) const
  {
    if (this->map_url != other.map_url) {
      return false;
    }
    if (this->localize_near_point != other.localize_near_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_Goal_

// alias to use template instance with default allocator
using LoadMapAndLocalize_Goal =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_Result_
{
  using Type = LoadMapAndLocalize_Result_<ContainerAllocator>;

  explicit LoadMapAndLocalize_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit LoadMapAndLocalize_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
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
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_Result_

// alias to use template instance with default allocator
using LoadMapAndLocalize_Result =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_Feedback_
{
  using Type = LoadMapAndLocalize_Feedback_<ContainerAllocator>;

  explicit LoadMapAndLocalize_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->progress = 0l;
    }
  }

  explicit LoadMapAndLocalize_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->progress = 0l;
    }
  }

  // field types and members
  using _progress_type =
    int32_t;
  _progress_type progress;

  // setters for named parameter idiom
  Type & set__progress(
    const int32_t & _arg)
  {
    this->progress = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_Feedback_ & other) const
  {
    if (this->progress != other.progress) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_Feedback_

// alias to use template instance with default allocator
using LoadMapAndLocalize_Feedback =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_SendGoal_Request_
{
  using Type = LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>;

  explicit LoadMapAndLocalize_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit LoadMapAndLocalize_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_SendGoal_Request_

// alias to use template instance with default allocator
using LoadMapAndLocalize_SendGoal_Request =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_SendGoal_Response_
{
  using Type = LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>;

  explicit LoadMapAndLocalize_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit LoadMapAndLocalize_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_SendGoal_Response_

// alias to use template instance with default allocator
using LoadMapAndLocalize_SendGoal_Response =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

struct LoadMapAndLocalize_SendGoal
{
  using Request = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request;
  using Response = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response;
};

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_GetResult_Request_
{
  using Type = LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>;

  explicit LoadMapAndLocalize_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit LoadMapAndLocalize_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_GetResult_Request_

// alias to use template instance with default allocator
using LoadMapAndLocalize_GetResult_Request =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_GetResult_Response_
{
  using Type = LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>;

  explicit LoadMapAndLocalize_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit LoadMapAndLocalize_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_GetResult_Response_

// alias to use template instance with default allocator
using LoadMapAndLocalize_GetResult_Response =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

struct LoadMapAndLocalize_GetResult
{
  using Request = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request;
  using Response = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response;
};

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage __declspec(deprecated)
#endif

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct LoadMapAndLocalize_FeedbackMessage_
{
  using Type = LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>;

  explicit LoadMapAndLocalize_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit LoadMapAndLocalize_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage
    std::shared_ptr<isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMapAndLocalize_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMapAndLocalize_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMapAndLocalize_FeedbackMessage_

// alias to use template instance with default allocator
using LoadMapAndLocalize_FeedbackMessage =
  isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

struct LoadMapAndLocalize
{
  /// The goal message defined in the action definition.
  using Goal = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal;
  /// The result message defined in the action definition.
  using Result = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result;
  /// The feedback message defined in the action definition.
  using Feedback = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct LoadMapAndLocalize LoadMapAndLocalize;

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__LOAD_MAP_AND_LOCALIZE__STRUCT_HPP_
