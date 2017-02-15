#include "../Sonars/Sonars.h"
#include "../NewPing/NewPing.h"
#include "../AFMotor/AFMotor.h"
#include "../Wheels/Wheels.h"

#define SONAR_LEFT 0
#define SONAR_CENTER 1
#define SONAR_RIGHT 2
char buf;

void setup() {
  sonarsSetup();
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0)
  {
    buf = Serial.read();
    if (buf == '1') Serial.println("Working");
  }
  //sonarsLoop();
  //decideMove();
}

void decideMove() {
  unsigned int sonarCenter = getSonarDistance(SONAR_CENTER);

  if(sonarCenter > 40 || sonarCenter == 0) moveForward(200); // Move the car forward with the certain speed
  else stopCar();
  decideTurn();
}

void decideTurn() {
  unsigned int sonarLeft = getSonarDistance(SONAR_LEFT);
  unsigned int sonarRight = getSonarDistance(SONAR_RIGHT);

  if((sonarLeft > 40 && sonarRight > 40) || (sonarLeft == 0 || sonarRight == 0)) return;
  if((sonarLeft < 20 || sonarRight < 20) && (sonarLeft != 0 || sonarRight != 0)) stopCar();
  if(sonarLeft < 40) turnRight(250, 4000);
  if(sonarRight < 40) turnLeft(250, 4000);
}
