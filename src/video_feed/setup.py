from setuptools import find_packages, setup

package_name = 'video_feed'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch/', ['launch/cameras.launch.py']),
        ('share/' + package_name + '/launch/', ['launch/camera1.yaml']),
        ('share/' + package_name + '/launch/', ['launch/camera2.yaml']),
        ('share/' + package_name + '/launch/', ['launch/cams.launch.xml']),
        

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ethan',
    maintainer_email='holterethan@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
)
