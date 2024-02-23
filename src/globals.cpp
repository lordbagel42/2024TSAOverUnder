#include "main.h"
#include "headers/globals.hpp"

// controllers
Controller master(pros::E_CONTROLLER_MASTER);
Controller partner(pros::E_CONTROLLER_PARTNER);

// motors
Motor right_mtr_1(1, MOTOR_GEARSET_6, true);
Motor right_mtr_2(2, MOTOR_GEARSET_6, true);
Motor left_mtr_1(9, MOTOR_GEARSET_6, false);
Motor left_mtr_2(10, MOTOR_GEARSET_6, false);

// motor groups
MotorGroup left_drive({left_mtr_1, left_mtr_2});
MotorGroup right_drive({right_mtr_1, right_mtr_2});

// intake
Motor intake(11, MOTOR_GEARSET_18, true);

// catapult
Motor cata(16, MOTOR_GEARSET_36, false);

// auton selector
int autonSelection = BLUE_1; // specifies the default auton selected


int autonomousPreSet = 0;