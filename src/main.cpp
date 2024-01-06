/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jacob                                                     */
/*    Created:      11/10/2023, 8:32:41 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "robot/config.h"
#include "robot/core.h"
#include "robot/images.h"
#include "driver.h"
#include "auto.h"

int main()
{
	print("\n\n\n------\n");

	print("New thread started");
	print("Waiting for vex..");

	Competition.autonomous(autonomous);
	Competition.drivercontrol(driverControl);

	print("Registered events");

	print("\n------\n");

	return 0;
}
