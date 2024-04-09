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

controller Controller(primary);
competition Competition = competition();

motor LeftFrontMotor(PORT11, ratio18_1, !IS_REVERSED);
motor LeftBackMotor(PORT20, ratio18_1, !IS_REVERSED);
motor RightFrontMotor(PORT1, ratio18_1, IS_REVERSED);
motor RightBackMotor(PORT10, ratio18_1, IS_REVERSED);

motor SpinnyMotor(PORT16, ratio18_1, false);

motor IntakeMotor(PORT3, ratio18_1, false);

motor EndGameMotor1(PORT15, ratio18_1, false);
motor EndGameMotor2(PORT9, ratio18_1, true);

pneumatics Pneumatics1(Brain.ThreeWirePort.A);
pneumatics Pneumatics2(Brain.ThreeWirePort.B);

motor_group LeftMotors(LeftFrontMotor, LeftBackMotor);
motor_group RightMotors(RightFrontMotor, RightBackMotor);
motor_group EndGameMotors(EndGameMotor1, EndGameMotor2);

drivetrain Drivetrain(LeftMotors, RightMotors, 2 * M_PI * WHEEL_RADIUS, OPPOSITE_WHEEL_DISTANCE, WHEEL_BASE, mm);

// Reset all motors to default positions
void reset()
{
	// Wait for motors to register
	wait(MOTOR_INIT_DELAY, msec);

	Pneumatics1.set(false);
	Pneumatics2.set(false);

	EndGameMotors.setStopping(hold);
}

// Debug functions
void clearLine()
{
	Controller.Screen.clearLine(3);
	Brain.Screen.clearScreen();
}

void log(char *format...)
{
	clearLine();

	Brain.Screen.printAt(10, 60, format);

	Controller.Screen.print(format);

	std::cout << format << std::endl;

	fflush(stdout);
}