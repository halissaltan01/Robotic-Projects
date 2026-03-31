/*
  RC Brushless Car using 4-Button Remote and ZS-X11H ESC
  ------------------------------------------------------
  This Arduino sketch controls a brushless DC motor car using a 4-button remote
  and the ZS-X11H motor controller (same as used in HoverboardMotorTest project).

  Hardware:
    - Brushless motor(s) connected to ZS-X11H motor controller
    - 4 push buttons: Forward, Backward, Left, Right

  Arduino → ZS-X11H Controller Connections:
    - motorPin1 = 6 (PWM 1)
    - motorPin2 = 11 (PWM 2)
    - dirPin1   = 4 (Direction 1)
    - dirPin2   = 5 (Direction 2)
    - pinA      = 8 (Forward button)
    - pinB      = 9 (Backward button)
    - pinC      = 10 (Left button)
    - pinD      = 12 (Right button)
*/


int motorPin1 = 6;
int motorPin2 = 11;
int dirPin1 = 4;
int dirPin2 = 5;

int pinA = 8;  // Forward
int pinB = 9;  // Backward
int pinC = 10; // Left
int pinD = 12; // Right

int valueA, valueB, valueC, valueD;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);
}

void loop() {
  // Read button states
  valueA = digitalRead(pinA);
  valueB = digitalRead(pinB);
  valueC = digitalRead(pinC);
  valueD = digitalRead(pinD);
  
  // Forward
  if(valueA != 0){
    delay(100);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    rampUp(35, pinA);  // Gradual speed increase
    holdSpeed(35, pinA); // Maintain constant speed
  }

  // Backward
  if(valueB != 0){
    delay(100);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    rampUp(35, pinB);
    holdSpeed(35, pinB);
  }

  // Turn Left
  if(valueC != 0){
    delay(100);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, HIGH);
    rampUp(35, pinC);
    holdSpeed(35, pinC);
  }

  // Turn Right
  if(valueD != 0){
    delay(100);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, LOW);
    rampUp(35, pinD);
    holdSpeed(35, pinD);
  }
}

// Gradually increase motor speed until maxSpeed or button release
void rampUp(int maxSpeed, int buttonPin){
  for(int spd = 0; spd < maxSpeed; spd++){
    analogWrite(motorPin1, spd);
    analogWrite(motorPin2, spd);
    delay(100);  
    if(digitalRead(buttonPin) == 0){
      stopMotors();
      break;
    }
  }
}

// Maintain constant speed until button release
void holdSpeed(int speed, int buttonPin){
  while(digitalRead(buttonPin) != 0){
    analogWrite(motorPin1, speed);
    analogWrite(motorPin2, speed);
    if(digitalRead(buttonPin) == 0){
      stopMotors();
      break;
    }
  }
}

// Stop motors
void stopMotors(){
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
}
