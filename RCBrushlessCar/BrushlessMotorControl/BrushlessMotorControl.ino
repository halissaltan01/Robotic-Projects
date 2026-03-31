/*
  Brushless Hoverboard Motor Test using ZS-X11H Motor Controller
  -------------------------------------------------------------
  This Arduino sketch tests a single hoverboard brushless motor (BLDC)
  using the ZS-X11H motor controller.

  Motor Wiring (Motor → Controller):
    - MA (yellow) → MA terminal
    - MB (blue)   → MB terminal
    - MC (green)  → MC terminal
  Note: Wire colors may vary slightly depending on your motor.

  Arduino → Controller Connections:
    - motorPin1 = 6 (PWM for motor)
    - motorPin2 = 7 (PWM for motor)
    - dirPin1   = 9 (Direction 1)
    - dirPin2   = 10 (Direction 2)

  Author: Halis Mustafa Saltan 
  Date: August 2024
*/

int motorPin1 = 6; // PWM pin for motor phase A
int motorPin2 = 7; // PWM pin for motor phase B
int dirPin1 = 9;   // Direction control pin 1
int dirPin2 = 10;  // Direction control pin 2

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  // Forward direction
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);

  for(int spd = 0; spd < 100; spd++){
    analogWrite(motorPin1, spd);
    analogWrite(motorPin2, spd);
    delay(500);
  }
  stopMotors();
  delay(2500);

  // Backward direction
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);

  for(int spd = 0; spd < 100; spd++){
    analogWrite(motorPin1, spd);
    analogWrite(motorPin2, spd);
    delay(500);
  }
  stopMotors();
  delay(2500);
}

void stopMotors() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
}
