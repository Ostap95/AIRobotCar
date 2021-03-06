
/*
  Wheels.cpp - Library for manipulating wheels of the car
  Created by Ostap Kozak, July 22, 2016.
  Released into the public domain.
*/

#include "Wheels.h"
#include "../AFMotor/AFMotor.h"


#define RIGHT_DIRECTION FORWARD
#define LEFT_DIRECTION BACKWARD

unsigned int motorSpeed = 255;

AF_DCMotor motor_back(2); // Back Motor
AF_DCMotor motor_front(3); // Front Motor
AF_DCMotor motor_direction(4); // Direction Motor

void wheelsSetup() {
  motor_back.setSpeed(motorSpeed);
  motor_direction.setSpeed(motorSpeed);
  motor_front.setSpeed(motorSpeed);
}
void driveForward() {
  motor_back.run(FORWARD);
  motor_front.run(FORWARD);
}

void stopMotors() {
  motor_back.run(RELEASE);
  motor_front.run(RELEASE);
}

void driveBackward() {
  motor_back.run(BACKWARD);
  motor_front.run(BACKWARD);
}

void turnRight() {
  driveForward();
  motor_direction.run(RIGHT_DIRECTION);
  //delay(700);
}

void turnLeft() {
  driveForward();
  motor_direction.run(LEFT_DIRECTION);
  //delay(700);
}

void backUp(unsigned int duration) {
    driveBackward();
    delay(duration);
}

void releaseDirection() {
  motor_direction.run(RELEASE);
}
