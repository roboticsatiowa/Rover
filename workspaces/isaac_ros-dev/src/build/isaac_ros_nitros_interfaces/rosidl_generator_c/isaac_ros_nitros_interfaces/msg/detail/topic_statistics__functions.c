// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `node_name`
// Member `node_namespace`
// Member `topic_name`
#include "rosidl_runtime_c/string_functions.h"

bool
isaac_ros_nitros_interfaces__msg__TopicStatistics__init(isaac_ros_nitros_interfaces__msg__TopicStatistics * msg)
{
  if (!msg) {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__init(&msg->node_name)) {
    isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(msg);
    return false;
  }
  // node_namespace
  if (!rosidl_runtime_c__String__init(&msg->node_namespace)) {
    isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(msg);
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__init(&msg->topic_name)) {
    isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(msg);
    return false;
  }
  // is_subscriber
  // frame_rate
  // mean_abs_jitter
  // max_abs_jitter
  return true;
}

void
isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(isaac_ros_nitros_interfaces__msg__TopicStatistics * msg)
{
  if (!msg) {
    return;
  }
  // node_name
  rosidl_runtime_c__String__fini(&msg->node_name);
  // node_namespace
  rosidl_runtime_c__String__fini(&msg->node_namespace);
  // topic_name
  rosidl_runtime_c__String__fini(&msg->topic_name);
  // is_subscriber
  // frame_rate
  // mean_abs_jitter
  // max_abs_jitter
}

bool
isaac_ros_nitros_interfaces__msg__TopicStatistics__are_equal(const isaac_ros_nitros_interfaces__msg__TopicStatistics * lhs, const isaac_ros_nitros_interfaces__msg__TopicStatistics * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_name), &(rhs->node_name)))
  {
    return false;
  }
  // node_namespace
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_namespace), &(rhs->node_namespace)))
  {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->topic_name), &(rhs->topic_name)))
  {
    return false;
  }
  // is_subscriber
  if (lhs->is_subscriber != rhs->is_subscriber) {
    return false;
  }
  // frame_rate
  if (lhs->frame_rate != rhs->frame_rate) {
    return false;
  }
  // mean_abs_jitter
  if (lhs->mean_abs_jitter != rhs->mean_abs_jitter) {
    return false;
  }
  // max_abs_jitter
  if (lhs->max_abs_jitter != rhs->max_abs_jitter) {
    return false;
  }
  return true;
}

bool
isaac_ros_nitros_interfaces__msg__TopicStatistics__copy(
  const isaac_ros_nitros_interfaces__msg__TopicStatistics * input,
  isaac_ros_nitros_interfaces__msg__TopicStatistics * output)
{
  if (!input || !output) {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__copy(
      &(input->node_name), &(output->node_name)))
  {
    return false;
  }
  // node_namespace
  if (!rosidl_runtime_c__String__copy(
      &(input->node_namespace), &(output->node_namespace)))
  {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__copy(
      &(input->topic_name), &(output->topic_name)))
  {
    return false;
  }
  // is_subscriber
  output->is_subscriber = input->is_subscriber;
  // frame_rate
  output->frame_rate = input->frame_rate;
  // mean_abs_jitter
  output->mean_abs_jitter = input->mean_abs_jitter;
  // max_abs_jitter
  output->max_abs_jitter = input->max_abs_jitter;
  return true;
}

isaac_ros_nitros_interfaces__msg__TopicStatistics *
isaac_ros_nitros_interfaces__msg__TopicStatistics__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_nitros_interfaces__msg__TopicStatistics * msg = (isaac_ros_nitros_interfaces__msg__TopicStatistics *)allocator.allocate(sizeof(isaac_ros_nitros_interfaces__msg__TopicStatistics), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_nitros_interfaces__msg__TopicStatistics));
  bool success = isaac_ros_nitros_interfaces__msg__TopicStatistics__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_nitros_interfaces__msg__TopicStatistics__destroy(isaac_ros_nitros_interfaces__msg__TopicStatistics * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__init(isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_nitros_interfaces__msg__TopicStatistics * data = NULL;

  if (size) {
    data = (isaac_ros_nitros_interfaces__msg__TopicStatistics *)allocator.zero_allocate(size, sizeof(isaac_ros_nitros_interfaces__msg__TopicStatistics), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_nitros_interfaces__msg__TopicStatistics__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(&data[i - 1]);
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
isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__fini(isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * array)
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
      isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(&array->data[i]);
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

isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence *
isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * array = (isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence *)allocator.allocate(sizeof(isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__destroy(isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__are_equal(const isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * lhs, const isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_nitros_interfaces__msg__TopicStatistics__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence__copy(
  const isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * input,
  isaac_ros_nitros_interfaces__msg__TopicStatistics__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_nitros_interfaces__msg__TopicStatistics);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_nitros_interfaces__msg__TopicStatistics * data =
      (isaac_ros_nitros_interfaces__msg__TopicStatistics *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_nitros_interfaces__msg__TopicStatistics__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_nitros_interfaces__msg__TopicStatistics__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_nitros_interfaces__msg__TopicStatistics__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
