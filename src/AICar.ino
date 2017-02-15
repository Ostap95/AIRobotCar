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

  if(sonarCenter > 40 || sonarCenter > 0) driveForward(); // Move the car forward with the certain speed
  else stopCar();
  decideTurn();
}

void decideTurn() {
  unsigned int sonarLeft = getSonarDistance(SONAR_LEFT);
  unsigned int sonarRight = getSonarDistance(SONAR_RIGHT);

  if((sonarLeft > 40 && sonarRight > 40) || (sonarLeft == 0 || sonarRight == 0)) return;
  if((sonarLeft < 20 || sonarRight < 20) && (sonarLeft != 0 || sonarRight != 0)) stopMotors();
  if(sonarLeft < 40) turnRight();
  if(sonarRight < 40) turnLeft();
}
