#include "main.h"
#include "headers/globals.hpp"

#include "headers/autonomous.hpp"
#include "headers/odometry.hpp"
#include "headers/selection.h"

ASSET(path1_txt);

void autonomous()
{
    // startup some display tasks
    pros::Task screenTask(position);
	pros::Task arrowTask(drawArrow);
    delay(20);

    switch (autonSelection)
    {
    case RED_1:
        // Auton function here
        break;
    case BLUE_1:
        // Auton function here
        break;

    case RED_2:
        // Auton function here
        break;
    case BLUE_2:
        // Auton function here
        break;

    case RED_3:
        // Auton function here
        break;
    case BLUE_3:
        // Auton function here
        break;

    case RED_4:
        // Auton function here
        break;
    case BLUE_4:
        // Auton function here
        break;

    case RED_5:
        // Auton function here
        break;
    case BLUE_5:
        // Auton function here
        break;

    case SKILLS:
        // Skills function here
        break;
    }
}