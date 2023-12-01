# generated from rosidl_generator_py/resource/_idl.py.em
# with input from isaac_ros_nitros_interfaces:msg/TopicStatistics.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TopicStatistics(type):
    """Metaclass of message 'TopicStatistics'."""

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
            module = import_type_support('isaac_ros_nitros_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaac_ros_nitros_interfaces.msg.TopicStatistics')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__topic_statistics
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__topic_statistics
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__topic_statistics
            cls._TYPE_SUPPORT = module.type_support_msg__msg__topic_statistics
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__topic_statistics

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TopicStatistics(metaclass=Metaclass_TopicStatistics):
    """Message class 'TopicStatistics'."""

    __slots__ = [
        '_node_name',
        '_node_namespace',
        '_topic_name',
        '_is_subscriber',
        '_frame_rate',
        '_mean_abs_jitter',
        '_max_abs_jitter',
    ]

    _fields_and_field_types = {
        'node_name': 'string',
        'node_namespace': 'string',
        'topic_name': 'string',
        'is_subscriber': 'boolean',
        'frame_rate': 'float',
        'mean_abs_jitter': 'int32',
        'max_abs_jitter': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.node_name = kwargs.get('node_name', str())
        self.node_namespace = kwargs.get('node_namespace', str())
        self.topic_name = kwargs.get('topic_name', str())
        self.is_subscriber = kwargs.get('is_subscriber', bool())
        self.frame_rate = kwargs.get('frame_rate', float())
        self.mean_abs_jitter = kwargs.get('mean_abs_jitter', int())
        self.max_abs_jitter = kwargs.get('max_abs_jitter', int())

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
        if self.node_name != other.node_name:
            return False
        if self.node_namespace != other.node_namespace:
            return False
        if self.topic_name != other.topic_name:
            return False
        if self.is_subscriber != other.is_subscriber:
            return False
        if self.frame_rate != other.frame_rate:
            return False
        if self.mean_abs_jitter != other.mean_abs_jitter:
            return False
        if self.max_abs_jitter != other.max_abs_jitter:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def node_name(self):
        """Message field 'node_name'."""
        return self._node_name

    @node_name.setter
    def node_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_name' field must be of type 'str'"
        self._node_name = value

    @builtins.property
    def node_namespace(self):
        """Message field 'node_namespace'."""
        return self._node_namespace

    @node_namespace.setter
    def node_namespace(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_namespace' field must be of type 'str'"
        self._node_namespace = value

    @builtins.property
    def topic_name(self):
        """Message field 'topic_name'."""
        return self._topic_name

    @topic_name.setter
    def topic_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'topic_name' field must be of type 'str'"
        self._topic_name = value

    @builtins.property
    def is_subscriber(self):
        """Message field 'is_subscriber'."""
        return self._is_subscriber

    @is_subscriber.setter
    def is_subscriber(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_subscriber' field must be of type 'bool'"
        self._is_subscriber = value

    @builtins.property
    def frame_rate(self):
        """Message field 'frame_rate'."""
        return self._frame_rate

    @frame_rate.setter
    def frame_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'frame_rate' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'frame_rate' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._frame_rate = value

    @builtins.property
    def mean_abs_jitter(self):
        """Message field 'mean_abs_jitter'."""
        return self._mean_abs_jitter

    @mean_abs_jitter.setter
    def mean_abs_jitter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_abs_jitter' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mean_abs_jitter' field must be an integer in [-2147483648, 2147483647]"
        self._mean_abs_jitter = value

    @builtins.property
    def max_abs_jitter(self):
        """Message field 'max_abs_jitter'."""
        return self._max_abs_jitter

    @max_abs_jitter.setter
    def max_abs_jitter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_abs_jitter' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_abs_jitter' field must be an integer in [-2147483648, 2147483647]"
        self._max_abs_jitter = value
