/*
  Sonar.cpp - Library for creating sonar object
  Created by Ostap Kozak, July 20, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Sonar.h"
#include "../NewPing/NewPing.h"

// Constructor
Sonar::Sonar(uint8_t triggerPin, uint8_t echoPin, unsigned int maxDistance, uint8_t position) {
  _sonar = NewPing(triggerPin, echoPin, maxDistance);
  _position = position;
}

// Return sonar object
NewPing Sonar::getSonar(void) {
  return _sonar;
}


// Returns sonar position
uint8_t Sonar::getSonarPosition(void) {
  return _position;
}
