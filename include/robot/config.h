#pragma once

// Change to reverse direction of all motors.
bool IS_REVERSED = false;

// Recording
// -- "GetOnePoint" -- Gets one point, just drives straight and back.
// -- "Spin" -- Spins the spinny motor for 55 seconds.
// -- "Recording" -- Plays the saved recording.
const char *AUTO_MODE = "GetOnePoint";

// Measured in cm, multiplied by 10 to get mm
const float WHEEL_RADIUS = 10.5 / 2 * 10;
const float OPPOSITE_WHEEL_DISTANCE = 25.5 * 10;
const float WHEEL_BASE = 13.5 * 10;

// Velocity configuration
int MAX_VELOCITY = 25;

const int VELOCITY_INCREMENT = 5;
const int ARMS_VELOCITY = 40;

const int VELOCITY_UPDATE_RATE = 1;

// Recording
const bool IS_RECORDING_ENABLED = true;
const int RECORDING_VELOCITY_RATE = 1;
const int MAX_SAMPLES = (1000 / RECORDING_VELOCITY_RATE) * 15;

// Mutable variables (these are for run-time usage)
bool isLaunching = false;
bool areArmsOpen = false;
bool isRecording = false;
bool isPlayingRecording = false;