#include "config.h"

/**
* autonomous record path.
**/
std::string record_path = "/usd/oms6-";
int record_id = 1;
std::string record_full_path = record_path + std::to_string(record_id);

/**
* The autonomous part this is to operate.
**/
bool is_blue = true;

/**
* The motors to be used in the opcontrol and autonomous.
**/
pros::Motor left_front_wheel_motor (LEFT_FRONT_WHEEL_MOTOR, true);
pros::Motor left_front_wheel_motor_rev (LEFT_FRONT_WHEEL_MOTOR_REV);
pros::Motor right_front_wheel_motor (RIGHT_FRONT_WHEEL_MOTOR);
pros::Motor right_front_wheel_motor_rev (RIGHT_FRONT_WHEEL_MOTOR_REV, true);
pros::Motor left_back_wheel_motor (LEFT_BACK_WHEEL_MOTOR, true);
pros::Motor left_back_wheel_motor_rev (LEFT_BACK_WHEEL_MOTOR_REV);
pros::Motor right_back_wheel_motor (RIGHT_BACK_WHEEL_MOTOR);
pros::Motor right_back_wheel_motor_rev (RIGHT_BACK_WHEEL_MOTOR_REV, true);
pros::Motor left_throw_motor (LEFT_THROW_MOTOR);
pros::Motor right_throw_motor (RIGHT_THROW_MOTOR, true);
pros::Motor claw_motor (CLAW_MOTOR);
pros::Motor arm_motor (ARM_MOTOR);
