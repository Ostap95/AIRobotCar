#include "../Sonars/Sonars.h"
#include "../NewPing/NewPing.h"
#include "../AFMotor/AFMotor.h"
#include "../Wheels/Wheels.h"

#define SONAR_LEFT 0
#define SONAR_CENTER 1
#define SONAR_RIGHT 2
#define BACKUP_TIME 2000

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
    } else {
      releaseDirection();
    }
    if (sonarLeft < 20) {
      turnLeft();
      delay(200);
      backUp(BACKUP_TIME);
      releaseDirection();

    }
    if (sonarRight < 20) {
      turnRight();
      delay(200);
      backUp(BACKUP_TIME);
      releaseDirection();
    }
  } else {
    if (sonarLeft < sonarRight){
      turnLeft();
      backUp(BACKUP_TIME);
      releaseDirection();
    } else if (sonarLeft > sonarRight) {
      turnRight();
      backUp(BACKUP_TIME);
      releaseDirection();
    } else {
      releaseDirection();
      backUp(BACKUP_TIME);
    }
  }
}
