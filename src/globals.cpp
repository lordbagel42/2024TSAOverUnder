#include "main.h"
#include "headers/globals.hpp"

// controllers
Controller master(pros::E_CONTROLLER_MASTER);
Controller partner(pros::E_CONTROLLER_PARTNER);

// motors
Motor right_mtr_1(4, MOTOR_GEARSET_18, true);
Motor left_mtr_1(1, MOTOR_GEARSET_18, false);

// motor groups
MotorGroup left_drive({left_mtr_1});
MotorGroup right_drive({right_mtr_1});

// intake
Motor intake(21);


int autonomousPreSet = 0;