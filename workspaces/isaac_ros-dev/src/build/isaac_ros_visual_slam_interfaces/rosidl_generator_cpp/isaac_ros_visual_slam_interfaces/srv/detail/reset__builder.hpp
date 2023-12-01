// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_visual_slam_interfaces:srv/Reset.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__BUILDER_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_visual_slam_interfaces/srv/detail/reset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::srv::Reset_Request>()
{
  return ::isaac_ros_visual_slam_interfaces::srv::Reset_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace srv
{

namespace builder
{

class Init_Reset_Response_success
{
public:
  Init_Reset_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::srv::Reset_Response success(::isaac_ros_visual_slam_interfaces::srv::Reset_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::srv::Reset_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::srv::Reset_Response>()
{
  return isaac_ros_visual_slam_interfaces::srv::builder::Init_Reset_Response_success();
}

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__SRV__DETAIL__RESET__BUILDER_HPP_
