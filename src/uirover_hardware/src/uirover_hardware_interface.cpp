// Copyright (c) 2022, Stogl Robotics Consulting UG (haftungsbeschränkt) (template)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <limits>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "uirover_hardware/uirover_hardware_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "rclcpp/rclcpp.hpp" // IWYU pragma: keep

namespace uirover_hardware {

  hardware_interface::CallbackReturn UiroverHardwareInterface::on_init(const hardware_interface::HardwareInfo& info) {

    if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS) {
      return CallbackReturn::ERROR;
    }

    // Get number of joint state/command interfaces from URDF (stored in info_)
    hw_states_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());
    prev_hw_commands_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());

    RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "Hardware interface initialized successfully.");

    return CallbackReturn::SUCCESS;
  }

  hardware_interface::CallbackReturn UiroverHardwareInterface::on_configure(
    const rclcpp_lifecycle::State& /*previous_state*/) {

    // https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
    // open the serial port
    teensy_fd = open("/dev/ttyTEENSY", O_RDWR | O_NOCTTY | O_SYNC);
    if (teensy_fd == -1) {
      RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Failed to open serial port /dev/ttyTEENSY. Error code: %d - %s", errno, strerror(errno));
      return CallbackReturn::ERROR;
    }
    
    // Set up the serial port
    if (tcgetattr(teensy_fd, &tty) != 0) {
      return CallbackReturn::ERROR;
    }

    // Configure the serial port settings
    tty.c_cflag &= ~PARENB;        // No parity
    tty.c_cflag &= ~CSTOPB;        // 1 stop bit
    tty.c_cflag &= ~CSIZE;         // Clear size mask. prep for setting number of data bits below
    tty.c_cflag |= CS8;            // 8 data bits
    tty.c_cflag &= ~CRTSCTS;       // No RTS and CTS pins (hardware flow control)
    tty.c_cflag |= CREAD | CLOCAL; // Enable receiver, ignore modem control lines
    tty.c_lflag &= ~ICANON;        // No canonical mode
    tty.c_lflag &= ~ECHO;          // Disable echo
    tty.c_lflag &= ~ECHOE;         // Disable erasure
    tty.c_lflag &= ~ECHONL;        // Disable new-line echo
    tty.c_lflag &= ~ISIG;          // Disable signals
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);  // Turn off s/w flow ctrl   
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received bytes
    tty.c_oflag &= ~OPOST;         // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR;         // Prevent conversion of newline to carriage return/line feed

    // read op will block for 0.01 seconds if no data is available. Timeout was chosen completely arbitrarily.
    tty.c_cc[VMIN] = 0;     // No minimum number of bytes to read
    tty.c_cc[VTIME] = 0.1;  // 0.1 deciseconds (0.01 seconds) timeout for read

    // Set the baud rate
    cfsetspeed(&tty, baudrate);

    // Save tty settings, also checking for error
    if (tcsetattr(teensy_fd, TCSANOW, &tty) != 0) {
      return CallbackReturn::ERROR;
    }

    RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "Hardware interface configured successfully.");

    return CallbackReturn::SUCCESS;
  }

  std::vector<hardware_interface::StateInterface::ConstSharedPtr> UiroverHardwareInterface::on_export_state_interfaces() {
    std::vector<hardware_interface::StateInterface::ConstSharedPtr> state_interfaces;

    for (size_t i = 0; i < info_.joints.size(); ++i) {
      state_interfaces.emplace_back(new hardware_interface::StateInterface(
        info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_states_[i]));
    }

    return state_interfaces;
  }

  std::vector<hardware_interface::CommandInterface::SharedPtr> UiroverHardwareInterface::on_export_command_interfaces() {
    std::vector<hardware_interface::CommandInterface::SharedPtr> command_interfaces;

    command_interfaces.emplace_back(new hardware_interface::CommandInterface(
      "fl_wheel_joint", hardware_interface::HW_IF_VELOCITY, &fl_wheel_velocity_command_));
    command_interfaces.emplace_back(new hardware_interface::CommandInterface(
      "fr_wheel_joint", hardware_interface::HW_IF_VELOCITY, &fr_wheel_velocity_command_));
    command_interfaces.emplace_back(new hardware_interface::CommandInterface(
      "ml_wheel_joint", hardware_interface::HW_IF_VELOCITY, &ml_wheel_velocity_command_));
    command_interfaces.emplace_back(new hardware_interface::CommandInterface(
      "mr_wheel_joint", hardware_interface::HW_IF_VELOCITY, &mr_wheel_velocity_command_));
    command_interfaces.emplace_back(new hardware_interface::CommandInterface(
      "bl_wheel_joint", hardware_interface::HW_IF_VELOCITY, &bl_wheel_velocity_command_));
    command_interfaces.emplace_back(new hardware_interface::CommandInterface(
      "br_wheel_joint", hardware_interface::HW_IF_VELOCITY, &br_wheel_velocity_command_));

    return command_interfaces;
  }

  hardware_interface::CallbackReturn UiroverHardwareInterface::on_activate(
    const rclcpp_lifecycle::State& /*previous_state*/) {
      RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "recieved activation signal");


    return CallbackReturn::SUCCESS;
  }

  hardware_interface::CallbackReturn UiroverHardwareInterface::on_deactivate(
    const rclcpp_lifecycle::State& /*previous_state*/) {
    // TODO(anyone): prepare the robot to stop receiving commands

    return CallbackReturn::SUCCESS;
  }

  hardware_interface::return_type UiroverHardwareInterface::read(
    const rclcpp::Time& /*time*/, const rclcpp::Duration& /*period*/) {

      // TODO: this is a placeholder since we don't have any sensors to read from yet
      for (size_t i = 0; i < info_.joints.size(); ++i) {
        hw_states_[i] = 0.0;
      }

    return hardware_interface::return_type::OK;
  }

  hardware_interface::return_type UiroverHardwareInterface::write(
    const rclcpp::Time& /*time*/, const rclcpp::Duration& /*period*/) {
      std::string msg = "l " + std::to_string((int)(ml_wheel_velocity_command_)) + " " + std::to_string((int)(mr_wheel_velocity_command_)) + "\n\r";
      serial_write(msg);
    return hardware_interface::return_type::OK;
  }
  
  void UiroverHardwareInterface::serial_write(std::string msg) {
    ::write((int)teensy_fd, msg.c_str(), msg.size());
  }

  UiroverHardwareInterface::~UiroverHardwareInterface() {
    close(teensy_fd);
  }

  
}  // namespace uirover_hardware

#include "pluginlib/class_list_macros.hpp"


PLUGINLIB_EXPORT_CLASS(
  uirover_hardware::UiroverHardwareInterface, hardware_interface::SystemInterface)
