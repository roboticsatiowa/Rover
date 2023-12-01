# generated from rosidl_generator_py/resource/_idl.py.em
# with input from isaac_ros_visual_slam_interfaces:action/LoadMapAndLocalize.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LoadMapAndLocalize_Goal(type):
    """Metaclass of message 'LoadMapAndLocalize_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__goal

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_Goal(metaclass=Metaclass_LoadMapAndLocalize_Goal):
    """Message class 'LoadMapAndLocalize_Goal'."""

    __slots__ = [
        '_map_url',
        '_localize_near_point',
    ]

    _fields_and_field_types = {
        'map_url': 'string',
        'localize_near_point': 'geometry_msgs/Vector3',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.map_url = kwargs.get('map_url', str())
        from geometry_msgs.msg import Vector3
        self.localize_near_point = kwargs.get('localize_near_point', Vector3())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.map_url != other.map_url:
            return False
        if self.localize_near_point != other.localize_near_point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def map_url(self):
        """Message field 'map_url'."""
        return self._map_url

    @map_url.setter
    def map_url(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'map_url' field must be of type 'str'"
        self._map_url = value

    @builtins.property
    def localize_near_point(self):
        """Message field 'localize_near_point'."""
        return self._localize_near_point

    @localize_near_point.setter
    def localize_near_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'localize_near_point' field must be a sub message of type 'Vector3'"
        self._localize_near_point = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_Result(type):
    """Metaclass of message 'LoadMapAndLocalize_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__result

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_Result(metaclass=Metaclass_LoadMapAndLocalize_Result):
    """Message class 'LoadMapAndLocalize_Result'."""

    __slots__ = [
        '_success',
        '_pose',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'pose': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.pose != other.pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_Feedback(type):
    """Metaclass of message 'LoadMapAndLocalize_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_Feedback(metaclass=Metaclass_LoadMapAndLocalize_Feedback):
    """Message class 'LoadMapAndLocalize_Feedback'."""

    __slots__ = [
        '_progress',
    ]

    _fields_and_field_types = {
        'progress': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.progress = kwargs.get('progress', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.progress != other.progress:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def progress(self):
        """Message field 'progress'."""
        return self._progress

    @progress.setter
    def progress(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'progress' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'progress' field must be an integer in [-2147483648, 2147483647]"
        self._progress = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_SendGoal_Request(type):
    """Metaclass of message 'LoadMapAndLocalize_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__send_goal__request

            from isaac_ros_visual_slam_interfaces.action import LoadMapAndLocalize
            if LoadMapAndLocalize.Goal.__class__._TYPE_SUPPORT is None:
                LoadMapAndLocalize.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_SendGoal_Request(metaclass=Metaclass_LoadMapAndLocalize_SendGoal_Request):
    """Message class 'LoadMapAndLocalize_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'isaac_ros_visual_slam_interfaces/LoadMapAndLocalize_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['isaac_ros_visual_slam_interfaces', 'action'], 'LoadMapAndLocalize_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Goal
        self.goal = kwargs.get('goal', LoadMapAndLocalize_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Goal
            assert \
                isinstance(value, LoadMapAndLocalize_Goal), \
                "The 'goal' field must be a sub message of type 'LoadMapAndLocalize_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_SendGoal_Response(type):
    """Metaclass of message 'LoadMapAndLocalize_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_SendGoal_Response(metaclass=Metaclass_LoadMapAndLocalize_SendGoal_Response):
    """Message class 'LoadMapAndLocalize_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_LoadMapAndLocalize_SendGoal(type):
    """Metaclass of service 'LoadMapAndLocalize_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__load_map_and_localize__send_goal

            from isaac_ros_visual_slam_interfaces.action import _load_map_and_localize
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_SendGoal_Request._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_SendGoal_Request.__import_type_support__()
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_SendGoal_Response._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_SendGoal_Response.__import_type_support__()


class LoadMapAndLocalize_SendGoal(metaclass=Metaclass_LoadMapAndLocalize_SendGoal):
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_SendGoal_Request as Request
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_GetResult_Request(type):
    """Metaclass of message 'LoadMapAndLocalize_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_GetResult_Request(metaclass=Metaclass_LoadMapAndLocalize_GetResult_Request):
    """Message class 'LoadMapAndLocalize_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_GetResult_Response(type):
    """Metaclass of message 'LoadMapAndLocalize_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__get_result__response

            from isaac_ros_visual_slam_interfaces.action import LoadMapAndLocalize
            if LoadMapAndLocalize.Result.__class__._TYPE_SUPPORT is None:
                LoadMapAndLocalize.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_GetResult_Response(metaclass=Metaclass_LoadMapAndLocalize_GetResult_Response):
    """Message class 'LoadMapAndLocalize_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'isaac_ros_visual_slam_interfaces/LoadMapAndLocalize_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['isaac_ros_visual_slam_interfaces', 'action'], 'LoadMapAndLocalize_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Result
        self.result = kwargs.get('result', LoadMapAndLocalize_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Result
            assert \
                isinstance(value, LoadMapAndLocalize_Result), \
                "The 'result' field must be a sub message of type 'LoadMapAndLocalize_Result'"
        self._result = value


class Metaclass_LoadMapAndLocalize_GetResult(type):
    """Metaclass of service 'LoadMapAndLocalize_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__load_map_and_localize__get_result

            from isaac_ros_visual_slam_interfaces.action import _load_map_and_localize
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_GetResult_Request._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_GetResult_Request.__import_type_support__()
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_GetResult_Response._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_GetResult_Response.__import_type_support__()


class LoadMapAndLocalize_GetResult(metaclass=Metaclass_LoadMapAndLocalize_GetResult):
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_GetResult_Request as Request
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadMapAndLocalize_FeedbackMessage(type):
    """Metaclass of message 'LoadMapAndLocalize_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__load_map_and_localize__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__load_map_and_localize__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__load_map_and_localize__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__load_map_and_localize__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__load_map_and_localize__feedback_message

            from isaac_ros_visual_slam_interfaces.action import LoadMapAndLocalize
            if LoadMapAndLocalize.Feedback.__class__._TYPE_SUPPORT is None:
                LoadMapAndLocalize.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadMapAndLocalize_FeedbackMessage(metaclass=Metaclass_LoadMapAndLocalize_FeedbackMessage):
    """Message class 'LoadMapAndLocalize_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'isaac_ros_visual_slam_interfaces/LoadMapAndLocalize_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['isaac_ros_visual_slam_interfaces', 'action'], 'LoadMapAndLocalize_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Feedback
        self.feedback = kwargs.get('feedback', LoadMapAndLocalize_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Feedback
            assert \
                isinstance(value, LoadMapAndLocalize_Feedback), \
                "The 'feedback' field must be a sub message of type 'LoadMapAndLocalize_Feedback'"
        self._feedback = value


class Metaclass_LoadMapAndLocalize(type):
    """Metaclass of action 'LoadMapAndLocalize'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaac_ros_visual_slam_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_visual_slam_interfaces.action.LoadMapAndLocalize')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__load_map_and_localize

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from isaac_ros_visual_slam_interfaces.action import _load_map_and_localize
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_SendGoal._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_SendGoal.__import_type_support__()
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_GetResult._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_GetResult.__import_type_support__()
            if _load_map_and_localize.Metaclass_LoadMapAndLocalize_FeedbackMessage._TYPE_SUPPORT is None:
                _load_map_and_localize.Metaclass_LoadMapAndLocalize_FeedbackMessage.__import_type_support__()


class LoadMapAndLocalize(metaclass=Metaclass_LoadMapAndLocalize):

    # The goal message defined in the action definition.
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Goal as Goal
    # The result message defined in the action definition.
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Result as Result
    # The feedback message defined in the action definition.
    from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from isaac_ros_visual_slam_interfaces.action._load_map_and_localize import LoadMapAndLocalize_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
