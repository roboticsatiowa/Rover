// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_visual_slam_interfaces:action/SaveMap.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__SAVE_MAP__BUILDER_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__SAVE_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_visual_slam_interfaces/action/detail/save_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_Goal_map_url
{
public:
  Init_SaveMap_Goal_map_url()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Goal map_url(::isaac_ros_visual_slam_interfaces::action::SaveMap_Goal::_map_url_type arg)
  {
    msg_.map_url = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_Goal>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_Goal_map_url();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_Result_error
{
public:
  explicit Init_SaveMap_Result_error(::isaac_ros_visual_slam_interfaces::action::SaveMap_Result & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Result error(::isaac_ros_visual_slam_interfaces::action::SaveMap_Result::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Result msg_;
};

class Init_SaveMap_Result_success
{
public:
  Init_SaveMap_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveMap_Result_error success(::isaac_ros_visual_slam_interfaces::action::SaveMap_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SaveMap_Result_error(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_Result>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_Result_success();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_Feedback_progress
{
public:
  Init_SaveMap_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Feedback progress(::isaac_ros_visual_slam_interfaces::action::SaveMap_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_Feedback>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_Feedback_progress();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_SendGoal_Request_goal
{
public:
  explicit Init_SaveMap_SendGoal_Request_goal(::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request goal(::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request msg_;
};

class Init_SaveMap_SendGoal_Request_goal_id
{
public:
  Init_SaveMap_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveMap_SendGoal_Request_goal goal_id(::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SaveMap_SendGoal_Request_goal(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Request>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_SendGoal_Request_goal_id();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_SendGoal_Response_stamp
{
public:
  explicit Init_SaveMap_SendGoal_Response_stamp(::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response stamp(::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response msg_;
};

class Init_SaveMap_SendGoal_Response_accepted
{
public:
  Init_SaveMap_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveMap_SendGoal_Response_stamp accepted(::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SaveMap_SendGoal_Response_stamp(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_SendGoal_Response>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_SendGoal_Response_accepted();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_GetResult_Request_goal_id
{
public:
  Init_SaveMap_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Request goal_id(::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Request>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_GetResult_Request_goal_id();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_GetResult_Response_result
{
public:
  explicit Init_SaveMap_GetResult_Response_result(::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response result(::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response msg_;
};

class Init_SaveMap_GetResult_Response_status
{
public:
  Init_SaveMap_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveMap_GetResult_Response_result status(::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SaveMap_GetResult_Response_result(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_GetResult_Response>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_GetResult_Response_status();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_SaveMap_FeedbackMessage_feedback
{
public:
  explicit Init_SaveMap_FeedbackMessage_feedback(::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage feedback(::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage msg_;
};

class Init_SaveMap_FeedbackMessage_goal_id
{
public:
  Init_SaveMap_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveMap_FeedbackMessage_feedback goal_id(::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SaveMap_FeedbackMessage_feedback(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::SaveMap_FeedbackMessage>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_SaveMap_FeedbackMessage_goal_id();
}

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__SAVE_MAP__BUILDER_HPP_
