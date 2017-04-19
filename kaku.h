#include <NewPing.h>

#include <NewPing.h>
#define MAX_distanceANCE 200

const int leftMotorDirection = 4;
const int leftMotorSpeed = 5;

const int rightMotorSpeed = 6;
const int rightMotorDirection = 7;

const int SonarVcc = 8;
const int SonarEcho = 10;
const int SonarTrig = 9;
const int SonarGnd = 11;

NewPing sonar(SonarTrig, SonarEcho, MAX_distanceANCE);

#define FORWARD LOW
#define REVERSE HIGH
#define STOP LOW

#define sonarSensor sonar.ping_cm()

void setupRobot(void){
  pinMode(SonarVcc, OUTPUT);
  pinMode(SonarGnd, OUTPUT);
  digitalWrite(SonarVcc, HIGH);
  digitalWrite(SonarGnd, LOW);
  Serial.begin(9600);

  pinMode(leftMotorDirection, OUTPUT);
  pinMode(leftMotorSpeed, OUTPUT);
  pinMode(rightMotorDirection, OUTPUT);
  pinMode(rightMotorSpeed, OUTPUT);
}


void setup() {
  
}

int distance = 0;

void goForward(int d){
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection, FORWARD);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, FORWARD);  
    delay(d);
}

void turnLeft(int d){
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection, REVERSE);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, FORWARD);  
    delay(d);
}

void goBackward(int d){
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection, REVERSE);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, REVERSE);  
    delay(d);
}

void turnRight(int d){
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection, FORWARD);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, REVERSE);  
    delay(d);
}

void rukJa(int d){
    digitalWrite(leftMotorSpeed, LOW);
    digitalWrite(rightMotorSpeed, LOW);
    delay(d);
}
