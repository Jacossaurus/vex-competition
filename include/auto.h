#pragma once

void openArms()
{
	// Pneumatics1.set(true);
	// Pneumatics2.set(true);
}

void closeArms()
{
	// Pneumatics1.set(false);
	// Pneumatics2.set(false);
}

void autonomous()
{
	log("Resetting motors...");

	reset();

	log("Autonomous activated");

	Drivetrain.setDriveVelocity(40, percent);

	openArms();

	Drivetrain.drive(forward);

	wait(2, sec);

	Drivetrain.drive(reverse);

	wait(1.5, sec);

	Drivetrain.stop();

	closeArms();
}