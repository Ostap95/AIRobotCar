/*
  Sonar.h - Library for creating sonar object
  Created by Ostap Kozak, July 20, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "../NewPing/NewPing.h"

#ifndef Sonar_h
#define Sonar_h

class Sonar {
public:
  Sonar(uint8_t triggerPin, uint8_t echoPin, unsigned int maxDistance, uint8_t position);
  NewPing getSonar();
  uint8_t getSonarPosition();

private:
  uint8_t _position;
  NewPing _sonar;
};

#endif
