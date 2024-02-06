#pragma once

void openArms()
{
	ArmMotors.setVelocity(-ARMS_VELOCITY, percent);
	ArmMotors.spinFor(1.5, sec);
}

void closeArms()
{
	ArmMotors.setVelocity(ARMS_VELOCITY, percent);

	ArmMotors.spinFor(1, sec);
}

void autonomous()
{
	wait(100, msec);

	log("Autonomous activated");

	if (AUTO_MODE == "GetOnePoint")
	{
		Drivetrain.setDriveVelocity(40, percent);

		openArms();

		// Drivetrain.driveFor(27, inches, true);

		// wait(100, msec);

		// Drivetrain.driveFor(-25, inches, true);

		Drivetrain.drive(forward);

		wait(1.5, sec);

		Drivetrain.drive(reverse);

		wait(1, sec);

		Drivetrain.stop();

		closeArms();
	}
	else if (AUTO_MODE == "Spin")
	{
		Drivetrain.setStopping(hold);
		Drivetrain.setDriveVelocity(0, percent);
		Drivetrain.setTurnVelocity(0, percent);

		Drivetrain.stop();

		SpinnyMotor.setVelocity(70, percent);
		SpinnyMotor.spinFor(60, seconds);
	}
	else if (AUTO_MODE == "Recording")
	{
		playRecording();
	}
}