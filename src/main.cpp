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
#include "robot/buttons.h"
#include "record.h"
#include "driver.h"
#include "auto.h"

int main()
{
	log("One sec...");

	Competition.autonomous(autonomous);
	Competition.drivercontrol(driverControl);

	vex::thread(reset).setPriority(10);

	return 0;
}
