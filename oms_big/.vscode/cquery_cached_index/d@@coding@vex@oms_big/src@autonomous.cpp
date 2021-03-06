#include "config.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  FILE* record = fopen (record_path, "r");

  pros::lcd::set_text(3, "autonomous mode.\n");
  while (true) {
    // Arcade control
    std::int32_t straight_power = 0, turn_power = 0;
    fscanf(record, " %d %d ", &straight_power, &turn_power);
    if (!is_blue) {
      turn_power = - turn_power;
    }

    std::int32_t left_wheel_power = straight_power + turn_power;
    std::int32_t right_wheel_power = straight_power - turn_power;

    left_front_wheel_motor.move_velocity(left_wheel_power);
    left_middle_wheel_motor.move_velocity(left_wheel_power);
    left_back_wheel_motor.move_velocity(left_wheel_power);

  	right_front_wheel_motor.move_velocity(right_wheel_power);
  	right_middle_wheel_motor.move_velocity(right_wheel_power);
  	right_back_wheel_motor.move_velocity(right_wheel_power);

    // Scroll Control
    std::int32_t scroll_power = 0;
    fscanf(record, " %d ", &scroll_power);
    scroll_motor.move_velocity(scroll_power);

    // Eject Control
    std::int32_t eject_power = 0;
    fscanf(record, " %d ", &eject_power);
    eject_left_motor.move_velocity(eject_power);
    eject_right_motor.move_velocity(eject_power);

    // Arm Control
    std::int32_t arm_power = 0;
    fscanf(record, " %d ", &arm_power);
    left_arm_motor.move_velocity(arm_power);
    right_arm_motor.move_velocity(arm_power);

    // Claw Control
    std::int32_t claw_power = 0;
    fscanf(record, " %d ", &claw_power);
    claw_motor.move_velocity(claw_power);

    printf("%d %d %d %d %d %d\n", straight_power, turn_power, scroll_power, eject_power, arm_power, claw_power);
    pros::lcd::print(4, "%d %d %d %d %d %d\n", straight_power, turn_power, scroll_power, eject_power, arm_power, claw_power);

    // Delay
    pros::delay(delay_time);
  }
}
