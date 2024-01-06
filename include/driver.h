#pragma once

void driverControl()
{
	print("Driver control activated");

	Drivetrain.setDriveVelocity(MAX_VELOCITY, percent);

	// while (true)
	// {
	// 	wait(1, msec);

	// 	int rotVelocity = fmax(fmin(Controller.Axis1.position(), MAX_VELOCITY), -MAX_VELOCITY);

	// 	int leftVelocity = 0;
	// 	int rightVelocity = 0;

	// 	// Foward and Reverse
	// 	leftVelocity = fmax(fmin(Controller.Axis3.position(), MAX_VELOCITY), -MAX_VELOCITY);
	// 	rightVelocity = fmax(fmin(Controller.Axis3.position(), MAX_VELOCITY), -MAX_VELOCITY);

	// 	// Left and Right
	// 	leftVelocity += rotVelocity;
	// 	rightVelocity += -rotVelocity;

	// 	// Set velocites
	// 	LeftFrontMotor.setVelocity(leftVelocity, percent);
	// 	LeftBackMotor.setVelocity(leftVelocity, percent);

	// 	LeftFrontMotor.spin(forward);
	// 	LeftBackMotor.spin(forward);

	// 	RightFrontMotor.setVelocity(rightVelocity, percent);
	// 	RightBackMotor.setVelocity(rightVelocity, percent);

	// 	RightFrontMotor.spin(forward);
	// 	RightBackMotor.spin(forward);
	// }
}