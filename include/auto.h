#pragma once

void openArms()
{
	ArmMotors.setVelocity(ARMS_VELOCITY, percent);
	ArmMotors.spinFor(1, sec);
}

void closeArms()
{
	ArmMotors.setVelocity(-ARMS_VELOCITY, percent);

	ArmMotors.spinFor(1, sec);
}

void autonomous()
{
	wait(VELOCITY_UPDATE_RATE, msec);

	log("Autonomous activated");

	if (AUTO_MODE == "GetOnePoint")
	{
		Drivetrain.setDriveVelocity(15, percent);

		openArms();

		Drivetrain.driveFor(18, inches, true);

		wait(100, msec);

		Drivetrain.driveFor(-18, inches, true);

		closeArms();
	}
	else if (AUTO_MODE == "Spin")
	{
		Drivetrain.setStopping(hold);
		Drivetrain.setDriveVelocity(0, percent);
		Drivetrain.setTurnVelocity(0, percent);

		Drivetrain.stop();

		SpinnyMotor.setVelocity(600, rpm);
		SpinnyMotor.spinFor(55, seconds);
	}
	else if (AUTO_MODE == "Recording")
	{
		playRecording();
	}
}