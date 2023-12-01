// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from isaac_ros_visual_slam_interfaces:action/LoadMapAndLocalize.idl
// generated code does not contain a copyright notice

#ifndef ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__LOAD_MAP_AND_LOCALIZE__BUILDER_HPP_
#define ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__LOAD_MAP_AND_LOCALIZE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_Goal_localize_near_point
{
public:
  explicit Init_LoadMapAndLocalize_Goal_localize_near_point(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal localize_near_point(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal::_localize_near_point_type arg)
  {
    msg_.localize_near_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal msg_;
};

class Init_LoadMapAndLocalize_Goal_map_url
{
public:
  Init_LoadMapAndLocalize_Goal_map_url()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMapAndLocalize_Goal_localize_near_point map_url(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal::_map_url_type arg)
  {
    msg_.map_url = std::move(arg);
    return Init_LoadMapAndLocalize_Goal_localize_near_point(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Goal>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_Goal_map_url();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_Result_pose
{
public:
  explicit Init_LoadMapAndLocalize_Result_pose(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result pose(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result msg_;
};

class Init_LoadMapAndLocalize_Result_success
{
public:
  Init_LoadMapAndLocalize_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMapAndLocalize_Result_pose success(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_LoadMapAndLocalize_Result_pose(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Result>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_Result_success();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_Feedback_progress
{
public:
  Init_LoadMapAndLocalize_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback progress(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_Feedback>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_Feedback_progress();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_SendGoal_Request_goal
{
public:
  explicit Init_LoadMapAndLocalize_SendGoal_Request_goal(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request goal(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request msg_;
};

class Init_LoadMapAndLocalize_SendGoal_Request_goal_id
{
public:
  Init_LoadMapAndLocalize_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMapAndLocalize_SendGoal_Request_goal goal_id(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_LoadMapAndLocalize_SendGoal_Request_goal(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Request>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_SendGoal_Request_goal_id();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_SendGoal_Response_stamp
{
public:
  explicit Init_LoadMapAndLocalize_SendGoal_Response_stamp(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response stamp(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response msg_;
};

class Init_LoadMapAndLocalize_SendGoal_Response_accepted
{
public:
  Init_LoadMapAndLocalize_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMapAndLocalize_SendGoal_Response_stamp accepted(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_LoadMapAndLocalize_SendGoal_Response_stamp(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_SendGoal_Response>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_SendGoal_Response_accepted();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_GetResult_Request_goal_id
{
public:
  Init_LoadMapAndLocalize_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request goal_id(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Request>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_GetResult_Request_goal_id();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_GetResult_Response_result
{
public:
  explicit Init_LoadMapAndLocalize_GetResult_Response_result(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response result(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response msg_;
};

class Init_LoadMapAndLocalize_GetResult_Response_status
{
public:
  Init_LoadMapAndLocalize_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMapAndLocalize_GetResult_Response_result status(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_LoadMapAndLocalize_GetResult_Response_result(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_GetResult_Response>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_GetResult_Response_status();
}

}  // namespace isaac_ros_visual_slam_interfaces


namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace builder
{

class Init_LoadMapAndLocalize_FeedbackMessage_feedback
{
public:
  explicit Init_LoadMapAndLocalize_FeedbackMessage_feedback(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage feedback(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage msg_;
};

class Init_LoadMapAndLocalize_FeedbackMessage_goal_id
{
public:
  Init_LoadMapAndLocalize_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMapAndLocalize_FeedbackMessage_feedback goal_id(::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_LoadMapAndLocalize_FeedbackMessage_feedback(msg_);
  }

private:
  ::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::isaac_ros_visual_slam_interfaces::action::LoadMapAndLocalize_FeedbackMessage>()
{
  return isaac_ros_visual_slam_interfaces::action::builder::Init_LoadMapAndLocalize_FeedbackMessage_goal_id();
}

}  // namespace isaac_ros_visual_slam_interfaces

#endif  // ISAAC_ROS_VISUAL_SLAM_INTERFACES__ACTION__DETAIL__LOAD_MAP_AND_LOCALIZE__BUILDER_HPP_
