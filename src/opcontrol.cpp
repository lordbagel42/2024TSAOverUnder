#include "main.h"
#include "headers/odometry.hpp"
#include "headers/opcontrol.hpp"
#include "headers/screensim.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 */
pros::Controller controller(E_CONTROLLER_MASTER);

void opcontrol()
{
	// loop forever
	while (true)
	{
		// get left y and right x positions
		int leftY = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

		// move the robot
		chassis.curvature(leftY, rightX);

		// delay so we don't destroy the CPU
		pros::delay(10);
	}
}