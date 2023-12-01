// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/GetAllPoses.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__BUILDER_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_visual_slam_interfaces/srv/detail/get_all_poses__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetAllPoses_Request_max_count
{
public:
  Init_GetAllPoses_Request_max_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request max_count(::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request::_max_count_type arg)
  {
    msg_.max_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Request>()
{
  return isaac_ros_visual_slam_interfaces::srv::builder::Init_GetAllPoses_Request_max_count();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetAllPoses_Response_poses
{
public:
  explicit Init_GetAllPoses_Response_poses(::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response poses(::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response msg_;
};

class Init_GetAllPoses_Response_success
{
public:
  Init_GetAllPoses_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetAllPoses_Response_poses success(::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetAllPoses_Response_poses(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::srv::GetAllPoses_Response>()
{
  return isaac_ros_visual_slam_interfaces::srv::builder::Init_GetAllPoses_Response_success();
}

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__GET_ALL_POSES__BUILDER_HPP_
