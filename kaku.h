#include <NewPing.h>
#define MAX_distanceANCE 200
#define MAX_DISTANCE_FROM_OBSTACLE_IN_CMS 20
const int leftMotorDirection = 4;
const int leftMotorSpeed = 5;
const int rightMotorSpeed = 6;
const int rightMotorDirection = 7;
const int SonarVcc = 8;
const int SonarEcho = 10;
const int SonarTrig = 9;
const int SonarGnd = 11;
NewPing sonar(SonarTrig, SonarEcho, MAX_distanceANCE);
#define FORWARD HIGH
#define REVERSE LOW
#define STOP LOW
#define sonarSensor sonar.ping_cm()
const int dist = 0;
int leftdist = 0;
int rightdist = 0;
int object = 10;  
void setupRobot(void)
{
  pinMode(SonarTrig,OUTPUT);
  pinMode(SonarEcho,INPUT);
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
long duration, inches, cm;
void setup()
{
setupRobot();
}
int count = 0;
void loop()
{
digitalWrite(SonarTrig, LOW);
delayMicroseconds(2);
digitalWrite(SonarTrig, HIGH);
delayMicroseconds(5);
digitalWrite(SonarTrig, LOW);
duration = pulseIn(SonarEcho, HIGH);
//this returns the time duration taken
//for the ultrasonics to hit an obstacle and return
unsigned int distanceInCms = sonar.ping() / US_ROUNDTRIP_CM; // Send ping, get ping time in microseconds (uS) and convert it to centimeters (cm)
Serial.println("Distance: " + String(distanceInCms) + "cm");
  if(distanceInCms != NO_ECHO && distanceInCms < MAX_DISTANCE_FROM_OBSTACLE_IN_CMS) 
 {               
   findroute(100);
 }
 else
 {
 goForward(100);
}
}
int distance = 0;
void goForward(int d)
{
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection, FORWARD);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, FORWARD);  
    delay(d);
}
void turnLeft(int d)
{
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection,REVERSE);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, FORWARD);  
    delay(d);
}
void goBackward(int d)
{
    digitalWrite(leftMotorSpeed, HIGH);
    digitalWrite(leftMotorDirection, REVERSE);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, REVERSE);  
    delay(d);
}
void turnRight(int d)
{
    analogWrite(leftMotorSpeed, 155);
    digitalWrite(leftMotorDirection, FORWARD);
    digitalWrite(rightMotorSpeed, HIGH);
    digitalWrite(rightMotorDirection, REVERSE);  
    delay(d);
    halt(100);
}
void halt(int d)
{
    digitalWrite(leftMotorSpeed, LOW);
    digitalWrite(rightMotorSpeed, LOW);
    delay(d);
}
void findroute(int d)
{
 halt(100);                                             // stop                      //go to subroutine lookright                            
 if ( leftdist < rightdist )
 {
   turnLeft(1000);
 }
else
{
  turnRight (1000);
}
}



