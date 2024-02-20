#include "main.h"
#include "headers/globals.hpp"
#include "headers/odometry.hpp"
#include "headers/opcontrol.hpp"
#include "headers/screensim.hpp"

/**
 * Master controls left and right drive
 * T value is 12.4
 * Using curvature drive. Left stick controls speed, right stick controls the radius of a turn. Speed does not affect radius.
 *
 */

void opcontrol()
{
	// loop forever
	while (true)
	{
		// get left y and right x positions
		int leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

		// move the robot
		chassis.curvature(leftY, rightX, 12.4);

		// delay so we don't destroy the CPU
		pros::delay(10);
	}
}