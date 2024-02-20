#include "main.h"
#include "headers/globals.hpp"
#include "pros/apix.h"
#include "headers/odometry.hpp"
#include "headers/opcontrol.hpp"
#include "headers/autonomous.hpp"
#include "headers/screensim.hpp"

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
	delay(3000);
	// pros::Task screenTask(position);
	// pros::Task arrowTask(drawArrow);
	// pros::Task drawPathTask(drawPath);
	lv_obj_t *createBtn(lv_obj_t *parent, lv_coord_t 0, lv_coord_t 0, lv_coord_t 25, lv_coord_t 10, int 0, const char *title);
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