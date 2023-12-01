// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from isaac_ros_visual_slam_interfaces:action/LoadMapAndLocalize.idl
// generated code does not contain a copyright notice
#include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `map_url`
#include "rosidl_runtime_c/string_functions.h"
// Member `localize_near_point`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // map_url
  if (!rosidl_runtime_c__String__init(&msg->map_url)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(msg);
    return false;
  }
  // localize_near_point
  if (!geometry_msgs__msg__Vector3__init(&msg->localize_near_point)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * msg)
{
  if (!msg) {
    return;
  }
  // map_url
  rosidl_runtime_c__String__fini(&msg->map_url);
  // localize_near_point
  geometry_msgs__msg__Vector3__fini(&msg->localize_near_point);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // map_url
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->map_url), &(rhs->map_url)))
  {
    return false;
  }
  // localize_near_point
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->localize_near_point), &(rhs->localize_near_point)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // map_url
  if (!rosidl_runtime_c__String__copy(
      &(input->map_url), &(output->map_url)))
  {
    return false;
  }
  // localize_near_point
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->localize_near_point), &(output->localize_near_point)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // progress
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  output->progress = input->progress;
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__init(&msg->goal)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__fini(&msg->goal);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__init(&msg->result)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__fini(&msg->result);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__functions.h"

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__init(&msg->feedback)) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__fini(&msg->feedback);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * msg = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage));
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__init(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * data = NULL;

  if (size) {
    data = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage *)allocator.zero_allocate(size, sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(&data[i - 1]);
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
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__fini(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * array)
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
      isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(&array->data[i]);
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

isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence *
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * array = (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence *)allocator.allocate(sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__destroy(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__are_equal(const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * lhs, const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence__copy(
  const isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * input,
  isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage * data =
      (isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
