// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__struct.h"
#include "isaac_ros_nitros_interfaces/msg/detail/topic_statistics__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool isaac_ros_nitros_interfaces__msg__topic_statistics__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[66];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("isaac_ros_nitros_interfaces.msg._topic_statistics.TopicStatistics", full_classname_dest, 65) == 0);
  }
  isaac_ros_nitros_interfaces__msg__TopicStatistics * ros_message = _ros_message;
  {  // node_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->node_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // node_namespace
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_namespace");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->node_namespace, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // topic_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->topic_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // is_subscriber
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_subscriber");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_subscriber = (Py_True == field);
    Py_DECREF(field);
  }
  {  // frame_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "frame_rate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->frame_rate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mean_abs_jitter
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean_abs_jitter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mean_abs_jitter = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // max_abs_jitter
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_abs_jitter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_abs_jitter = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * isaac_ros_nitros_interfaces__msg__topic_statistics__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TopicStatistics */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("isaac_ros_nitros_interfaces.msg._topic_statistics");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TopicStatistics");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  isaac_ros_nitros_interfaces__msg__TopicStatistics * ros_message = (isaac_ros_nitros_interfaces__msg__TopicStatistics *)raw_ros_message;
  {  // node_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->node_name.data,
      strlen(ros_message->node_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_namespace
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->node_namespace.data,
      strlen(ros_message->node_namespace.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_namespace", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // topic_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->topic_name.data,
      strlen(ros_message->topic_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_subscriber
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_subscriber ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_subscriber", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frame_rate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->frame_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frame_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mean_abs_jitter
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mean_abs_jitter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean_abs_jitter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_abs_jitter
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max_abs_jitter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_abs_jitter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
