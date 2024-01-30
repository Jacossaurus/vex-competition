#pragma once

std::vector<int> recording[4] = {};

void record(int leftVelocity, int rightVelocity, int armsVelocity, int endGameVelocity)
{
	recording->insert(recording->end(), {leftVelocity, rightVelocity, armsVelocity, endGameVelocity});
}

void beginRecording()
{
	isRecording = true;

	show("Recording started");
}

void stopRecording()
{
	isRecording = false;

	show("Recording ended");

	log("DO NOT STOP PROGRAM.");
	log("Saving recording...");

	Brain.SDcard.savefile("auton.dat", (uint8_t *)recording, sizeof(recording));

	log("Saved. All is well.");
}

void playRecording()
{
	isPlayingRecording = true;

	show("Loading recording");

	Brain.SDcard.loadfile("auton.dat", (uint8_t *)recording, sizeof(recording));

	show("Playing recording");

	// Stages - (1) left, (2) right, (3) arms, (4) end game
	int stage = 1;

	for (std::vector<int> velocities : recording)
	{
		LeftFrontMotor.setVelocity(velocities[0], percent);
		LeftBackMotor.setVelocity(velocities[0], percent);

		RightFrontMotor.setVelocity(velocities[1], percent);
		RightBackMotor.setVelocity(velocities[1], percent);

		ArmMotors.setVelocity(velocities[2], percent);

		EndGameMotors.setVelocity(velocities[3], percent);

		LeftFrontMotor.spin(forward);
		LeftBackMotor.spin(forward);

		RightFrontMotor.spin(forward);
		RightBackMotor.spin(forward);

		ArmMotors.spin(forward);

		EndGameMotors.spin(forward);

		wait(1, msec);
	}

	show("Recording finished");

	isPlayingRecording = false;
}