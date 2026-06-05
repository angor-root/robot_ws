// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from camera_detection_interfaces:srv/DetectPipe.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__TRAITS_HPP_
#define CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "camera_detection_interfaces/srv/detail/detect_pipe__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace camera_detection_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectPipe_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectPipe_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectPipe_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace camera_detection_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use camera_detection_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const camera_detection_interfaces::srv::DetectPipe_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  camera_detection_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use camera_detection_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const camera_detection_interfaces::srv::DetectPipe_Request & msg)
{
  return camera_detection_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<camera_detection_interfaces::srv::DetectPipe_Request>()
{
  return "camera_detection_interfaces::srv::DetectPipe_Request";
}

template<>
inline const char * name<camera_detection_interfaces::srv::DetectPipe_Request>()
{
  return "camera_detection_interfaces/srv/DetectPipe_Request";
}

template<>
struct has_fixed_size<camera_detection_interfaces::srv::DetectPipe_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<camera_detection_interfaces::srv::DetectPipe_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<camera_detection_interfaces::srv::DetectPipe_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace camera_detection_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectPipe_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: found
  {
    out << "found: ";
    rosidl_generator_traits::value_to_yaml(msg.found, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: num_pipes
  {
    out << "num_pipes: ";
    rosidl_generator_traits::value_to_yaml(msg.num_pipes, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectPipe_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "found: ";
    rosidl_generator_traits::value_to_yaml(msg.found, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: num_pipes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_pipes: ";
    rosidl_generator_traits::value_to_yaml(msg.num_pipes, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectPipe_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace camera_detection_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use camera_detection_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const camera_detection_interfaces::srv::DetectPipe_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  camera_detection_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use camera_detection_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const camera_detection_interfaces::srv::DetectPipe_Response & msg)
{
  return camera_detection_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<camera_detection_interfaces::srv::DetectPipe_Response>()
{
  return "camera_detection_interfaces::srv::DetectPipe_Response";
}

template<>
inline const char * name<camera_detection_interfaces::srv::DetectPipe_Response>()
{
  return "camera_detection_interfaces/srv/DetectPipe_Response";
}

template<>
struct has_fixed_size<camera_detection_interfaces::srv::DetectPipe_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<camera_detection_interfaces::srv::DetectPipe_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<camera_detection_interfaces::srv::DetectPipe_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<camera_detection_interfaces::srv::DetectPipe>()
{
  return "camera_detection_interfaces::srv::DetectPipe";
}

template<>
inline const char * name<camera_detection_interfaces::srv::DetectPipe>()
{
  return "camera_detection_interfaces/srv/DetectPipe";
}

template<>
struct has_fixed_size<camera_detection_interfaces::srv::DetectPipe>
  : std::integral_constant<
    bool,
    has_fixed_size<camera_detection_interfaces::srv::DetectPipe_Request>::value &&
    has_fixed_size<camera_detection_interfaces::srv::DetectPipe_Response>::value
  >
{
};

template<>
struct has_bounded_size<camera_detection_interfaces::srv::DetectPipe>
  : std::integral_constant<
    bool,
    has_bounded_size<camera_detection_interfaces::srv::DetectPipe_Request>::value &&
    has_bounded_size<camera_detection_interfaces::srv::DetectPipe_Response>::value
  >
{
};

template<>
struct is_service<camera_detection_interfaces::srv::DetectPipe>
  : std::true_type
{
};

template<>
struct is_service_request<camera_detection_interfaces::srv::DetectPipe_Request>
  : std::true_type
{
};

template<>
struct is_service_response<camera_detection_interfaces::srv::DetectPipe_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__TRAITS_HPP_
