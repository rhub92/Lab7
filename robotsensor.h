/*
 * robotsensor.h
 *
 * Author: Ryan Hub
 *
 * Function: This provides the function prototypes used for the code necessary to make the sensors on the robot work and take in readings
 */

#include <msp430g2553.h>

// Initializes the sensor's subsystem
void initializeSensorSubsystem();

// Reads in and returns the value from the left sensor
unsigned int leftSensorReading();

// Reads in and returns the value from the right sensor
unsigned int rightSensorReading();


