from setuptools import find_packages
from setuptools import setup

setup(
    name='camera_detection_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('camera_detection_interfaces', 'camera_detection_interfaces.*')),
)
