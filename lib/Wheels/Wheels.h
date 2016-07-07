/*
  Wheels.h - Library for manipulating wheels of the car
  Created by Ostap Kozak, July 22, 2016.
  Released into the public domain.
*/

#include "Arduino.h"

#ifndef Wheels_h
#define Wheels_h

void moveForward(unsigned int speed);
void stopCar();
void turnLeft(unsigned int speed);
void turnRight(unsigned int speed);
void backUp(unsigned int speed, unsigned int duration);

#endif
