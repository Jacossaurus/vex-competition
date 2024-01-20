#pragma once

void lockArms()
{
	ArmMotors.spinFor(10, sec);
}

void openArms()
{
	ArmMotors.setVelocity(ARMS_VELOCITY, percent);
	ArmMotors.spinFor(1, sec);

	// vex::thread(lockArms).setPriority(10);
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

	Drivetrain.setDriveVelocity(15, percent);

	openArms();

	Drivetrain.driveFor(18, inches, true);

	wait(100, msec);

	Drivetrain.driveFor(-18, inches, true);

	closeArms();

	// LeftMotors.setVelocity(25, percent);
	// RightMotors.setVelocity(25, percent);

	// Drivetrain.setDriveVelocity(25, percent);
	// Drivetrain.setTurnVelocity(25, percent);

	// openArms();

	// Drivetrain.driveFor(30, inches, true);

	// RightMotors.setVelocity(10, percent);

	// LeftMotors.spin(forward);
	// RightMotors.spin(forward);

	// wait(4, seconds);

	// LeftMotors.stop();
	// RightMotors.stop();

	// Drivetrain.setDriveVelocity(25, percent);

	// Drivetrain.driveFor(-30, inches, true);

	// // Drive forward
	// Drivetrain.driveFor(45, inches, true);

	// // Turn towards the goal
	// Drivetrain.turnFor(65 * (IS_OPPOSITE_AUTONOMOUS ? -1 : 1), degrees, true);

	// // Drive toward the goal
	// Drivetrain.driveFor(30, inches, true);

	// // Drive backwards to get out from underneath the goal.
	// Drivetrain.driveFor(-30, inches, true);
}