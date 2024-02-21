#include "main.h"

using namespace pros;

#ifndef GLOBALS
#define GLOBALS

// controllers
extern pros::Controller master;
extern pros::Controller partner;

// motors
extern pros::Motor right_mtr_1, left_mtr_1;

// motor groups
extern pros::MotorGroup left_drive, right_drive;
extern pros::Motor intake;

// auton selector
extern int autonSelection;
enum AutonEnum {BLUE_1 = -1, BLUE_2 = -2, BLUE_3 = -3, BLUE_4 = -4, BLUE_5 = -5, RED_1 = 1, RED_2 = 2, RED_3 = 3, RED_4 = 4, RED_5 = 5, NOTHING = 10, SKILLS = 0};

#endif