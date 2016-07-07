/*
  Sonars.h - Library for manipulating sonar objects
  Created by Ostap Kozak, July 20, 2016.
  Released into the public domain.
*/

#include "Arduino.h"

#ifndef Sonars_h
#define Sonars_h

  void sonarsSetup();
  void sonarsLoop();
  void echoCheck();
  void printCycle();
  unsigned int getSonarDistance(int i);

#endif
