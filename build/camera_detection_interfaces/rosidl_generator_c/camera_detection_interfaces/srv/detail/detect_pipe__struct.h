// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from camera_detection_interfaces:srv/DetectPipe.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__STRUCT_H_
#define CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DetectPipe in the package camera_detection_interfaces.
typedef struct camera_detection_interfaces__srv__DetectPipe_Request
{
  uint8_t structure_needs_at_least_one_member;
} camera_detection_interfaces__srv__DetectPipe_Request;

// Struct for a sequence of camera_detection_interfaces__srv__DetectPipe_Request.
typedef struct camera_detection_interfaces__srv__DetectPipe_Request__Sequence
{
  camera_detection_interfaces__srv__DetectPipe_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_detection_interfaces__srv__DetectPipe_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DetectPipe in the package camera_detection_interfaces.
typedef struct camera_detection_interfaces__srv__DetectPipe_Response
{
  bool found;
  float angle;
  float confidence;
  int32_t num_pipes;
  rosidl_runtime_c__String message;
} camera_detection_interfaces__srv__DetectPipe_Response;

// Struct for a sequence of camera_detection_interfaces__srv__DetectPipe_Response.
typedef struct camera_detection_interfaces__srv__DetectPipe_Response__Sequence
{
  camera_detection_interfaces__srv__DetectPipe_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_detection_interfaces__srv__DetectPipe_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_DETECTION_INTERFACES__SRV__DETAIL__DETECT_PIPE__STRUCT_H_
