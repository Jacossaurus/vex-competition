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

motor SpinnyMotor(PORT5, ratio18_1, SPINNY_MOTOR_REVERSED);
motor ArmMotors(PORT6, ratio18_1, false);

motor EndGameMotor1(PORT7, ratio18_1, false);
motor EndGameMotor2(PORT8, ratio18_1, true);

motor_group LeftMotors(LeftFrontMotor, LeftBackMotor);
motor_group RightMotors(RightFrontMotor, RightBackMotor);

drivetrain Drivetrain(LeftMotors, RightMotors, 2 * M_PI * WHEEL_RADIUS, OPPOSITE_WHEEL_DISTANCE, WHEEL_BASE, mm);

motor_group EndGameMotors(EndGameMotor1, EndGameMotor2);

// Reset all motors to default positions
void reset()
{
	wait(VELOCITY_UPDATE_RATE, msec);

	ArmMotors.setStopping(hold);
	EndGameMotors.setStopping(hold);
}

// Debug functions
void clearLine()
{
	Controller.Screen.clearLine(3);
	Brain.Screen.clearScreen();
}

void log(const char *message)
{
	Brain.Screen.clearScreen();

	Brain.Screen.printAt(10, 60, message);

	clearLine();

	Controller.Screen.print(message);

	std::cout << message << std::endl;
}