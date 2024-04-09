#pragma once

bool IS_CANARY = true;

// Change to reverse direction of all motors.
bool IS_REVERSED = true;

// Measured in cm, multiplied by 10 to get mm
float WHEEL_RADIUS = 10.5 / 2 * 10;
float OPPOSITE_WHEEL_DISTANCE = 25.5 * 10;
float WHEEL_BASE = 13.5 * 10;

// Velocity configuration
int MAX_VELOCITY = 100;
int VELOCITY_INCREMENT = 5;

int VELOCITY_UPDATE_RATE = 1;

// Motor initiation delay (msec)
int MOTOR_INIT_DELAY = 50;

// Mutable variables (these are for run-time usage)
bool isSpinning = false;
bool isArmsOpen = false;
bool isManual = false;

bool isIntakeSpinningForward = false;
bool isIntakeSpinningBackward = false;