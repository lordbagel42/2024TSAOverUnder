#include "main.h"
#include "headers/autonomous.hpp"
#include "headers/odometry.hpp"

ASSET(example_txt);
void autonomous()
{
    // variables needed for things
    int turnRate = 32;
    screen::print(TEXT_MEDIUM, 3, "Desired RPM: %d", turnRate);
    int loops = 0;

    chassis.moveToPose(0, 50, 90, 3000);
}