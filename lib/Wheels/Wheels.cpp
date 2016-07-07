
/*
  Wheels.cpp - Library for manipulating wheels of the car
  Created by Ostap Kozak, July 22, 2016.
  Released into the public domain.
*/

#include "Wheels.h"
#include "../AFMotor/AFMotor.h"

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void moveForward(unsigned int speed) {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void stopCar(void) {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(RELEASE); // Turn off the motor
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void turnRight(unsigned int speed) {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void turnLeft(unsigned int speed) {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void backUp(unsigned int speed, unsigned int duration) {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  for(uint8_t i = 0; i < duration; i++) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  stopCar();
}
