#include "../Sonars/Sonars.h"
#include "../NewPing/NewPing.h"
#include "../AFMotor/AFMotor.h"
#include "../Wheels/Wheels.h"

#define SONAR_LEFT 0
#define SONAR_CENTER 1
#define SONAR_RIGHT 2

void setup() {
  sonarsSetup();
}

void loop() {
  sonarsLoop();
  decideMove();
}

void decideMove() {
  unsigned int sonarCenter = getSonarDistance(SONAR_CENTER);
  unsigned int sonarLeft = getSonarDistance(SONAR_LEFT);
  unsigned int sonarRight = getSonarDistance(SONAR_RIGHT);

  if(sonarCenter > 40) {
    moveForward(200); // Move the car forward with the certain speed
  } else if (sonarLeft < sonarRight) {
    turnRight(250);
  } else {
    turnLeft(250);
  }
}
