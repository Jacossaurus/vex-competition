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
	wait(100, msec);

	log("Autonomous activated");

	if (!IS_SKILLS_AUTONOMOUS)
	{
		Drivetrain.setDriveVelocity(15, percent);

		openArms();

		Drivetrain.driveFor(18, inches, true);

		wait(100, msec);

		Drivetrain.driveFor(-18, inches, true);

		closeArms();
	}
	else
	{
		Drivetrain.setStopping(hold);
		Drivetrain.setDriveVelocity(0, percent);
		Drivetrain.setTurnVelocity(0, percent);

		Drivetrain.stop();

		SpinnyMotor.setVelocity(600, rpm);
		SpinnyMotor.spinFor(55, seconds);
	}
}