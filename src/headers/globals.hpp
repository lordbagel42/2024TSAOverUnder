#include "main.h"

using namespace pros;

#ifndef GLOBALS
#define GLOBALS

/*
    only put declarations in this file
*/

extern pros::Controller master;
extern pros::Controller partner;
extern pros::Motor right_mtr_1, left_mtr_1;
extern pros::MotorGroup left_drive, right_drive;
extern pros::Motor intake;

extern int autonomousPreSet;

#endif