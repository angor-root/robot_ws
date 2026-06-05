# generated from rosidl_generator_py/resource/_idl.py.em
# with input from camera_detection_interfaces:srv/DetectPipe.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectPipe_Request(type):
    """Metaclass of message 'DetectPipe_Request'."""

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
            module = import_type_support('camera_detection_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'camera_detection_interfaces.srv.DetectPipe_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detect_pipe__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detect_pipe__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detect_pipe__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detect_pipe__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detect_pipe__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectPipe_Request(metaclass=Metaclass_DetectPipe_Request):
    """Message class 'DetectPipe_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_DetectPipe_Response(type):
    """Metaclass of message 'DetectPipe_Response'."""

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
            module = import_type_support('camera_detection_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'camera_detection_interfaces.srv.DetectPipe_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detect_pipe__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detect_pipe__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detect_pipe__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detect_pipe__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detect_pipe__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectPipe_Response(metaclass=Metaclass_DetectPipe_Response):
    """Message class 'DetectPipe_Response'."""

    __slots__ = [
        '_found',
        '_angle',
        '_confidence',
        '_num_pipes',
        '_message',
    ]

    _fields_and_field_types = {
        'found': 'boolean',
        'angle': 'float',
        'confidence': 'float',
        'num_pipes': 'int32',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.found = kwargs.get('found', bool())
        self.angle = kwargs.get('angle', float())
        self.confidence = kwargs.get('confidence', float())
        self.num_pipes = kwargs.get('num_pipes', int())
        self.message = kwargs.get('message', str())

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
        if self.found != other.found:
            return False
        if self.angle != other.angle:
            return False
        if self.confidence != other.confidence:
            return False
        if self.num_pipes != other.num_pipes:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def found(self):
        """Message field 'found'."""
        return self._found

    @found.setter
    def found(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'found' field must be of type 'bool'"
        self._found = value

    @builtins.property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._angle = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def num_pipes(self):
        """Message field 'num_pipes'."""
        return self._num_pipes

    @num_pipes.setter
    def num_pipes(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_pipes' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_pipes' field must be an integer in [-2147483648, 2147483647]"
        self._num_pipes = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_DetectPipe(type):
    """Metaclass of service 'DetectPipe'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('camera_detection_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'camera_detection_interfaces.srv.DetectPipe')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__detect_pipe

            from camera_detection_interfaces.srv import _detect_pipe
            if _detect_pipe.Metaclass_DetectPipe_Request._TYPE_SUPPORT is None:
                _detect_pipe.Metaclass_DetectPipe_Request.__import_type_support__()
            if _detect_pipe.Metaclass_DetectPipe_Response._TYPE_SUPPORT is None:
                _detect_pipe.Metaclass_DetectPipe_Response.__import_type_support__()


class DetectPipe(metaclass=Metaclass_DetectPipe):
    from camera_detection_interfaces.srv._detect_pipe import DetectPipe_Request as Request
    from camera_detection_interfaces.srv._detect_pipe import DetectPipe_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
