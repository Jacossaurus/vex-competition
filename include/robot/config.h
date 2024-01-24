#pragma once

// Change to reverse direction of all motors.
bool IS_REVERSED = false;
bool SPINNY_MOTOR_REVERSED = true;

// If true, then skills autonomous will play. Else, competition autonomous will play.
bool IS_SKILLS_AUTONOMOUS = false;

// WARNING: highly recommended off, as drivetrain introduces noticeable input-lag.
bool IS_USING_DRIVETRAIN = false;

// Measured in cm, multiplied by 10 to get mm
float WHEEL_RADIUS = 10.5 / 2 * 10;
float OPPOSITE_WHEEL_DISTANCE = 25.5 * 10;
float WHEEL_BASE = 13.5 * 10;

// Velocity configuration
int MAX_VELOCITY = 50;
int VELOCITY_INCREMENT = 5;

int END_GAME_VELOCITY = 75;
int ARMS_VELOCITY = 25;

// Mutable variables (these are for run-time usage)
bool isSpinnyMotorRunning = false;
bool areArmsOpen = false;
bool isTestingAutonomous = false;
bool isRecording = false;