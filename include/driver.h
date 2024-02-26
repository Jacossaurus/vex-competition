#pragma once

void launch()
{
	if (isLaunching)
		return;

	isLaunching = true;

	LaunchMotor.spin(forward, MAX_VELOCITY, percent);

	wait(50000, msec);

	LaunchMotor.stop();

	log("Launching");

	isLaunching = false;
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

	log("Velocity: %d", MAX_VELOCITY);
}

void decreaseVelocity()
{
	MAX_VELOCITY -= VELOCITY_INCREMENT;

	if (MAX_VELOCITY < 0)
	{
		MAX_VELOCITY = 0;
	}

	clearLine();

	log("Velocity: %d", MAX_VELOCITY);
}

void driverControl()
{
	log("Driver control activated");

	TOGGLE_LAUNCHER_BUTTON.pressed(launch);
	TOGGLE_DRIVER_REVERSE_BUTTON.pressed(toggleDriverReverse);

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
		if (OPEN_ARMS_BUTTON.pressing())
		{
			Pneumatics.set(true);
		}
		else if (CLOSE_ARMS_BUTTON.pressing())
		{
			Pneumatics.set(false);
		}

		if (isRecording)
		{
			// record(leftVelocity, rightVelocity);
		}
	}
}
