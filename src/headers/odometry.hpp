#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "main.h"

extern pros::Motor_Group left_drive;
extern pros::Motor_Group right_drive;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

void position();
void drawArrow();

#endif // ODOMETRY_H