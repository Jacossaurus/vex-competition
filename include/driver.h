#pragma once

void toggleManual()
{
	isManual = !isManual;

	clearLine();

	Controller.Screen.print("Manual %s", isManual ? "enabled" : "disabled");
}

void toggleSpinny()
{
	isSpinning = !isSpinning;

	if (isSpinning)
	{
		SpinnyMotor.spin(forward, 100 * 120, vex::voltageUnits::mV);
	}
	else
	{
		SpinnyMotor.stop();
	}

	clearLine();

	Controller.Screen.print("Spinning %s", isSpinning ? "enabled" : "disabled");
}

void toggleArms()
{
	isArmsOpen = !isArmsOpen;

	Pneumatics1.set(isArmsOpen);
	Pneumatics2.set(isArmsOpen);

	clearLine();

	Controller.Screen.print("Arms %s", isArmsOpen ? "opened" : "closed");
}

void spinIntakeForward()
{
	if (isIntakeSpinningForward)
	{
		IntakeMotor.stop();

		isIntakeSpinningForward = false;
		isIntakeSpinningBackward = false;
	}
	else
	{
		isIntakeSpinningForward = true;
		isIntakeSpinningBackward = false;

		IntakeMotor.spin(forward, 100, percent);
	}
}

void spinIntakeBackward()
{
	if (isIntakeSpinningBackward)
	{
		IntakeMotor.stop();

		isIntakeSpinningForward = false;
		isIntakeSpinningBackward = false;
	}
	else
	{
		isIntakeSpinningForward = false;
		isIntakeSpinningBackward = true;

		IntakeMotor.spin(reverse, 100, percent);
	}
}

void increaseVelocity()
{
	MAX_VELOCITY = fmin(MAX_VELOCITY + VELOCITY_INCREMENT, 100);

	clearLine();

	Controller.Screen.print("Velocity: %d", MAX_VELOCITY);
}

void decreaseVelocity()
{
	MAX_VELOCITY = fmax(MAX_VELOCITY - VELOCITY_INCREMENT, 0);

	clearLine();

	Controller.Screen.print("Velocity: %d", MAX_VELOCITY);
}

void driverControl()
{
	log("Resetting motors...");

	reset();

	log("Driver control activated");

	TOGGLE_ARMS_BUTTON.pressed(toggleArms);
	TOGGLE_MANUAL_BUTTON.pressed(toggleManual);
	TOGGLE_SPINNY_BUTTON.pressed(toggleSpinny);

	INTAKE_FORWARD_BUTTON.pressed(spinIntakeForward);
	INTAKE_BACKWARD_BUTTON.pressed(spinIntakeBackward);

	INCREASE_VELOCITY_BUTTON.pressed(increaseVelocity);
	DECREASE_VELOCITY_BUTTON.pressed(decreaseVelocity);

	while (true)
	{
		wait(VELOCITY_UPDATE_RATE, msec);

		int rotVelocity = !isManual ? fmax(fmin(LEFT_AND_RIGHT_AXIS.position(), MAX_VELOCITY), -MAX_VELOCITY) : 0;

		int leftVelocity = 0;
		int rightVelocity = 0;

		// Foward and Reverse
		leftVelocity = fmax(fmin(!isManual ? FORWARD_AND_BACK_AXIS.position() : MANUAL_LEFT_AXIS.position(), MAX_VELOCITY), -MAX_VELOCITY);
		rightVelocity = fmax(fmin(!isManual ? FORWARD_AND_BACK_AXIS.position() : MANUAL_RIGHT_AXIS.position(), MAX_VELOCITY), -MAX_VELOCITY);

		// Left and Right
		leftVelocity += (-rotVelocity * (IS_REVERSED ? 1 : -1)) / 2;
		rightVelocity += (rotVelocity * (IS_REVERSED ? 1 : -1)) / 2;

		leftVelocity = fmax(fmin(leftVelocity, 100), -100);
		rightVelocity = fmax(fmin(rightVelocity, 100), -100);

		// Set velocites and spin
		LeftMotors.spin(forward, leftVelocity, percent);
		RightMotors.spin(forward, rightVelocity, percent);

		if (ENDGAME_FORWARD_BUTTON.pressing())
		{
			EndGameMotors.spin(forward, 50, percent);
		}
		else if (ENDGAME_BACKWARD_BUTTON.pressing())
		{
			EndGameMotors.spin(reverse, 50, percent);
		}
		else
		{
			EndGameMotors.stop();
		}
	}
}
