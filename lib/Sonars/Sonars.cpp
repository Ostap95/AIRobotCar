#include "Arduino.h"
#include "Sonars.h"
#include "../NewPing/NewPing.h"

#define SONAR_NUM     3 // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).
#define LEFT_SONAR_TRIGGER 22
#define LEFT_SONAR_ECHO 23
#define CENTER_SONAR_TRIGGER 24
#define CENTER_SONAR_ECHO 25
#define RIGHT_SONAR_TRIGGER 26
#define RIGHT_SONAR_ECHO 27


unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.

NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(LEFT_SONAR_TRIGGER, LEFT_SONAR_ECHO, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. LEFT SENSOR
  NewPing(CENTER_SONAR_TRIGGER, CENTER_SONAR_ECHO, MAX_DISTANCE), // CENTER SENSOR
  NewPing(RIGHT_SONAR_TRIGGER, RIGHT_SONAR_ECHO, MAX_DISTANCE)  // RIGHT SENSOR

};

unsigned int getSonarDistance(int i) {
  if (cm[i] == 0) cm[i] = 200;
  return cm[i];
}
void sonarsSetup(void) {
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}

void sonarsLoop(void) {
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == SONAR_NUM - 1) printCycle(); // Sensor ping cycle complete, do something with the results.
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }
}

void echoCheck(void) { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void printCycle(void) {
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm ");
  }
  Serial.println();
}
