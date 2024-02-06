#pragma once

void toggleSpinnyThing()
{
	if (!isSpinnyMotorRunning)
	{
		isSpinnyMotorRunning = true;

		SpinnyMotor.spin(forward, MAX_VELOCITY, percent);

		log("Spinny motor enabled");
	}
	else
	{
		isSpinnyMotorRunning = false;

		SpinnyMotor.stop();
		SpinnyMotor.setVelocity(0, percent);

		log("Spinny motor disabled");
	}
}

void toggleSpinnyReverse()
{
	if (isSpinnyMotorRunning)
		return;

	SPINNY_MOTOR_REVERSED = !SPINNY_MOTOR_REVERSED;

	SpinnyMotor.setReversed(SPINNY_MOTOR_REVERSED);

	if (isSpinnyMotorRunning)
	{
		SpinnyMotor.spin(forward);
	}

	log("Spinny motor reversed");
}

void toggleDriverReverse()
{
	IS_REVERSED = !IS_REVERSED;

	LeftFrontMotor.setReversed(IS_REVERSED);
	LeftBackMotor.setReversed(IS_REVERSED);

	RightFrontMotor.setReversed(!IS_REVERSED);
	RightBackMotor.setReversed(!IS_REVERSED);

	log("Driver motors reversed");
}

void increaseVelocity()
{
	MAX_VELOCITY += VELOCITY_INCREMENT;

	if (MAX_VELOCITY > 100)
	{
		MAX_VELOCITY = 100;
	}

	if (isSpinnyMotorRunning)
	{
		SpinnyMotor.setVelocity(MAX_VELOCITY, percent);
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

	if (isSpinnyMotorRunning)
	{
		SpinnyMotor.setVelocity(MAX_VELOCITY, percent);
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
		if (!isRecording)
		{
			wait(VELOCITY_UPDATE_RATE, msec);
		}
		else
		{
			wait(RECORDING_VELOCITY_RATE, msec);
		}

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

		leftVelocity = fmax(fmin(leftVelocity, 100), -100);
		rightVelocity = fmax(fmin(rightVelocity, 100), -100);

		// Set velocites
		LeftMotors.spin(forward, leftVelocity, percent);
		RightMotors.spin(forward, rightVelocity, percent);

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

		ArmMotors.spin(forward, armVelocity, percent);

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

		EndGameMotors.spin(forward, endGameVelocity, percent);

		if (isRecording)
		{
			record(leftVelocity, rightVelocity, armVelocity, endGameVelocity);
		}
	}
}
