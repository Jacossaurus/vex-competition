#pragma once

void toggleSpinnyThing()
{
	if (!isSpinnyMotorRunning)
	{
		isSpinnyMotorRunning = true;

		SpinnyMotor.setVelocity(600, rpm);
		SpinnyMotor.spin(forward);

		show("Spinny motor enabled");
	}
	else
	{
		isSpinnyMotorRunning = false;

		SpinnyMotor.stop();
		SpinnyMotor.setVelocity(0, rpm);

		show("Spinny motor disabled");
	}
}

void toggleSpinnyReverse()
{
	SpinnyMotor.stop();

	SPINNY_MOTOR_REVERSED = !SPINNY_MOTOR_REVERSED;

	SpinnyMotor.setReversed(SPINNY_MOTOR_REVERSED);

	if (isSpinnyMotorRunning)
	{
		SpinnyMotor.spin(forward);
	}

	show("Spinny motor reversed");
}

void toggleDriverReverse()
{
	IS_REVERSED = !IS_REVERSED;

	LeftFrontMotor.setReversed(IS_REVERSED);
	LeftBackMotor.setReversed(IS_REVERSED);

	RightFrontMotor.setReversed(!IS_REVERSED);
	RightBackMotor.setReversed(!IS_REVERSED);

	show("Driver motors reversed");
}

void increaseVelocity()
{
	MAX_VELOCITY += VELOCITY_INCREMENT;

	if (MAX_VELOCITY > 100)
	{
		MAX_VELOCITY = 100;
	}

	clearLine();

	Controller.Screen.print("Velocity: %d", MAX_VELOCITY);
}

void decreaseVelocity()
{
	MAX_VELOCITY -= VELOCITY_INCREMENT;

	if (MAX_VELOCITY < 0)
	{
		MAX_VELOCITY = 0;
	}

	clearLine();

	Controller.Screen.print("Velocity: %d", MAX_VELOCITY);
}

void driverControl()
{
	log("Driver control activated");

	TOGGLE_SPINNY_THING_BUTTON.pressed(toggleSpinnyThing);
	TOGGLE_DRIVER_REVERSE_BUTTON.pressed(toggleDriverReverse);
	TOGGLE_SPINNY_REVERSE_BUTTON.pressed(toggleSpinnyReverse);

	INCREASE_VELOCITY_BUTTON.pressed(increaseVelocity);
	DECREASE_VELOCITY_BUTTON.pressed(decreaseVelocity);

	BEGIN_RECORDING_BUTTON.pressed(beginRecording);
	STOP_RECORDING_BUTTON.pressed(stopRecording);

	PLAY_RECORDING_BUTTON.pressed(playRecording);

	while (true)
	{
		wait(1, msec);

		if (isPlayingRecording)
			continue;

		int rotVelocity = fmax(fmin(LEFT_AND_RIGHT_AXIS.position(), MAX_VELOCITY), -MAX_VELOCITY);

		int leftVelocity = 0;
		int rightVelocity = 0;

		// Foward and Reverse
		leftVelocity = fmax(fmin(FORWARD_AND_BACK_AXIS.position(), MAX_VELOCITY), -MAX_VELOCITY);
		rightVelocity = fmax(fmin(FORWARD_AND_BACK_AXIS.position(), MAX_VELOCITY), -MAX_VELOCITY);

		// Left and Right
		leftVelocity += (-rotVelocity * (IS_REVERSED ? 1 : -1)) / 2;
		rightVelocity += (rotVelocity * (IS_REVERSED ? 1 : -1)) / 2;

		// Set velocites
		LeftFrontMotor.setVelocity(leftVelocity, percent);
		LeftBackMotor.setVelocity(leftVelocity, percent);

		LeftFrontMotor.spin(forward);
		LeftBackMotor.spin(forward);

		RightFrontMotor.setVelocity(rightVelocity, percent);
		RightBackMotor.setVelocity(rightVelocity, percent);

		RightFrontMotor.spin(forward);
		RightBackMotor.spin(forward);

		// Arms
		int armVelocity = 0;

		if (OPEN_ARMS_BUTTON.pressing())
		{
			armVelocity += ARMS_VELOCITY;
		}

		if (CLOSE_ARMS_BUTTON.pressing())
		{
			armVelocity -= ARMS_VELOCITY;
		}

		ArmMotors.setVelocity(armVelocity, percent);
		ArmMotors.spin(forward);

		// Endgame
		int endGameVelocity = 0;

		if (INCREASE_ENDGAME_BUTTON.pressing())
		{
			endGameVelocity += END_GAME_VELOCITY;
		}

		if (DECREASE_ENDGAME_BUTTON.pressing())
		{
			endGameVelocity -= END_GAME_VELOCITY;
		}

		EndGameMotors.setVelocity(endGameVelocity, percent);
		EndGameMotors.spin(forward);

		if (isRecording)
		{
			record(leftVelocity, rightVelocity, armVelocity, endGameVelocity);
		}
	}
}
