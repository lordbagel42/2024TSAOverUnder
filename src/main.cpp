#include "main.h"
#include "headers/globals.hpp"

#include "pros/apix.h"
#include "headers/odometry.hpp"
#include "headers/opcontrol.hpp"
#include "headers/autonomous.hpp"
#include "headers/screensim.hpp"
#include "headers/selection.h"

// #include "lemlib/api.hpp"
// Included in the main.h file already!

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	chassis.calibrate();
	chassis.setPose(-24.148, 1.067, 0); // X: 0, Y: 0, Heading: 0
    lv_init();
	delay(3000);
	selectorInit();
	// pros::Task screenTask(position);
	// pros::Task arrowTask(drawArrow);
	// pros::Task drawPathTask(drawPath);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

// opcontrol defined in opcontrol.cpp
// autonomous defined in autonomous.cpp
// odom defined in odometry.cpp
// screen simulation defined in screensim.cpp
// utilities are in utilities.cpp
// initialize is in main.cpp (HERE)