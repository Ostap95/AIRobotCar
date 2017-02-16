#include "../Sonars/Sonars.h"
#include "../NewPing/NewPing.h"
#include "../AFMotor/AFMotor.h"
#include "../Wheels/Wheels.h"

#define SONAR_LEFT 0
#define SONAR_CENTER 1
#define SONAR_RIGHT 2

void setup() {
  sonarsSetup();
  wheelsSetup();
}

void loop() {
  sonarsLoop();
  decideMove();
}

void decideMove() {
  unsigned int sonarCenter = getSonarDistance(SONAR_CENTER);
  unsigned int sonarLeft = getSonarDistance(SONAR_LEFT);
  unsigned int sonarRight = getSonarDistance(SONAR_RIGHT);

  if(sonarCenter > 30) { // If the path forward is free than continue to drive in straight line
    driveForward();
    if (sonarLeft < sonarRight) {
      turnRight();
    } else if (sonarLeft > sonarRight) {
      turnLeft();
    } else if (sonarLeft < 20) {
      turnLeft();
      backUp(1000);
    } else if (sonarRight < 20) {
      turnRight();
      backUp(1000);
    } else {
      releaseDirection();
    }
  } else {
    if (sonarLeft < sonarRight){
      turnLeft();
      backUp(1000);
    } else if (sonarLeft > sonarRight) {
      turnRight();
      backUp(1000);
    } else if (sonarLeft < 20) {
      turnLeft();
      backUp(1000);
    } else if (sonarRight < 20) {
      turnRight();
      backUp(1000);
    } else {
      releaseDirection();
      backUp(1000);
    }
  }
}
