// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from camera_detection_interfaces:srv/DetectPipe.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__BUILDER_HPP_
#define CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "camera_detection_interfaces/srv/detail/detect_pipe__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace camera_detection_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_detection_interfaces::srv::DetectPipe_Request>()
{
  return ::camera_detection_interfaces::srv::DetectPipe_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace camera_detection_interfaces


namespace camera_detection_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectPipe_Response_message
{
public:
  explicit Init_DetectPipe_Response_message(::camera_detection_interfaces::srv::DetectPipe_Response & msg)
  : msg_(msg)
  {}
  ::camera_detection_interfaces::srv::DetectPipe_Response message(::camera_detection_interfaces::srv::DetectPipe_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::camera_detection_interfaces::srv::DetectPipe_Response msg_;
};

class Init_DetectPipe_Response_num_pipes
{
public:
  explicit Init_DetectPipe_Response_num_pipes(::camera_detection_interfaces::srv::DetectPipe_Response & msg)
  : msg_(msg)
  {}
  Init_DetectPipe_Response_message num_pipes(::camera_detection_interfaces::srv::DetectPipe_Response::_num_pipes_type arg)
  {
    msg_.num_pipes = std::move(arg);
    return Init_DetectPipe_Response_message(msg_);
  }

private:
  ::camera_detection_interfaces::srv::DetectPipe_Response msg_;
};

class Init_DetectPipe_Response_confidence
{
public:
  explicit Init_DetectPipe_Response_confidence(::camera_detection_interfaces::srv::DetectPipe_Response & msg)
  : msg_(msg)
  {}
  Init_DetectPipe_Response_num_pipes confidence(::camera_detection_interfaces::srv::DetectPipe_Response::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DetectPipe_Response_num_pipes(msg_);
  }

private:
  ::camera_detection_interfaces::srv::DetectPipe_Response msg_;
};

class Init_DetectPipe_Response_angle
{
public:
  explicit Init_DetectPipe_Response_angle(::camera_detection_interfaces::srv::DetectPipe_Response & msg)
  : msg_(msg)
  {}
  Init_DetectPipe_Response_confidence angle(::camera_detection_interfaces::srv::DetectPipe_Response::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_DetectPipe_Response_confidence(msg_);
  }

private:
  ::camera_detection_interfaces::srv::DetectPipe_Response msg_;
};

class Init_DetectPipe_Response_found
{
public:
  Init_DetectPipe_Response_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectPipe_Response_angle found(::camera_detection_interfaces::srv::DetectPipe_Response::_found_type arg)
  {
    msg_.found = std::move(arg);
    return Init_DetectPipe_Response_angle(msg_);
  }

private:
  ::camera_detection_interfaces::srv::DetectPipe_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_detection_interfaces::srv::DetectPipe_Response>()
{
  return camera_detection_interfaces::srv::builder::Init_DetectPipe_Response_found();
}

}  // namespace camera_detection_interfaces

#endif  // CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__BUILDER_HPP_
