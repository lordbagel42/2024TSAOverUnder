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
		// intake if R1 pressed, spit if R2 pressed
		if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intake = -127;
		}
		else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			intake = 127;
		}
		else {
			intake = 0;
		}

		// delay so we don't destroy the CPU
		pros::delay(10);
	}
}
