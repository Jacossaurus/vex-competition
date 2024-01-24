#pragma once

std::vector<int> driverVelocities;

std::vector<int> driverRecording = {};

void record(int leftVelocity, int rightVelocity)
{
	driverVelocities.push_back(leftVelocity);
	driverVelocities.push_back(rightVelocity);
}

void beginRecording()
{
	isRecording = true;

	clearLine();

	Controller.Screen.print("Recording started");
}

void stopRecording()
{
	isRecording = false;

	for (int velocity : driverVelocities)
	{
		// log stuff
	}

	clearLine();

	Controller.Screen.print("Recording ended and logged");
}

void playRecording()
{
	bool isLeft = true;

	LeftFrontMotor.spin(forward);
	LeftBackMotor.spin(forward);

	RightFrontMotor.spin(forward);
	RightBackMotor.spin(forward);

	for (int velocity : driverRecording)
	{
		if (isLeft)
		{
			LeftFrontMotor.setVelocity(velocity, percent);
			LeftBackMotor.setVelocity(velocity, percent);
		}
		else
		{

			RightFrontMotor.setVelocity(velocity, percent);
			RightBackMotor.setVelocity(velocity, percent);
		}

		isLeft = !isLeft;

		wait(1, msec);
	}
}