#ifndef UIROVER_HARDWARE__UIROVER_CANBUS_INTERFACE_HPP_
#define UIROVER_HARDWARE__UIROVER_CANBUS_INTERFACE_HPP_

#include <linux/can.h>
#include <net/if.h>
#include <termios.h>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp_lifecycle/state.hpp"

namespace CANCmd {

constexpr uint16_t GET_VERSION = 0x000;
constexpr uint16_t HEARTBEAT = 0x001;
constexpr uint16_t ESTOP = 0x002;
constexpr uint16_t GET_ERROR = 0x003;
constexpr uint16_t RX_SDO = 0x004;
constexpr uint16_t TX_SDO = 0x005;
constexpr uint16_t ADDRESS = 0x006;
constexpr uint16_t SET_AXIS_STATE = 0x007;
constexpr uint16_t GET_ENCODER_ESTIMATES = 0x009;
constexpr uint16_t SET_CONTROLLER_MODE = 0x00B;
constexpr uint16_t SET_INPUT_POS = 0x00C;
constexpr uint16_t SET_INPUT_VEL = 0x00D;
constexpr uint16_t SET_INPUT_TORQUE = 0x00E;
constexpr uint16_t SET_LIMITS = 0x00F;
constexpr uint16_t SET_TRAJ_VEL_LIMIT = 0x011;
constexpr uint16_t SET_TRAJ_ACCEL_LIMITS = 0x012;
constexpr uint16_t SET_TRAJ_INERTIA = 0x013;
constexpr uint16_t GET_IQ = 0x014;
constexpr uint16_t GET_TEMPERATURE = 0x015;
constexpr uint16_t REBOOT = 0x016;
constexpr uint16_t GET_BUS_VOLTAGE_CURRENT = 0x017;
constexpr uint16_t CLEAR_ERRORS = 0x018;
constexpr uint16_t SET_ABSOLUTE_POSITION = 0x019;
constexpr uint16_t SET_POS_GAIN = 0x01A;
constexpr uint16_t SET_VEL_GAINS = 0x01B;
constexpr uint16_t GET_TORQUES = 0x01C;
constexpr uint16_t GET_POWERS = 0x01D;
constexpr uint16_t ENTER_DFU_MODE = 0x01F;

} // namespace CANCmd

namespace uirover_hardware {
class CANInterface : public hardware_interface::SystemInterface {
public:
  hardware_interface::CallbackReturn
  on_init(const hardware_interface::HardwareComponentInterfaceParams &params)
      override;

  hardware_interface::CallbackReturn
  on_configure(const rclcpp_lifecycle::State &previous_state) override;

  std::vector<hardware_interface::StateInterface::ConstSharedPtr>
  on_export_state_interfaces() override;

  std::vector<hardware_interface::CommandInterface::SharedPtr>
  on_export_command_interfaces() override;

  hardware_interface::CallbackReturn
  on_activate(const rclcpp_lifecycle::State &previous_state) override;

  hardware_interface::CallbackReturn
  on_deactivate(const rclcpp_lifecycle::State &previous_state) override;

  hardware_interface::return_type read(const rclcpp::Time &time,
                                       const rclcpp::Duration &period) override;

  hardware_interface::return_type
  write(const rclcpp::Time &time, const rclcpp::Duration &period) override;

  ~CANInterface();

private:
  int cansock;
  struct sockaddr_can addr;  // CAN socket address
  struct ifreq ifr;          // interface request
  struct can_frame canframe; // CAN frame

  std::string wheel_map[6] = {"fl_wheel_joint", "fr_wheel_joint",
                              "ml_wheel_joint", "mr_wheel_joint",
                              "bl_wheel_joint", "br_wheel_joint"};

  std::string arm_map[6] = {"arm_j0", "arm_j1", "arm_j2",
                            "arm_j3", "arm_j4", "arm_j5"};

  // 6 bit identifiers
  int wheel_can_ids[6] = {0x010, 0x011, 0x012, 0x013, 0x014, 0x015};
  int arm_can_ids[6] = {0x020, 0x021, 0x022, 0x023, 0x024, 0x025};

  // commands
  double arm_position_commands[6];
  double wheel_velocity_commands[6];

  // states - velocity
  double arm_velocity_states[6];
  double wheel_velocity_states[6];

  // states - position
  double arm_position_states[6];
  double wheel_position_states[6];
};

} // namespace uirover_hardware

#endif // UIROVER_HARDWARE__UIROVER_CANBUS_INTERFACE_HPP_