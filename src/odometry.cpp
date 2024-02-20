#include "main.h"
#include "headers/odometry.hpp"

// motors
Motor right_mtr_1(4, MOTOR_GEARSET_18, true);
Motor left_mtr_1(1, MOTOR_GEARSET_18, false);
// motor groups
MotorGroup left_drive({left_mtr_1});
MotorGroup right_drive({right_mtr_1});

// drivetrain
lemlib::Drivetrain drivetrain{
	&left_drive,  // left drivetrain motors
	&right_drive, // right drivetrain motors
	10,			  // track width
	3.25,		  // wheel diameter
	200,		  // wheel rpm
	2			  // chase power
};

// encoders
pros::ADIEncoder right_enc('C', 'D', true); // ports C and D
pros::ADIEncoder left_enc('A', 'B', false); // ports A and B

// tracking wheels
lemlib::TrackingWheel left_tracking_wheel(&left_enc, 3.25, -5);
lemlib::TrackingWheel right_tracking_wheel(&right_enc, 3.25, 5);

// odometry
lemlib::OdomSensors sensors{
	&left_tracking_wheel,  // vertical tracking wheel 1
	&right_tracking_wheel, // vertical tracking wheel 2
	nullptr,			   // no horizontal tracking wheel
	nullptr,			   // no secondary horizontal tracking wheel
	nullptr				   // no inertial sensor. sadly. :(
};

// lateral motion controller
lemlib::ControllerSettings lateralController(
	1,	 // proportional gain (kP)
	0,	 // integral gain (kI)
	0,	 // derivative gain (kD)
	3,	 // anti windup
	1,	 // small error range, in inches
	100, // small error range timeout, in milliseconds
	3,	 // large error range, in inches
	500, // large error range timeout, in millisecondsF
	20	 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(
	8,	 // proportional gain (kP)
	0,	 // integral gain (kI)
	20,	 // derivative gain (kD)
	3,	 // anti windup
	1,	 // small error range, in degrees
	100, // small error range timeout, in milliseconds
	3,	 // large error range, in degrees
	500, // large error range timeout, in milliseconds
	0	 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);