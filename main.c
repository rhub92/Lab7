/*
* Lab 7: A/D Conversion - "Robot Sensing"
*
* Author: Ryan Hub
*
* Date: 10 December 2013
*
* Purpose: The purpose of this lab is to create a robot sensing library that we can use to have the robot to sense different objects coming towards
* the robot. Therefore, in the robot maze the robot will be able to make its way through the maze with out hitting the wall.
*
* Documentation: None
*/

#include "robotsensor.h"

/*
 * Subroutine Name: initializeLights
 * Author: Ryan Hub
 * Function: intializes the lights on the MSP430
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void initializeLights() {
	P1DIR |= BIT0;
	P1DIR |= BIT6;
}

/*
 * Subroutine Name: turnLeftLightOn
 * Author: Ryan Hub
 * Function: turns the left light on
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void turnLeftLightOn(){
	P1OUT |= BIT0;
}

/*
 * Subroutine Name: turnRightLightOn
 * Author: Ryan Hub
 * Function: turns the right light on
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void turnRightLightOn(){
	P1OUT |= BIT6;
}

/*
 * Subroutine Name: turnLeftLightOff
 * Author: Ryan Hub
 * Function: turns the left light off
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void turnLeftLightOff(){
	P1OUT &= ~BIT0;
}

/*
 * Subroutine Name: turnRightLightOff
 * Author: Ryan Hub
 * Function: turns the right light off
 * Inputs: none
 * Outputs: none
 * Subroutines used: none
 */

void turnRightLightOff(){
	P1OUT &= ~BIT6;
}


int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  initializeSensorSubsystem();
  initializeLights();



  for (;;)
  {

	  if (leftSensorReading() < 0x299)
			turnLeftLightOff();
		else
			turnLeftLightOn();


		if (rightSensorReading() < 0x2FF)
			turnRightLightOff();
		else
			turnRightLightOn();

  }

    return 0;
}
