
#include <hardware_interface/handle.hpp>
#include <hardware_interface/system_interface.hpp>
#include <hardware_interface/types/hardware_interface_type_values.hpp>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>

#include "uirover_hardware/uirover_canbus_interface.hpp"
#include "rclcpp/rclcpp.hpp" // IWYU pragma: keep


namespace uirover_hardware {

    hardware_interface::CallbackReturn CANInterface::on_init(const hardware_interface::HardwareComponentInterfaceParams & params) {
    
        if (hardware_interface::SystemInterface::on_init(params) != CallbackReturn::SUCCESS) {
            return CallbackReturn::ERROR;
        }

        for (size_t i = 0; i < 6; ++i) {
            arm_position_commands[i] = 0.0;
            wheel_velocity_commands[i] = 0.0;
            arm_position_states[i] = 0.0;
            arm_velocity_states[i] = 0.0;
            wheel_position_states[i] = 0.0;
            wheel_velocity_states[i] = 0.0;
        }

        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "%zu", params.hardware_info.hardware_parameters.size());

        memset(&ifr, 0, sizeof(ifr));
        memset(&addr, 0, sizeof(addr));
        CANInterface::cansock = -1;

        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CANInterface initialized successfully");

        return CallbackReturn::SUCCESS;
    
    }

    hardware_interface::CallbackReturn CANInterface::on_configure(
    const rclcpp_lifecycle::State& /*previous_state*/) {

        CANInterface::cansock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
        if (CANInterface::cansock < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error while opening CAN socket");
            return CallbackReturn::ERROR;
        }

        strncpy(CANInterface::ifr.ifr_name, "vcan0", IFNAMSIZ - 1);
        ioctl(CANInterface::cansock, SIOCGIFINDEX, &ifr);
        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CAN interface index: %d", CANInterface::ifr.ifr_ifindex);
        addr.can_family = AF_CAN;
        addr.can_ifindex = CANInterface::ifr.ifr_ifindex;
        
        int bind_result = bind(CANInterface::cansock, (struct sockaddr *)&addr, sizeof(addr));

        if (bind_result < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error in CAN socket bind: %d - %s", errno, strerror(errno)); 
            return CallbackReturn::ERROR;
        }
        
        RCLCPP_INFO(rclcpp::get_logger("uirover_hardware"), "CAN socket opened successfully");

        // send placeholder message
        canframe.can_id = 0x123;
        canframe.len = 2;
        canframe.data[0] = 0x11;
        canframe.data[1] = 0x22;
        int nbytes = ::write(CANInterface::cansock, &canframe, sizeof(struct can_frame));
        if (nbytes < 0) {
            RCLCPP_ERROR(rclcpp::get_logger("uirover_hardware"), "Error in CAN frame transmission: %d - %s", errno, strerror(errno));
            return CallbackReturn::ERROR;
        }

        // for (size_t i = 0; i < 6; ++i) {
        //     canframe.can_id = arm_can_ids[i];
        //     canframe.len = 8;
        //     canframe.data[0] = 
        // }



        return CallbackReturn::SUCCESS;
    }

    std::vector<hardware_interface::StateInterface::ConstSharedPtr> CANInterface::on_export_state_interfaces() {
        std::vector<hardware_interface::StateInterface::ConstSharedPtr> state_interfaces;

        for (size_t i = 0; i < 6; ++i) {
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                arm_map[i], hardware_interface::HW_IF_POSITION, &arm_position_states[i]));
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                arm_map[i], hardware_interface::HW_IF_VELOCITY, &arm_velocity_states[i]));
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                wheel_map[i], hardware_interface::HW_IF_VELOCITY, &wheel_velocity_states[i]));
            state_interfaces.emplace_back(new hardware_interface::StateInterface(
                wheel_map[i], hardware_interface::HW_IF_POSITION, &wheel_position_states[i]));
            
        }
        return state_interfaces;
    }

    std::vector<hardware_interface::CommandInterface::SharedPtr> CANInterface::on_export_command_interfaces() {
        std::vector<hardware_interface::CommandInterface::SharedPtr> command_interfaces;

        for (size_t i = 0; i < 6; ++i) {
            command_interfaces.emplace_back(new hardware_interface::CommandInterface(
                arm_map[i], hardware_interface::HW_IF_POSITION, &arm_position_commands[i]));
            command_interfaces.emplace_back(new hardware_interface::CommandInterface(
                wheel_map[i], hardware_interface::HW_IF_VELOCITY, &wheel_velocity_commands[i]));
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
            arm_position_states[i] = arm_position_commands[i];
            wheel_velocity_states[i] = wheel_velocity_commands[i];
        }
        
        return hardware_interface::return_type::OK;
    }

    hardware_interface::return_type CANInterface::write(
    const rclcpp::Time& /*time*/, const rclcpp::Duration& /*period*/) {
        for (size_t i = 0; i < 6; ++i) {
            canframe.can_id = arm_can_ids[i] << 5;
            canframe.can_id |= CANCmd::SET_INPUT_POS;
            canframe.len = 4;

            float arm_pos_float = static_cast<float>(arm_position_commands[i]);
            memcpy(&canframe.data[0], &arm_pos_float, sizeof(float));
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