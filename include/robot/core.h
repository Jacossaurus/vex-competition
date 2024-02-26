#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vex_thread.h"
#include "v5.h"
#include "v5_vcs.h"

using namespace vex;

vex::brain Brain;
vex::timer Timer;

controller Controller(primary);
competition Competition = competition();

motor LeftFrontMotor(PORT1, ratio18_1, IS_REVERSED);
motor LeftBackMotor(PORT2, ratio18_1, IS_REVERSED);
motor RightFrontMotor(PORT3, ratio18_1, !IS_REVERSED);
motor RightBackMotor(PORT4, ratio18_1, !IS_REVERSED);

motor LaunchMotor(PORT5, ratio18_1, true);

pneumatics Pneumatics(Brain.ThreeWirePort.A);

motor_group LeftMotors(LeftFrontMotor, LeftBackMotor);
motor_group RightMotors(RightFrontMotor, RightBackMotor);

drivetrain Drivetrain(LeftMotors, RightMotors, 2 * M_PI * WHEEL_RADIUS, OPPOSITE_WHEEL_DISTANCE, WHEEL_BASE, mm);

// Reset all motors to default positions
void reset()
{
	wait(VELOCITY_UPDATE_RATE, msec);

	Pneumatics.set(false);
	LaunchMotor.setStopping(coast);
}

// Debug functions
void clearLine()
{
	Controller.Screen.clearLine(3);
	Brain.Screen.clearScreen();
}

void log(const char *format...)
{
	clearLine();

	Brain.Screen.printAt(10, 60, format);

	Controller.Screen.print(format);

	std::cout << format << std::endl;
}
