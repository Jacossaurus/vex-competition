#pragma once

// Axes (you can change these - they change the driver motor axes)
vex::controller::axis FORWARD_AND_BACK_AXIS = Controller.Axis3;
vex::controller::axis LEFT_AND_RIGHT_AXIS = Controller.Axis1;

vex::controller::axis MANUAL_LEFT_AXIS = Controller.Axis3;
vex::controller::axis MANUAL_RIGHT_AXIS = Controller.Axis2;

// Buttons (you can change these to whatever feels best)
vex::controller::button TOGGLE_ARMS_BUTTON = Controller.ButtonA;
vex::controller::button TOGGLE_SPINNY_BUTTON = Controller.ButtonY;
vex::controller::button TOGGLE_MANUAL_BUTTON = Controller.ButtonX;

vex::controller::button INCREASE_VELOCITY_BUTTON = Controller.ButtonUp;
vex::controller::button DECREASE_VELOCITY_BUTTON = Controller.ButtonDown;

vex::controller::button INTAKE_FORWARD_BUTTON = Controller.ButtonL1;
vex::controller::button INTAKE_BACKWARD_BUTTON = Controller.ButtonL2;

vex::controller::button ENDGAME_FORWARD_BUTTON = Controller.ButtonR1;
vex::controller::button ENDGAME_BACKWARD_BUTTON = Controller.ButtonR2;
