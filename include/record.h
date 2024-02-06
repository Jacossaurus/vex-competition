#pragma once

int8_t recording[4][MAX_SAMPLES] = {};

int index = 0;

void record(int leftVelocity, int rightVelocity, int armsVelocity, int endGameVelocity)
{
	if (!IS_RECORDING_ENABLED || !isRecording || isPlayingRecording)
		return;

	recording[0][index] = leftVelocity;
	recording[1][index] = rightVelocity;
	recording[2][index] = armsVelocity;
	recording[3][index] = endGameVelocity;

	if (index % 1000 == 0)
	{
		clearLine();

		Controller.Screen.print("Recording (%d / %d)", index / 1000, MAX_SAMPLES / 1000);
	}

	index++;
}

void beginRecording()
{
	if (!IS_RECORDING_ENABLED || isRecording || isPlayingRecording)
		return;

	log("Recording began");

	index = 0;

	isRecording = true;
}

void stopRecording()
{
	if (!IS_RECORDING_ENABLED || !isRecording)
		return;

	log("Recording stopped");

	if (index < MAX_SAMPLES)
	{
		recording[0][index] = -101;
	}

	Brain.SDcard.savefile("auton.dat", (uint8_t *)recording, sizeof(recording));

	index = 0;

	isRecording = false;
}

void playRecording()
{
	if (!IS_RECORDING_ENABLED || isPlayingRecording || isRecording)
		return;

	log("Playing recording");

	isPlayingRecording = true;

	int read = Brain.SDcard.loadfile("auton.dat", (uint8_t *)recording, sizeof(recording));

	for (int i = 0; i <= MAX_SAMPLES; i++)
	{
		int leftVelocity = recording[0][i];
		int rightVelocity = recording[1][i];
		int armsVelocity = recording[2][i];
		int endGameVelocity = recording[3][i];

		if (leftVelocity == -101)
		{
			break;
		}

		LeftMotors.spin(forward, leftVelocity, percent);
		RightMotors.spin(forward, rightVelocity, percent);

		ArmMotors.spin(forward, armsVelocity, percent);
		EndGameMotors.spin(forward, endGameVelocity, percent);

		wait(1, msec);
	}

	LeftMotors.stop();
	RightMotors.stop();
	ArmMotors.stop();
	EndGameMotors.stop();

	isPlayingRecording = false;

	log("Recording stopped");
}
