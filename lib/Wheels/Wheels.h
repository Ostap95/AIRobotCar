/*
  Wheels.h - Library for manipulating wheels of the car
  Created by Ostap Kozak, July 22, 2016.
  Released into the public domain.
*/

#include "Arduino.h"

#ifndef Wheels_h
#define Wheels_h

void wheelsSetup();
void driveForward();
void stopMotors();
void turnLeft();
void turnRight();
void backUp(unsigned int duration);
void releaseDirection();

#endif
