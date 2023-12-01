# generated from rosidl_generator_py/resource/_idl.py.em
# with input from isaac_ros_visual_slam_interfaces:msg/VisualSlamStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisualSlamStatus(type):
    """Metaclass of message 'VisualSlamStatus'."""

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
                'isaac_ros_visual_slam_interfaces.msg.VisualSlamStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__visual_slam_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__visual_slam_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__visual_slam_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__visual_slam_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__visual_slam_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VisualSlamStatus(metaclass=Metaclass_VisualSlamStatus):
    """Message class 'VisualSlamStatus'."""

    __slots__ = [
        '_header',
        '_vo_state',
        '_node_callback_execution_time',
        '_track_execution_time',
        '_track_execution_time_mean',
        '_track_execution_time_max',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'vo_state': 'uint8',
        'node_callback_execution_time': 'double',
        'track_execution_time': 'double',
        'track_execution_time_mean': 'double',
        'track_execution_time_max': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.vo_state = kwargs.get('vo_state', int())
        self.node_callback_execution_time = kwargs.get('node_callback_execution_time', float())
        self.track_execution_time = kwargs.get('track_execution_time', float())
        self.track_execution_time_mean = kwargs.get('track_execution_time_mean', float())
        self.track_execution_time_max = kwargs.get('track_execution_time_max', float())

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
        if self.header != other.header:
            return False
        if self.vo_state != other.vo_state:
            return False
        if self.node_callback_execution_time != other.node_callback_execution_time:
            return False
        if self.track_execution_time != other.track_execution_time:
            return False
        if self.track_execution_time_mean != other.track_execution_time_mean:
            return False
        if self.track_execution_time_max != other.track_execution_time_max:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def vo_state(self):
        """Message field 'vo_state'."""
        return self._vo_state

    @vo_state.setter
    def vo_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vo_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vo_state' field must be an unsigned integer in [0, 255]"
        self._vo_state = value

    @builtins.property
    def node_callback_execution_time(self):
        """Message field 'node_callback_execution_time'."""
        return self._node_callback_execution_time

    @node_callback_execution_time.setter
    def node_callback_execution_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'node_callback_execution_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'node_callback_execution_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._node_callback_execution_time = value

    @builtins.property
    def track_execution_time(self):
        """Message field 'track_execution_time'."""
        return self._track_execution_time

    @track_execution_time.setter
    def track_execution_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'track_execution_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'track_execution_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._track_execution_time = value

    @builtins.property
    def track_execution_time_mean(self):
        """Message field 'track_execution_time_mean'."""
        return self._track_execution_time_mean

    @track_execution_time_mean.setter
    def track_execution_time_mean(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'track_execution_time_mean' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'track_execution_time_mean' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._track_execution_time_mean = value

    @builtins.property
    def track_execution_time_max(self):
        """Message field 'track_execution_time_max'."""
        return self._track_execution_time_max

    @track_execution_time_max.setter
    def track_execution_time_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'track_execution_time_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'track_execution_time_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._track_execution_time_max = value
