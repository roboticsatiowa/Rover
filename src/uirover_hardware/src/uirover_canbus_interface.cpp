#include <hardware_interface/hardware_info.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can/raw.h>
#include <linux/can.h>
#include <cstring>
#include <errno.h>
#include <cstdint>
#include <cstddef>
#include <chrono>

#include <hardware_interface/types/hardware_interface_type_values.hpp>
#include <hardware_interface/system_interface.hpp>
#include <hardware_interface/handle.hpp>
#include "uirover_hardware/uirover_canbus_interface.hpp"
#include "rclcpp/rclcpp.hpp" // IWYU pragma: keep

namespace uirover_hardware {

    int CANInterface::send_cmd(uint8_t node_id, uint8_t cmd, uint8_t len, const uint8_t* data) {
        canframe.can_id = node_id << 5 | cmd;
        canframe.len = len;
        memcpy(canframe.data, data, len);
        int nbytes = ::write(CANInterface::cansock, &canframe, sizeof(struct can_frame));
        if (nbytes < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error in CAN frame transmission: %d - %s", errno, strerror(errno));
            return -1;
        }
        return 0;
    }

    int CANInterface::send_rtr(uint8_t node_id, uint8_t cmd) {
        canframe.can_id = node_id << 5 | cmd | CAN_RTR_FLAG;
        canframe.len = 0;
        int nbytes = ::write(CANInterface::cansock, &canframe, sizeof(struct can_frame));
        if (nbytes < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error in CAN frame transmission: %d - %s", errno, strerror(errno));
            return -1;
        }
        return 0;
    }



    hardware_interface::CallbackReturn CANInterface::on_init(const hardware_interface::HardwareComponentInterfaceParams& params) {

        if (hardware_interface::SystemInterface::on_init(params) != CallbackReturn::SUCCESS) {
            return CallbackReturn::ERROR;
        }

        for (size_t i = 0; i < 6; ++i) {
            odrives[i].node_id = 0x3f;
            odrives[i].joint_name = "arm_j" + std::to_string(i);
            odrives[i].position_command = 0;
            odrives[i].position_state = 0;
            odrives[i].velocity_state = 0;
        }

        odrives[0].node_id = 0x07;

        for (size_t i = 0; i < 6; ++i) {
            wheels[i].node_id = 0x00; // TODO placeholder
            wheels[i].velocity_command = 0;
            wheels[i].position_state = 0;
            wheels[i].velocity_state = 0;
        }

        wheels[0].joint_name = "bl_wheel_joint";
        wheels[1].joint_name = "br_wheel_joint";
        wheels[2].joint_name = "ml_wheel_joint";
        wheels[3].joint_name = "mr_wheel_joint";
        wheels[4].joint_name = "fl_wheel_joint";
        wheels[5].joint_name = "fr_wheel_joint";

        memset(&ifr, 0, sizeof(ifr));
        memset(&addr, 0, sizeof(addr));
        memset(&canframe, 0, sizeof(canframe));

        for (hardware_interface::ComponentInfo info : params.hardware_info.joints) {
            for (Odrive& odrive : odrives) {
                if (odrive.joint_name == info.name) {
                    odrive.serial_num = std::stol(info.parameters.at("odrive_serial_number"), nullptr, 16);
                }
            }
        }

        for (Odrive odrive : odrives) {
            RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "%s: %lu", odrive.joint_name.c_str(), odrive.serial_num);
        }

