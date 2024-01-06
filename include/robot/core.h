#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

motor_group LeftMotors = motor_group(LeftFrontMotor, LeftBackMotor);
motor_group RightMotors = motor_group(RightFrontMotor, RightBackMotor);

drivetrain Drivetrain = drivetrain(LeftMotors, RightMotors);

void print(char *message)
{
	printf(message);

	Brain.Screen.print(message);
	Brain.Screen.newLine();
}