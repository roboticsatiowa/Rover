from setuptools import find_packages
from setuptools import setup

setup(
    name='isaac_ros_nova_interfaces',
    version='2.0.0',
    packages=find_packages(
        include=('isaac_ros_nova_interfaces', 'isaac_ros_nova_interfaces.*')),
)