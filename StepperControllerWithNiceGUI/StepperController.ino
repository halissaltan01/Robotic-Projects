#include <AccelStepper.h>

#define HALFSTEP 8

#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11

AccelStepper stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

enum state {STOPPED, FORWARD, BACKWARD};

state currentState = STOPPED;

byte value;

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(500.0);
  stepper.setCurrentPosition(0);
}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();
    if (value == '1') {
      moveForward();
    }
    if (value == '2') {
      moveBackward();
    }
    if (value == '0') {
      stopMotor();
    }
  }

  if (currentState == FORWARD) {
    Serial.println(stepper.currentPosition());
    stepper.runSpeed();
  }
  else if (currentState == BACKWARD) {
    Serial.println(stepper.currentPosition());
    stepper.runSpeed();
  }
}

void moveForward() {
  Serial.println("Motor is moving forward...");
  stepper.setSpeed(500);
  currentState = FORWARD;
}

void moveBackward() {
  Serial.println("Motor is moving backward...");
  stepper.setSpeed(-500);
  currentState = BACKWARD;
}

void stopMotor() {
  Serial.println("Motor has stopped.");
  currentState = STOPPED;
}
