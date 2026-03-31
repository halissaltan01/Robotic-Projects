/*
 * Project: Smart Elevator System with Distance Sensing
 * Author: Halis Saltan
 * Description: Automated elevator control using HC-SR04 ultrasonic sensor and L298N motor driver.
 */

#define echoPin 4
#define trigPin 5

// L298N Motor Driver Pins
const int enA = 6;
const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;

// Operational Parameters
const int MAX_DISTANCE = 45; // Upper limit in cm
const int MIN_DISTANCE = 5;  // Lower limit in cm
const int MOTOR_SPEED = 200; // PWM value (0-255)

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
}

void loop() {
  int currentDist = getDistance();
  Serial.print("Distance: "); Serial.println(currentDist);

  // Asansör Mantığı
  if (currentDist >= MAX_DISTANCE) {
    stopMotors();
    delay(1000);
    moveDown(); 
  } 
  else if (currentDist <= MIN_DISTANCE && currentDist > 0) { 
    stopMotors();
    delay(1000);
    moveUp();
  }
  
  delay(100); // Sensör kararlılığı için kısa bir bekleme
}

int getDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  
  return (distance > 0 && distance < 400) ? distance : 0;
}

void moveUp() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, MOTOR_SPEED);
}

void moveDown() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, MOTOR_SPEED);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
}