        CANInterface::cansock = -1;

        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CANInterface initialized successfully");
        return CallbackReturn::SUCCESS;

    }

    hardware_interface::CallbackReturn CANInterface::on_configure(
        const rclcpp_lifecycle::State& /*previous_state*/) {

        CANInterface::cansock = socket(PF_CAN, SOCK_RAW | SOCK_NONBLOCK, CAN_RAW);
        if (CANInterface::cansock < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error while opening CAN socket");
            return CallbackReturn::ERROR;
        }

        strncpy(CANInterface::ifr.ifr_name, "can0", IFNAMSIZ - 1);
        ioctl(CANInterface::cansock, SIOCGIFINDEX, &ifr);
        addr.can_family = AF_CAN;
        addr.can_ifindex = CANInterface::ifr.ifr_ifindex;

        int bind_result = bind(CANInterface::cansock, (struct sockaddr*)&addr, sizeof(addr));

        if (bind_result < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error in CAN socket bind: %d - %s", errno, strerror(errno));
            return CallbackReturn::ERROR;
        }

        for (Odrive odrive : odrives) {
            uint8_t mode_data[8] = { 3,0,0,0,1,0,0,0 };
            if (send_cmd(odrive.node_id, ODRIVE_CMDS::SET_CONTROLLER_MODE, 8, mode_data) != 0) {
                RCLCPP_WARN(rclcpp::get_logger("uirover_hardware"), "Failed to set controller mode for node 0x%02x", odrive.node_id);
            }
            uint8_t axis_state_data[8] = {8,0,0,0,0,0,0,0};
            send_cmd(odrive.node_id, ODRIVE_CMDS::SET_AXIS_STATE, 8, axis_state_data);
        }

        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CAN socket opened successfully");

        // // attempt to re-address odrives every 2 sec until timout (10 sec) or success
        // std::chrono::time_point start = std::chrono::steady_clock::now();
        // std::chrono::time_point last_cmd = std::chrono::steady_clock::now();
        // send_rtr(0x3F, ODRIVE_CMDS::ADDRESS);
        // while (std::chrono::steady_clock::now() - start < std::chrono::seconds(10)) {
        //     if (std::chrono::steady_clock::now() - last_cmd > std::chrono::seconds(2)) {
        //         send_rtr(0x3F, ODRIVE_CMDS::ADDRESS);
        //         last_cmd = std::chrono::steady_clock::now();
        //         RCLCPP_WARN(rclcpp::get_logger("uirover_hardware"), "No response from address command. Retrying...");
        //     }

        //     memset(&canframe.data, 0, sizeof(uint8_t[8]));
        //     int nbytes = ::read(cansock, &canframe, sizeof(struct can_frame));
        //     if (nbytes <= 0) {
        //         continue;
        //     }

        //     // lower 5 bits are command, upper bits (shifted right 5) are node id
        //     int cmd = static_cast<int>(canframe.can_id & 0x1F);
        //     int node_id = static_cast<int>((canframe.can_id >> 5) & 0x7F);

        //     // assemble little-endian 64-bit serial number from CAN data bytes
        //     uint64_t serial_num = (data[0]<<0) | (data[1]<<8) | (data[2]<<16) | ((unsigned)data[3]<<24);


        //     if (cmd == 6) {
        //         RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "%lu", serial_num);
        //         for (Odrive odrive : odrives) {

        //         }

        //     }

        // }

        return CallbackReturn::SUCCESS;
    }

    std::vector<hardware_interface::StateInterface::ConstSharedPtr> CANInterface::on_export_state_interfaces() {
        std::vector<hardware_interface::StateInterface::ConstSharedPtr> state_interfaces;

        for (size_t i = 0; i < 6; ++i) {
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                odrives[i].joint_name, hardware_interface::HW_IF_POSITION, &odrives[i].position_state));
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                odrives[i].joint_name, hardware_interface::HW_IF_VELOCITY, &odrives[i].velocity_state));
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                wheels[i].joint_name, hardware_interface::HW_IF_VELOCITY, &wheels[i].velocity_state));
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                wheels[i].joint_name, hardware_interface::HW_IF_POSITION, &wheels[i].position_state));

        }
        return state_interfaces;
    }

    std::vector<hardware_interface::CommandInterface::SharedPtr> CANInterface::on_export_command_interfaces() {
        std::vector<hardware_interface::CommandInterface::SharedPtr> command_interfaces;

        for (size_t i = 0; i < 6; ++i) {
            command_interfaces.emplace_back(new hardware_interface::CommandInterface(
                odrives[i].joint_name, hardware_interface::HW_IF_POSITION, &odrives[i].position_command));
            command_interfaces.emplace_back(new hardware_interface::CommandInterface(
                wheels[i].joint_name, hardware_interface::HW_IF_VELOCITY, &wheels[i].velocity_command));
        }

        return command_interfaces;
    }

    hardware_interface::CallbackReturn CANInterface::on_activate(
        const rclcpp_lifecycle::State& /*previous_state*/) {
        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CANInterface activated");
        return CallbackReturn::SUCCESS;
    }

    hardware_interface::CallbackReturn CANInterface::on_deactivate(
        const rclcpp_lifecycle::State& /*previous_state*/) {
        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CANInterface deactivated");
        return CallbackReturn::SUCCESS;
    }

    hardware_interface::return_type CANInterface::read(
        const rclcpp::Time& /*time*/, const rclcpp::Duration& /*period*/) {
        // TODO placeholder. currently returning commanded positions/velocities as states
        for (size_t i = 0; i < 6; ++i) {
            odrives[i].position_state = odrives[i].position_command;
            wheels[i].velocity_state = wheels[i].velocity_command;
        }

        return hardware_interface::return_type::OK;
    }

    hardware_interface::return_type CANInterface::write(
        const rclcpp::Time& /*time*/, const rclcpp::Duration& /*period*/) {
        for (size_t i = 0; i < 6; ++i) {
            canframe.can_id = odrives[i].node_id << 5;
            canframe.can_id |= ODRIVE_CMDS::SET_INPUT_POS;
            canframe.len = 8;

            float arm_pos_float = static_cast<float>(odrives[i].position_command);
            memcpy(&canframe.data[0], &arm_pos_float, sizeof(float));
            memset(&canframe.data[4], 1000, sizeof(uint16_t));
            memset(&canframe.data[6], 1000, sizeof(uint16_t));
            int nbytes = ::write(CANInterface::cansock, &canframe, sizeof(struct can_frame));
            if (nbytes < 0) {
                RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error in CAN frame transmission: %d - %s", errno, strerror(errno));
                return hardware_interface::return_type::ERROR;
            }
        }


        return hardware_interface::return_type::OK;
    }

    CANInterface::~CANInterface() {
        if (cansock >= 0) {
            close(cansock);
        }
    }

}

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(uirover_hardware::CANInterface, hardware_interface::SystemInterface)