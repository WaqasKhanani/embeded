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

void setupRobot(void)
{
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
Serial.begin(9600);

pinMode(SonarTrig,OUTPUT);

pinMode(SonarEcho,INPUT);

pinMode(leftMotorDirection, OUTPUT);
pinMode(leftMotorSpeed, OUTPUT);
pinMode(rightMotorDirection, OUTPUT);
pinMode(rightMotorSpeed, OUTPUT);

}

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

inches = duration / 74 / 2;//converts the time duration into inches

cm = duration / 29 / 2;//converts the time duration to cm

if(cm>30)//checks for the distance is greater than 4cm
{
//the bot forward if the condition is true

digitalWrite(leftMotorDirection ,HIGH);//Both the motors are in ON state
digitalWrite(leftMotorSpeed ,HIGH);//Both the motors are in ON state

digitalWrite(rightMotorDirection ,HIGH);
digitalWrite(rightMotorSpeed ,HIGH);//Both the motors are in ON state

Serial.print("No obstacle detected");
}

else
 {
  
//the robot turns right when an obstacle is detected

digitalWrite(leftMotorDirection ,LOW);//the left motor is in ON state
digitalWrite(rightMotorDirection ,HIGH);//the right motor is in OFF state
digitalWrite(leftMotorSpeed ,LOW);//Both the motors are in ON state
digitalWrite(rightMotorSpeed ,HIGH);//Both the motors are in ON state

Serial.print("Obstacle detected");

delay(100);//this delays the process by 100millisec

Serial.print(inches);

Serial.print("in, ");

Serial.print(cm);

Serial.print("cm");

Serial.println();

delay(100);//this delays the code by 0.1 second and repeats the loop again

}
delay(500);
}
