// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from camera_detection_interfaces:srv/DetectPipe.idl
// generated code does not contain a copyright notice
#include "camera_detection_interfaces/srv/detail/detect_pipe__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
camera_detection_interfaces__srv__DetectPipe_Request__init(camera_detection_interfaces__srv__DetectPipe_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
camera_detection_interfaces__srv__DetectPipe_Request__fini(camera_detection_interfaces__srv__DetectPipe_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
camera_detection_interfaces__srv__DetectPipe_Request__are_equal(const camera_detection_interfaces__srv__DetectPipe_Request * lhs, const camera_detection_interfaces__srv__DetectPipe_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
camera_detection_interfaces__srv__DetectPipe_Request__copy(
  const camera_detection_interfaces__srv__DetectPipe_Request * input,
  camera_detection_interfaces__srv__DetectPipe_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

camera_detection_interfaces__srv__DetectPipe_Request *
camera_detection_interfaces__srv__DetectPipe_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_detection_interfaces__srv__DetectPipe_Request * msg = (camera_detection_interfaces__srv__DetectPipe_Request *)allocator.allocate(sizeof(camera_detection_interfaces__srv__DetectPipe_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera_detection_interfaces__srv__DetectPipe_Request));
  bool success = camera_detection_interfaces__srv__DetectPipe_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera_detection_interfaces__srv__DetectPipe_Request__destroy(camera_detection_interfaces__srv__DetectPipe_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera_detection_interfaces__srv__DetectPipe_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera_detection_interfaces__srv__DetectPipe_Request__Sequence__init(camera_detection_interfaces__srv__DetectPipe_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_detection_interfaces__srv__DetectPipe_Request * data = NULL;

  if (size) {
    data = (camera_detection_interfaces__srv__DetectPipe_Request *)allocator.zero_allocate(size, sizeof(camera_detection_interfaces__srv__DetectPipe_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera_detection_interfaces__srv__DetectPipe_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera_detection_interfaces__srv__DetectPipe_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
camera_detection_interfaces__srv__DetectPipe_Request__Sequence__fini(camera_detection_interfaces__srv__DetectPipe_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      camera_detection_interfaces__srv__DetectPipe_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

camera_detection_interfaces__srv__DetectPipe_Request__Sequence *
camera_detection_interfaces__srv__DetectPipe_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_detection_interfaces__srv__DetectPipe_Request__Sequence * array = (camera_detection_interfaces__srv__DetectPipe_Request__Sequence *)allocator.allocate(sizeof(camera_detection_interfaces__srv__DetectPipe_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera_detection_interfaces__srv__DetectPipe_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera_detection_interfaces__srv__DetectPipe_Request__Sequence__destroy(camera_detection_interfaces__srv__DetectPipe_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera_detection_interfaces__srv__DetectPipe_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera_detection_interfaces__srv__DetectPipe_Request__Sequence__are_equal(const camera_detection_interfaces__srv__DetectPipe_Request__Sequence * lhs, const camera_detection_interfaces__srv__DetectPipe_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera_detection_interfaces__srv__DetectPipe_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera_detection_interfaces__srv__DetectPipe_Request__Sequence__copy(
  const camera_detection_interfaces__srv__DetectPipe_Request__Sequence * input,
  camera_detection_interfaces__srv__DetectPipe_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera_detection_interfaces__srv__DetectPipe_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera_detection_interfaces__srv__DetectPipe_Request * data =
      (camera_detection_interfaces__srv__DetectPipe_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera_detection_interfaces__srv__DetectPipe_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera_detection_interfaces__srv__DetectPipe_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera_detection_interfaces__srv__DetectPipe_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
camera_detection_interfaces__srv__DetectPipe_Response__init(camera_detection_interfaces__srv__DetectPipe_Response * msg)
{
  if (!msg) {
    return false;
  }
  // found
  // angle
  // confidence
  // num_pipes
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    camera_detection_interfaces__srv__DetectPipe_Response__fini(msg);
    return false;
  }
  return true;
}

void
camera_detection_interfaces__srv__DetectPipe_Response__fini(camera_detection_interfaces__srv__DetectPipe_Response * msg)
{
  if (!msg) {
    return;
  }
  // found
  // angle
  // confidence
  // num_pipes
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
camera_detection_interfaces__srv__DetectPipe_Response__are_equal(const camera_detection_interfaces__srv__DetectPipe_Response * lhs, const camera_detection_interfaces__srv__DetectPipe_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // found
  if (lhs->found != rhs->found) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // num_pipes
  if (lhs->num_pipes != rhs->num_pipes) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
camera_detection_interfaces__srv__DetectPipe_Response__copy(
  const camera_detection_interfaces__srv__DetectPipe_Response * input,
  camera_detection_interfaces__srv__DetectPipe_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // found
  output->found = input->found;
  // angle
  output->angle = input->angle;
  // confidence
  output->confidence = input->confidence;
  // num_pipes
  output->num_pipes = input->num_pipes;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

camera_detection_interfaces__srv__DetectPipe_Response *
camera_detection_interfaces__srv__DetectPipe_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_detection_interfaces__srv__DetectPipe_Response * msg = (camera_detection_interfaces__srv__DetectPipe_Response *)allocator.allocate(sizeof(camera_detection_interfaces__srv__DetectPipe_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera_detection_interfaces__srv__DetectPipe_Response));
  bool success = camera_detection_interfaces__srv__DetectPipe_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera_detection_interfaces__srv__DetectPipe_Response__destroy(camera_detection_interfaces__srv__DetectPipe_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera_detection_interfaces__srv__DetectPipe_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera_detection_interfaces__srv__DetectPipe_Response__Sequence__init(camera_detection_interfaces__srv__DetectPipe_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_detection_interfaces__srv__DetectPipe_Response * data = NULL;

  if (size) {
    data = (camera_detection_interfaces__srv__DetectPipe_Response *)allocator.zero_allocate(size, sizeof(camera_detection_interfaces__srv__DetectPipe_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera_detection_interfaces__srv__DetectPipe_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera_detection_interfaces__srv__DetectPipe_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
camera_detection_interfaces__srv__DetectPipe_Response__Sequence__fini(camera_detection_interfaces__srv__DetectPipe_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      camera_detection_interfaces__srv__DetectPipe_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

camera_detection_interfaces__srv__DetectPipe_Response__Sequence *
camera_detection_interfaces__srv__DetectPipe_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_detection_interfaces__srv__DetectPipe_Response__Sequence * array = (camera_detection_interfaces__srv__DetectPipe_Response__Sequence *)allocator.allocate(sizeof(camera_detection_interfaces__srv__DetectPipe_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera_detection_interfaces__srv__DetectPipe_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera_detection_interfaces__srv__DetectPipe_Response__Sequence__destroy(camera_detection_interfaces__srv__DetectPipe_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera_detection_interfaces__srv__DetectPipe_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera_detection_interfaces__srv__DetectPipe_Response__Sequence__are_equal(const camera_detection_interfaces__srv__DetectPipe_Response__Sequence * lhs, const camera_detection_interfaces__srv__DetectPipe_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera_detection_interfaces__srv__DetectPipe_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera_detection_interfaces__srv__DetectPipe_Response__Sequence__copy(
  const camera_detection_interfaces__srv__DetectPipe_Response__Sequence * input,
  camera_detection_interfaces__srv__DetectPipe_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera_detection_interfaces__srv__DetectPipe_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera_detection_interfaces__srv__DetectPipe_Response * data =
      (camera_detection_interfaces__srv__DetectPipe_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera_detection_interfaces__srv__DetectPipe_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera_detection_interfaces__srv__DetectPipe_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera_detection_interfaces__srv__DetectPipe_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
