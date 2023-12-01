// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__BUILDER_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_visual_slam_interfaces/msg/detail/visual_slam_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_visual_slam_interfaces
{

namespace msg
{

namespace builder
{

class Init_VisualSlamStatus_track_execution_time_max
{
public:
  explicit Init_VisualSlamStatus_track_execution_time_max(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus track_execution_time_max(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus::_track_execution_time_max_type arg)
  {
    msg_.track_execution_time_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus msg_;
};

class Init_VisualSlamStatus_track_execution_time_mean
{
public:
  explicit Init_VisualSlamStatus_track_execution_time_mean(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg)
  : msg_(msg)
  {}
  Init_VisualSlamStatus_track_execution_time_max track_execution_time_mean(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus::_track_execution_time_mean_type arg)
  {
    msg_.track_execution_time_mean = std::move(arg);
    return Init_VisualSlamStatus_track_execution_time_max(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus msg_;
};

class Init_VisualSlamStatus_track_execution_time
{
public:
  explicit Init_VisualSlamStatus_track_execution_time(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg)
  : msg_(msg)
  {}
  Init_VisualSlamStatus_track_execution_time_mean track_execution_time(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus::_track_execution_time_type arg)
  {
    msg_.track_execution_time = std::move(arg);
    return Init_VisualSlamStatus_track_execution_time_mean(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus msg_;
};

class Init_VisualSlamStatus_node_callback_execution_time
{
public:
  explicit Init_VisualSlamStatus_node_callback_execution_time(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg)
  : msg_(msg)
  {}
  Init_VisualSlamStatus_track_execution_time node_callback_execution_time(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus::_node_callback_execution_time_type arg)
  {
    msg_.node_callback_execution_time = std::move(arg);
    return Init_VisualSlamStatus_track_execution_time(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus msg_;
};

class Init_VisualSlamStatus_vo_state
{
public:
  explicit Init_VisualSlamStatus_vo_state(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus & msg)
  : msg_(msg)
  {}
  Init_VisualSlamStatus_node_callback_execution_time vo_state(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus::_vo_state_type arg)
  {
    msg_.vo_state = std::move(arg);
    return Init_VisualSlamStatus_node_callback_execution_time(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus msg_;
};

class Init_VisualSlamStatus_header
{
public:
  Init_VisualSlamStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisualSlamStatus_vo_state header(::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VisualSlamStatus_vo_state(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::msg::VisualSlamStatus>()
{
  return isaac_ros_visual_slam_interfaces::msg::builder::Init_VisualSlamStatus_header();
}

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__MSG__DETAIL__VISUAL_SLAM_STATUS__BUILDER_HPP_
