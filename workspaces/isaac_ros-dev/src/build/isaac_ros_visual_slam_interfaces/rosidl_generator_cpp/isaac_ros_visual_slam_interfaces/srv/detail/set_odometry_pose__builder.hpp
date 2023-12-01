// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/SetOdometryPose.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__BUILDER_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_visual_slam_interfaces/srv/detail/set_odometry_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetOdometryPose_Request_pose
{
public:
  Init_SetOdometryPose_Request_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request pose(::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Request>()
{
  return isaac_ros_visual_slam_interfaces::srv::builder::Init_SetOdometryPose_Request_pose();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetOdometryPose_Response_success
{
public:
  Init_SetOdometryPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response success(::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::srv::SetOdometryPose_Response>()
{
  return isaac_ros_visual_slam_interfaces::srv::builder::Init_SetOdometryPose_Response_success();
}

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__SET_ODOMETRY_POSE__BUILDER_HPP_
