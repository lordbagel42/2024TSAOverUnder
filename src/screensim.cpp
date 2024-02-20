#include "main.h"
#include "headers/odometry.hpp"
#include "headers/utilities.hpp"
#include <cmath>
// #include "pros/apix.h"

/**
 * Displays current position to screen.
 */
void position()
{
	// Define a deque to store the pose.theta values and their timestamps
	std::deque<std::pair<double, uint32_t>> thetaValues;

	// Define a variable to store the maximum theta value in the last 5 seconds
	double maxTheta = 0;
	double avgSpeed = 0.0;
	double rSpeedLeft = 0.0;
	double rSpeedRight = 0.0;

	// loop forever
	while (true)
	{
		// get the pose
		lemlib::Pose pose = chassis.getPose();

		// Add the current pose.theta value and the current time to the deque
		thetaValues.push_back({pose.theta, pros::millis()});

		// Remove the values that are older than 5 seconds
		while (!thetaValues.empty() && pros::millis() - thetaValues.front().second > 5000)
		{
			thetaValues.pop_front();
		}

		// Find the maximum theta value in the deque
		maxTheta = std::max_element(thetaValues.begin(), thetaValues.end(),
									[](const std::pair<double, uint32_t> &a, const std::pair<double, uint32_t> &b)
									{
										return a.first < b.first;
									})
					   ->first;

		// print things
		screen::set_pen(COLOR_WHITE);
		screen::print(TEXT_MEDIUM, 0, "x: %f", pose.x);			// print the x position
		screen::print(TEXT_MEDIUM, 1, "y: %f", pose.y);			// print the y position
		screen::print(TEXT_MEDIUM, 2, "theta: %f", pose.theta); // print the heading
		// do not print on line 3, autonomous.cpp already prints here
		screen::print(TEXT_MEDIUM, 4, "Max Theta: %f", maxTheta);
		pros::delay(10);
	}
}

// boundary box definitions. usually constant.
int boundaryX1 = 275;
int boundaryX2 = 475;
int boundaryY1 = 20;
int boundaryY2 = 220;
int boundaryWidth = boundaryX2 - boundaryX1;
int boundaryHeight = boundaryY2 - boundaryY1;
int scale = 100 / 72;

// NEEDS TO BE A PARAMETER OF DRAWPATH, NO CLUE WHY I CAN'T JUST SHOVE IT IN.
// ASSET(path_txt); // defines the example path as an asset.

// TODO: AUTON Selector
/**
 * Draws the path of the selected auton.
 * NEEDS AUTON SELECTOR TO BE CREATED.
*/

ASSET(path1_txt);
ASSET(path2_txt);
ASSET(path3_txt);
void drawPath(asset pathName)
{

	// Parse the path file
	std::vector<lemlib::Pose> pathPoints = getData(pathName); // get list of path points

	// Draw the path
	for (int i = 0; i < pathPoints.size() - 1; i++)
	{
		lemlib::Pose point1 = pathPoints.at(i);
		lemlib::Pose point2 = pathPoints.at(i + 1);
		point1.x = boundaryX1 + (boundaryWidth / 2) + (point1.x * scale);
		point1.y = boundaryY1 + (boundaryHeight / 2) - (point1.y * scale);
		point2.x = boundaryX1 + (boundaryWidth / 2) + (point2.x * scale);
		point2.y = boundaryY1 + (boundaryHeight / 2) - (point2.y * scale);
		screen::draw_line(point1.x, point1.y, point2.x, point2.y);
		delay(10);
	}
}

/**
 * Draws a crude robot along with a arrow for heading.
 * Everything exists inside of a square on the right side of the screen.
 */
void drawArrow()
{
	// draw boundary box
	screen::set_pen(COLOR_GREEN);
	screen::draw_rect(boundaryX1, boundaryY1, boundaryX2, boundaryY2);

	// Define the center of the arrow
	int centerX = boundaryX1 + (boundaryWidth / 2);	 // arrow center X
	int centerY = boundaryY1 + (boundaryHeight / 2); // arrow center Y

	// Define the length of the arrow
	int length = 25;

	// baseline old arrow points so that stuff doesn't break
	int arrowheadX1old = 0;
	int arrowheadY1old = 0;
	int arrowheadX2old = 0;
	int arrowheadY2old = 0;
	int endXold = 0;
	int endYold = 0;

	while (true)
	{
		// clear old arrow
		screen::erase_line(endXold, endYold, arrowheadX1old, arrowheadY1old); // arrowhead 1 erase
		screen::erase_line(endXold, endYold, arrowheadX2old, arrowheadY2old); // arrowhead 2 erase
		screen::erase_line(centerX, centerY, endXold, endYold);				  // main line erase
		screen::erase_rect(centerX - 5, centerY - 5, centerX + 5, centerY + 5);

		// get pose
		lemlib::Pose pose = chassis.getPose();
		double theta_rad = (pose.theta - 90) * M_PI / 180.0; // Convert theta to degrees, make face upward
		centerX = boundaryX1 + (boundaryWidth / 2) + (pose.x * scale);
		centerY = boundaryY1 + (boundaryHeight / 2) - (pose.y * scale);

		// Calculate the end point of the arrow
		int endX = centerX + length * cos(theta_rad);
		int endY = centerY + length * sin(theta_rad);

		// Draw the main line of the arrow
		screen::set_pen(COLOR_WHITE);
		screen::draw_line(centerX, centerY, endX, endY);
		screen::draw_rect(centerX - 5, centerY - 5, centerX + 5, centerY + 5);

		// Draw the arrowhead
		// Calculate the points for the arrowhead
		int arrowheadLength = 10;
		int arrowheadX1 = endX - arrowheadLength * cos(theta_rad + M_PI / 6);
		int arrowheadY1 = endY - arrowheadLength * sin(theta_rad + M_PI / 6);
		int arrowheadX2 = endX - arrowheadLength * cos(theta_rad - M_PI / 6);
		int arrowheadY2 = endY - arrowheadLength * sin(theta_rad - M_PI / 6);

		endXold = endX;
		endYold = endY;
		arrowheadX1old = arrowheadX1;
		arrowheadY1old = arrowheadY1;
		arrowheadX2old = arrowheadX2;
		arrowheadY2old = arrowheadY2;

		// Draw the lines for the arrowhead
		screen::set_pen(COLOR_WHITE);
		screen::draw_line(endX, endY, arrowheadX1, arrowheadY1);
		screen::draw_line(endX, endY, arrowheadX2, arrowheadY2);

	}
}