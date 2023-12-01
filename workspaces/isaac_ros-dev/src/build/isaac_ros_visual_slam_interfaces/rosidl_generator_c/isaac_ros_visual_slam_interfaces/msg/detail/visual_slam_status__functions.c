// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
// generated code does not contain a copyright notice
#include "isaac_ros_visual_slam_interfaces/msg/detail/visual_slam_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__init(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(msg);
    return false;
  }
  // vo_state
  // node_callback_execution_time
  // track_execution_time
  // track_execution_time_mean
  // track_execution_time_max
  return true;
}

void
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // vo_state
  // node_callback_execution_time
  // track_execution_time
  // track_execution_time_mean
  // track_execution_time_max
}

bool
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__are_equal(const isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * lhs, const isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // vo_state
  if (lhs->vo_state != rhs->vo_state) {
    return false;
  }
  // node_callback_execution_time
  if (lhs->node_callback_execution_time != rhs->node_callback_execution_time) {
    return false;
  }
  // track_execution_time
  if (lhs->track_execution_time != rhs->track_execution_time) {
    return false;
  }
  // track_execution_time_mean
  if (lhs->track_execution_time_mean != rhs->track_execution_time_mean) {
    return false;
  }
  // track_execution_time_max
  if (lhs->track_execution_time_max != rhs->track_execution_time_max) {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__copy(
  const isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * input,
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // vo_state
  output->vo_state = input->vo_state;
  // node_callback_execution_time
  output->node_callback_execution_time = input->node_callback_execution_time;
  // track_execution_time
  output->track_execution_time = input->track_execution_time;
  // track_execution_time_mean
  output->track_execution_time_mean = input->track_execution_time_mean;
  // track_execution_time_max
  output->track_execution_time_max = input->track_execution_time_max;
  return true;
}

isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus *
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * msg = (isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus));
  bool success = isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__destroy(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__init(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__fini(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence *
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * array = (isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__destroy(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * lhs, const isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * input,
  isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus * data =
      (isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__msg__VisualSlamStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
