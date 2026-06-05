// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from camera_detection_interfaces:srv/DetectPipe.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__STRUCT_HPP_
#define CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Request __attribute__((deprecated))
#else
# define DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Request __declspec(deprecated)
#endif

namespace camera_detection_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectPipe_Request_
{
  using Type = DetectPipe_Request_<ContainerAllocator>;

  explicit DetectPipe_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit DetectPipe_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Request
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Request
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectPipe_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectPipe_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectPipe_Request_

// alias to use template instance with default allocator
using DetectPipe_Request =
  camera_detection_interfaces::srv::DetectPipe_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace camera_detection_interfaces


#ifndef _WIN32
# define DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Response __attribute__((deprecated))
#else
# define DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Response __declspec(deprecated)
#endif

namespace camera_detection_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectPipe_Response_
{
  using Type = DetectPipe_Response_<ContainerAllocator>;

  explicit DetectPipe_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->found = false;
      this->angle = 0.0f;
      this->confidence = 0.0f;
      this->num_pipes = 0l;
      this->message = "";
    }
  }

  explicit DetectPipe_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->found = false;
      this->angle = 0.0f;
      this->confidence = 0.0f;
      this->num_pipes = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _found_type =
    bool;
  _found_type found;
  using _angle_type =
    float;
  _angle_type angle;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _num_pipes_type =
    int32_t;
  _num_pipes_type num_pipes;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__found(
    const bool & _arg)
  {
    this->found = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__num_pipes(
    const int32_t & _arg)
  {
    this->num_pipes = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Response
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__camera_detection_interfaces__srv__DetectPipe_Response
    std::shared_ptr<camera_detection_interfaces::srv::DetectPipe_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectPipe_Response_ & other) const
  {
    if (this->found != other.found) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->num_pipes != other.num_pipes) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectPipe_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectPipe_Response_

// alias to use template instance with default allocator
using DetectPipe_Response =
  camera_detection_interfaces::srv::DetectPipe_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace camera_detection_interfaces

namespace camera_detection_interfaces
{

namespace srv
{

struct DetectPipe
{
  using Request = camera_detection_interfaces::srv::DetectPipe_Request;
  using Response = camera_detection_interfaces::srv::DetectPipe_Response;
};

}  // namespace srv

}  // namespace camera_detection_interfaces

#endif  // CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__STRUCT_HPP_
