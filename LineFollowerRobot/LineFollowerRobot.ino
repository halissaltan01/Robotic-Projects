/*
  5-Channel Line Follower Robot using HCRT5000 Sensors and L298N Motor Driver
  --------------------------------------------------------------------------
  This Arduino sketch controls a line follower robot using 5 HCRT5000 infrared
  sensors, two brushed DC motors, and an L298N motor driver.

  Hardware:
    - Arduino Uno / Nano / Mega
    - 5 x HCRT5000 Infrared Sensors (S1-S5)
    - 2 x Brushed DC Motors
    - L298N Motor Driver Module
    - Jumper wires & power supply

  Pin Configuration:
    Motor A: ENA (9), IN1 (8), IN2 (7)
    Motor B: ENB (10), IN3 (6), IN4 (5)
    Sensors: S1 (12), S2 (11), S3 (4), S4 (13), S5 (2)

  Functionality:
    - Robot moves forward when center sensor detects the line
    - Slight turns when side sensors detect line
    - Stops if no sensor detects the line
*/

#define ENA 9   // Motor A speed
#define IN1 8   // Motor A direction 1
#define IN2 7   // Motor A direction 2
#define IN3 6   // Motor B direction 1
#define IN4 5   // Motor B direction 2
#define ENB 10  // Motor B speed

#define S1 12
#define S2 11
#define S3 4
#define S4 13
#define S5 2

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  if (digitalRead(S3) == LOW) {
    moveForward(130);
  } else if (digitalRead(S2) == LOW) {
    turnLeftSlight(100);
  } else if (digitalRead(S4) == LOW) {
    turnRightSlight(100);
  } else if (digitalRead(S5) == LOW) {
    turnLeftSharp(130);
  } else if (digitalRead(S1) == LOW) {
    turnRightSharp(130);
  } else {
    stopRobot();
  }
}

void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeftSharp(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnRightSharp(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeftSlight(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, 0);
}

void turnRightSlight(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, speed);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
