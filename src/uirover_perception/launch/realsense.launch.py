from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import SetParameter


def generate_launch_description():
    return LaunchDescription(
        [
            # Hack to disable IR emitter
            SetParameter(name='depth_module.emitter_enabled', value=0),
            
            IncludeLaunchDescription(
                AnyLaunchDescriptionSource(
                    PathJoinSubstitution(
                        [
                            FindPackageShare("realsense2_camera"),
                            "launch/rs_launch.py",
                        ]
                    )
                ),
                launch_arguments={
                    "camera_name": "realsense",
                    "camera_namespace": "rover",
                    "enable_rgbd": "true",
                    "enable_gyro": "true",
                    "enable_accel": "true",
                    "unite_imu_method": "2",
                    "enable_infra1": "true",
                    "enable_infra2": "true",
                    "enable_sync": "true",
                    "align_depth.enable": "true",
                    "pointcloud.enable": "true",
                }.items(),
            )
        ]
    )


# Default launch parameters:
"""
"camera_name": "camera",
"camera_namespace": "camera",
"serial_no": "''",
"usb_port_id": "''",
"device_type": "''",
"config_file": "''",
"json_file_path": "''",
"initial_reset": "false",
"accelerate_gpu_with_glsl": "false",
"rosbag_filename": "''",
"rosbag_loop": "false",
"log_level": "info",
"output": "screen",
"enable_color": "true",
"rgb_camera.color_profile": "0,0,0",
"rgb_camera.color_format": "RGB8",
"rgb_camera.enable_auto_exposure": "true",
"enable_depth": "true",
"enable_infra": "false",
"enable_infra1": "false",
"enable_infra2": "false",
"depth_module.depth_profile": "0,0,0",
"depth_module.depth_format": "Z16",
"depth_module.infra_profile": "0,0,0",
"depth_module.infra_format": "RGB8",
"depth_module.infra1_format": "Y8",
"depth_module.infra2_format": "Y8",
"depth_module.color_profile": "0,0,0",
"depth_module.color_format": "RGB8",
"depth_module.exposure": "8500",
"depth_module.gain": "16",
"depth_module.hdr_enabled": "false",
"depth_module.enable_auto_exposure": "true",
"depth_module.exposure.1": "7500",
"depth_module.gain.1": "16",
"depth_module.exposure.2": "1",
"depth_module.gain.2": "16",
"enable_sync": "false",
"depth_module.inter_cam_sync_mode": "0",
"enable_rgbd": "false",
"enable_gyro": "false",
"enable_accel": "false",
"gyro_fps": "0",
"enable_motion": "false",
"accel_fps": "0",
"unite_imu_method": "0",
"clip_distance": "-2.",
"angular_velocity_cov": "0.01",
"linear_accel_cov": "0.01",
"diagnostics_period": "0.0",
"publish_tf": "true",
"tf_publish_rate": "0.0",
"pointcloud.enable": "false",
"pointcloud.stream_filter": "2",
"pointcloud.stream_index_filter": "0",
"pointcloud.ordered_pc": "false",
"pointcloud.allow_no_texture_points": "false",
"align_depth.enable": "false",
"colorizer.enable": "false",
"decimation_filter.enable": "false",
"rotation_filter.enable": "false",
"rotation_filter.rotation": "0.0",
"spatial_filter.enable": "false",
"temporal_filter.enable": "false",
"disparity_filter.enable": "false",
"hole_filling_filter.enable": "false",
"hdr_merge.enable": "false",
"wait_for_device_timeout": "-1.",
"reconnect_timeout": "6.",
"base_frame_id": "link",
"""
