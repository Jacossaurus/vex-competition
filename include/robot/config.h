#pragma once

// Change to reverse direction of all motors.
bool IS_REVERSED = false;
bool SPINNY_MOTOR_REVERSED = true;

// Recording
// -- "GetOnePoint" -- Gets one point, just drives straight and back.
// -- "Spin" -- Spins the spinny motor for 55 seconds.
// -- "Recording" -- Plays the saved recording.
const char *AUTO_MODE = "Recording";

// Measured in cm, multiplied by 10 to get mm
const float WHEEL_RADIUS = 10.5 / 2 * 10;
const float OPPOSITE_WHEEL_DISTANCE = 25.5 * 10;
const float WHEEL_BASE = 13.5 * 10;

// Velocity configuration
int MAX_VELOCITY = 75;
const int VELOCITY_INCREMENT = 5;

const int END_GAME_VELOCITY = 75;
const int ARMS_VELOCITY = 25;

const int VELOCITY_UPDATE_RATE = 1;

// Recording
const int MAX_SAMPLES = (1000 / VELOCITY_UPDATE_RATE) * 15;

// Mutable variables (these are for run-time usage)
bool isSpinnyMotorRunning = false;
bool areArmsOpen = false;
bool isRecording = false;
bool isPlayingRecording = false;