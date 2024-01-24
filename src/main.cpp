/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jacob                                                     */
/*    Created:      11/10/2023, 8:32:41 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "../include/robot/config.h"
#include "../include/robot/core.h"
#include "../include/robot/buttons.h"
#include "../include/record.h"
#include "../include/driver.h"
#include "../include/auto.h"

int main()
{
	log("------");

	log("New thread started");
	log("Waiting for vex...");

	if (!isTestingAutonomous)
	{
		Competition.autonomous(autonomous);
		Competition.drivercontrol(driverControl);
	}
	else
	{
		log("Testing autonomous!");
		log("Disable isTestingAutonomous in config.h if incorrect.");

		autonomous();
	}

	vex::thread(reset).setPriority(10);

	log("Registered events");

	log("------");

	return 0;
}
