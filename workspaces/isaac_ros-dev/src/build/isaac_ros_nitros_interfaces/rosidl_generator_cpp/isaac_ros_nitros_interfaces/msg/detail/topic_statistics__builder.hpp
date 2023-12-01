// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__BUILDER_HPP_
#define ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_nitros_interfaces
{

namespace msg
{

namespace builder
{

class Init_TopicStatistics_max_abs_jitter
{
public:
  explicit Init_TopicStatistics_max_abs_jitter(::isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
  : msg_(msg)
  {}
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics max_abs_jitter(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_max_abs_jitter_type arg)
  {
    msg_.max_abs_jitter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

class Init_TopicStatistics_mean_abs_jitter
{
public:
  explicit Init_TopicStatistics_mean_abs_jitter(::isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
  : msg_(msg)
  {}
  Init_TopicStatistics_max_abs_jitter mean_abs_jitter(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_mean_abs_jitter_type arg)
  {
    msg_.mean_abs_jitter = std::move(arg);
    return Init_TopicStatistics_max_abs_jitter(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

class Init_TopicStatistics_frame_rate
{
public:
  explicit Init_TopicStatistics_frame_rate(::isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
  : msg_(msg)
  {}
  Init_TopicStatistics_mean_abs_jitter frame_rate(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_frame_rate_type arg)
  {
    msg_.frame_rate = std::move(arg);
    return Init_TopicStatistics_mean_abs_jitter(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

class Init_TopicStatistics_is_subscriber
{
public:
  explicit Init_TopicStatistics_is_subscriber(::isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
  : msg_(msg)
  {}
  Init_TopicStatistics_frame_rate is_subscriber(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_is_subscriber_type arg)
  {
    msg_.is_subscriber = std::move(arg);
    return Init_TopicStatistics_frame_rate(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

class Init_TopicStatistics_topic_name
{
public:
  explicit Init_TopicStatistics_topic_name(::isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
  : msg_(msg)
  {}
  Init_TopicStatistics_is_subscriber topic_name(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_topic_name_type arg)
  {
    msg_.topic_name = std::move(arg);
    return Init_TopicStatistics_is_subscriber(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

class Init_TopicStatistics_node_namespace
{
public:
  explicit Init_TopicStatistics_node_namespace(::isaac_ros_nitros_interfaces::msg::TopicStatistics & msg)
  : msg_(msg)
  {}
  Init_TopicStatistics_topic_name node_namespace(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_node_namespace_type arg)
  {
    msg_.node_namespace = std::move(arg);
    return Init_TopicStatistics_topic_name(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

class Init_TopicStatistics_node_name
{
public:
  Init_TopicStatistics_node_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TopicStatistics_node_namespace node_name(::isaac_ros_nitros_interfaces::msg::TopicStatistics::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_TopicStatistics_node_namespace(msg_);
  }

private:
  ::isaac_ros_nitros_interfaces::msg::TopicStatistics msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_nitros_interfaces::msg::TopicStatistics>()
{
  return isaac_ros_nitros_interfaces::msg::builder::Init_TopicStatistics_node_name();
}

}  // namespace isaac_ros_nitros_interfaces

#endif  // ISAAC_ROS_NITROS_INTERFACES__MSG__DETAIL__TOPIC_STATISTICS__BUILDER_HPP_
