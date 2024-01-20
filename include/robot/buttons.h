#pragma once

// Axes (you can change these - they change the driver motor axes)
vex::controller::axis FORWARD_AND_BACK_AXIS = Controller.Axis3;
vex::controller::axis LEFT_AND_RIGHT_AXIS = Controller.Axis1;

// Buttons (you can change these to whatever feels best)
vex::controller::button TOGGLE_SPINNY_THING_BUTTON = Controller.ButtonA;

vex::controller::button OPEN_ARMS_BUTTON = Controller.ButtonL1;
vex::controller::button CLOSE_ARMS_BUTTON = Controller.ButtonL2;

vex::controller::button TOGGLE_DRIVER_REVERSE_BUTTON = Controller.ButtonX;
vex::controller::button TOGGLE_SPINNY_REVERSE_BUTTON = Controller.ButtonY;

vex::controller::button INCREASE_VELOCITY_BUTTON = Controller.ButtonUp;
vex::controller::button DECREASE_VELOCITY_BUTTON = Controller.ButtonDown;

vex::controller::button INCREASE_ENDGAME_BUTTON = Controller.ButtonR1;
vex::controller::button DECREASE_ENDGAME_BUTTON = Controller.ButtonR2;