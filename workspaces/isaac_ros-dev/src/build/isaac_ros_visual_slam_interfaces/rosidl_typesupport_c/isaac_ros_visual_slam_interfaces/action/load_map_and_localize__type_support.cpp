// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from isaac_ros_visual_slam_interfaces:action/LoadMapAndLocalize.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
#include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_Goal_type_support_ids_t;

static const _LoadMapAndLocalize_Goal_type_support_ids_t _LoadMapAndLocalize_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_Goal_type_support_symbol_names_t _LoadMapAndLocalize_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Goal)),
  }
};

typedef struct _LoadMapAndLocalize_Goal_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_Goal_type_support_data_t;

static _LoadMapAndLocalize_Goal_type_support_data_t _LoadMapAndLocalize_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_Goal_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Goal)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_Result_type_support_ids_t;

static const _LoadMapAndLocalize_Result_type_support_ids_t _LoadMapAndLocalize_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_Result_type_support_symbol_names_t _LoadMapAndLocalize_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Result)),
  }
};

typedef struct _LoadMapAndLocalize_Result_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_Result_type_support_data_t;

static _LoadMapAndLocalize_Result_type_support_data_t _LoadMapAndLocalize_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_Result_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_Result_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_Result_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Result)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_Feedback_type_support_ids_t;

static const _LoadMapAndLocalize_Feedback_type_support_ids_t _LoadMapAndLocalize_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_Feedback_type_support_symbol_names_t _LoadMapAndLocalize_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Feedback)),
  }
};

typedef struct _LoadMapAndLocalize_Feedback_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_Feedback_type_support_data_t;

static _LoadMapAndLocalize_Feedback_type_support_data_t _LoadMapAndLocalize_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_Feedback_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_Feedback)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_SendGoal_Request_type_support_ids_t;

static const _LoadMapAndLocalize_SendGoal_Request_type_support_ids_t _LoadMapAndLocalize_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_SendGoal_Request_type_support_symbol_names_t _LoadMapAndLocalize_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Request)),
  }
};

typedef struct _LoadMapAndLocalize_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_SendGoal_Request_type_support_data_t;

static _LoadMapAndLocalize_SendGoal_Request_type_support_data_t _LoadMapAndLocalize_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_SendGoal_Request_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Request)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_SendGoal_Response_type_support_ids_t;

static const _LoadMapAndLocalize_SendGoal_Response_type_support_ids_t _LoadMapAndLocalize_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_SendGoal_Response_type_support_symbol_names_t _LoadMapAndLocalize_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Response)),
  }
};

typedef struct _LoadMapAndLocalize_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_SendGoal_Response_type_support_data_t;

static _LoadMapAndLocalize_SendGoal_Response_type_support_data_t _LoadMapAndLocalize_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_SendGoal_Response_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal_Response)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_SendGoal_type_support_ids_t;

static const _LoadMapAndLocalize_SendGoal_type_support_ids_t _LoadMapAndLocalize_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_SendGoal_type_support_symbol_names_t _LoadMapAndLocalize_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal)),
  }
};

typedef struct _LoadMapAndLocalize_SendGoal_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_SendGoal_type_support_data_t;

static _LoadMapAndLocalize_SendGoal_type_support_data_t _LoadMapAndLocalize_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_SendGoal_service_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t LoadMapAndLocalize_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_GetResult_Request_type_support_ids_t;

static const _LoadMapAndLocalize_GetResult_Request_type_support_ids_t _LoadMapAndLocalize_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_GetResult_Request_type_support_symbol_names_t _LoadMapAndLocalize_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Request)),
  }
};

typedef struct _LoadMapAndLocalize_GetResult_Request_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_GetResult_Request_type_support_data_t;

static _LoadMapAndLocalize_GetResult_Request_type_support_data_t _LoadMapAndLocalize_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_GetResult_Request_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Request)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_GetResult_Response_type_support_ids_t;

static const _LoadMapAndLocalize_GetResult_Response_type_support_ids_t _LoadMapAndLocalize_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_GetResult_Response_type_support_symbol_names_t _LoadMapAndLocalize_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Response)),
  }
};

typedef struct _LoadMapAndLocalize_GetResult_Response_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_GetResult_Response_type_support_data_t;

static _LoadMapAndLocalize_GetResult_Response_type_support_data_t _LoadMapAndLocalize_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_GetResult_Response_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult_Response)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_GetResult_type_support_ids_t;

static const _LoadMapAndLocalize_GetResult_type_support_ids_t _LoadMapAndLocalize_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_GetResult_type_support_symbol_names_t _LoadMapAndLocalize_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult)),
  }
};

typedef struct _LoadMapAndLocalize_GetResult_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_GetResult_type_support_data_t;

static _LoadMapAndLocalize_GetResult_type_support_data_t _LoadMapAndLocalize_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_GetResult_service_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t LoadMapAndLocalize_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__struct.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace isaac_ros_visual_slam_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _LoadMapAndLocalize_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _LoadMapAndLocalize_FeedbackMessage_type_support_ids_t;

static const _LoadMapAndLocalize_FeedbackMessage_type_support_ids_t _LoadMapAndLocalize_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _LoadMapAndLocalize_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _LoadMapAndLocalize_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _LoadMapAndLocalize_FeedbackMessage_type_support_symbol_names_t _LoadMapAndLocalize_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_FeedbackMessage)),
  }
};

typedef struct _LoadMapAndLocalize_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _LoadMapAndLocalize_FeedbackMessage_type_support_data_t;

static _LoadMapAndLocalize_FeedbackMessage_type_support_data_t _LoadMapAndLocalize_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _LoadMapAndLocalize_FeedbackMessage_message_typesupport_map = {
  2,
  "isaac_ros_visual_slam_interfaces",
  &_LoadMapAndLocalize_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_LoadMapAndLocalize_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_LoadMapAndLocalize_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t LoadMapAndLocalize_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_LoadMapAndLocalize_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace isaac_ros_visual_slam_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_FeedbackMessage)() {
  return &::isaac_ros_visual_slam_interfaces::action::rosidl_typesupport_c::LoadMapAndLocalize_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "isaac_ros_visual_slam_interfaces/action/load_map_and_localize.h"
// already included above
// #include "isaac_ros_visual_slam_interfaces/action/detail/load_map_and_localize__type_support.h"

static rosidl_action_type_support_t _isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize)()
{
  // Thread-safe by always writing the same values to the static struct
  _isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_SendGoal)();
  _isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_GetResult)();
  _isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, isaac_ros_visual_slam_interfaces, action, LoadMapAndLocalize_FeedbackMessage)();
  _isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_isaac_ros_visual_slam_interfaces__action__LoadMapAndLocalize__typesupport_c;
}

#ifdef __cplusplus
}
#endif
