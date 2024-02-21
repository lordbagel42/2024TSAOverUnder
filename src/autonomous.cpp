#include "main.h"
#include "headers/globals.hpp"
#include "headers/autonomous.hpp"
#include "headers/odometry.hpp"
#include "autoSelect/selection.h"

ASSET(path1_txt);
void autonomous()
{
    if (selector::auton == 1)
    { // run auton for Front Red
        // variables needed for things
        int turnRate = 32;
        screen::print(TEXT_MEDIUM, 3, "Desired RPM: %d", turnRate);
        int loops = 0;

        chassis.moveToPose(0, 50, 90, 3000);
    }

    else if (selector::auton == 2) // run auton for Back Red
    {
    }

    else if (selector::auton == 3) // no auton for Red
    {
    }

    else if (selector::auton == -1) // run auton for Front Blue
    {
    }
    
    else if (selector::auton == -2) // run auton for Back Blue
    {
    }

    else if (selector::auton == -3) // no auton for Blue
    {
    }

    else if (selector::auton == 0) // skills auton
    {
    }

    else // no auton
    {
    };
}