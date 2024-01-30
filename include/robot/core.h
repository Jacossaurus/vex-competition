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

controller Controller = controller(primary);
competition Competition = competition();

motor LeftFrontMotor = motor(PORT1, ratio18_1, IS_REVERSED);
motor LeftBackMotor = motor(PORT2, ratio18_1, IS_REVERSED);
motor RightFrontMotor = motor(PORT3, ratio18_1, !IS_REVERSED);
motor RightBackMotor = motor(PORT4, ratio18_1, !IS_REVERSED);

motor SpinnyMotor = motor(PORT5, ratio18_1, SPINNY_MOTOR_REVERSED);
motor ArmMotors = motor(PORT6, ratio18_1, false);

motor EndGameMotor1 = motor(PORT7, ratio18_1, false);
motor EndGameMotor2 = motor(PORT8, ratio18_1, true);

motor_group LeftMotors = motor_group(LeftFrontMotor, LeftBackMotor);
motor_group RightMotors = motor_group(RightFrontMotor, RightBackMotor);

motor_group EndGameMotors = motor_group(EndGameMotor1, EndGameMotor2);

// Reset all motors to default positions
void reset()
{
	wait(100, msec);

	ArmMotors.setStopping(hold);
	EndGameMotors.setStopping(hold);
}

// Debug functions
void log(const char *message)
{
	Brain.Screen.print(message);
	Brain.Screen.newLine();

	std::cout << message << std::endl;
}

void clearLine()
{
	Controller.Screen.clearLine(3);
}

void show(const char *message)
{
	clearLine();

	Controller.Screen.print(message);
}