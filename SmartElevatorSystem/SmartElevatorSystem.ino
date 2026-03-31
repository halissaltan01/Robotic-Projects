/*
 * Project: Integrated Smart Elevator System with Load-Sensitive Safety Interlock
 * Author: Halis Saltan
 * Description: An automated elevator controller that integrates weight sensing (HX711) 
 * and distance tracking (HC-SR04). Includes a 3-stage safety alert system and 
 * prevents operation during overload conditions (>100kg).
 */

#include "HX711.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- Pin Configuration ---
// Weight Sensor (HX711)
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN  = 3;

// Distance Sensor (HC-SR04)
const int ULTRASONIC_ECHO_PIN = 4;
const int ULTRASONIC_TRIG_PIN = 5;

// Safety Feedback (LEDs & Buzzer)
const int PIN_LED_RED    = 11;
const int PIN_LED_YELLOW = 12;
const int PIN_LED_GREEN  = 13;
const int PIN_BUZZER     = A0; 

// Motor Driver (L298N)
const int PIN_ENA = 6;
const int PIN_IN1 = 7;
const int PIN_IN2 = 8;
const int PIN_IN3 = 9;
const int PIN_IN4 = 10;

// --- Operational Constants ---
const float CALIBRATION_FACTOR = 1700.0; 
const int DIST_THRESHOLD_MAX   = 45; // cm
const int DIST_THRESHOLD_MIN   = 5;  // cm
const int DEFAULT_MOTOR_SPEED  = 200; // PWM (0-255)
const float WEIGHT_LIMIT_CRITICAL = 100.0; // kg
const float WEIGHT_LIMIT_WARNING  = 80.0;  // kg

// --- Objects ---
HX711 scale;
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  
  // Pin Initialization
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(PIN_IN1, OUTPUT); pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT); pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  // Peripheral Initialization
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(CALIBRATION_FACTOR);
  scale.tare(); 
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Booting..");
  delay(1500);
}

void loop() {
  float currentWeight = scale.get_units(5);
  if (currentWeight < 0) currentWeight = 0; 
  
  int currentDistance = readUltrasonicDistance();

  updateSafetyAlerts(currentWeight);
  updateLCD(currentWeight, currentDistance);

  // --- Core Control Logic with Safety Interlock ---
  if (currentWeight < WEIGHT_LIMIT_CRITICAL) {
    handleElevatorMovement(currentDistance);
  } else {
    // Overload Protection: Immediate Shutdown
    stopMotors();
  }

  delay(100); 
}

// Helper: Distance Measurement
int readUltrasonicDistance() {
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  
  long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  int distance = duration / 58.2;
  return (distance > 0 && distance < 400) ? distance : 0;
}

// Helper: Safety System Management
void updateSafetyAlerts(float weight) {
  if (weight >= WEIGHT_LIMIT_CRITICAL) {
    digitalWrite(PIN_LED_RED, HIGH);
    digitalWrite(PIN_LED_YELLOW, LOW);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_BUZZER, HIGH); 
  } 
  else if (weight >= WEIGHT_LIMIT_WARNING) {
    digitalWrite(PIN_LED_RED, LOW);
    digitalWrite(PIN_LED_YELLOW, HIGH);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_BUZZER, LOW);
  } 
  else {
    digitalWrite(PIN_LED_RED, LOW);
    digitalWrite(PIN_LED_YELLOW, LOW);
    digitalWrite(PIN_LED_GREEN, HIGH);
    digitalWrite(PIN_BUZZER, LOW);
  }
}

// Helper: LCD Interface
void updateLCD(float weight, int dist) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Weight: "); lcd.print(weight, 1); lcd.print("kg");
  
  lcd.setCursor(0, 1);
  if (weight >= WEIGHT_LIMIT_CRITICAL) {
    lcd.print("!! OVERLOAD !!");
  } else {
    lcd.print("Dist: "); lcd.print(dist); lcd.print("cm");
  }
}

// Helper: Movement Logic
void handleElevatorMovement(int dist) {
  if (dist >= DIST_THRESHOLD_MAX) {
    stopMotors();
    delay(1000);
    moveDown(); 
  } 
  else if (dist <= DIST_THRESHOLD_MIN && dist > 0) { 
    stopMotors();
    delay(1000);
    moveUp();
  }
}

void moveUp() {
  digitalWrite(PIN_IN1, HIGH); digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);  digitalWrite(PIN_IN4, HIGH);
  analogWrite(PIN_ENA, DEFAULT_MOTOR_SPEED);
}

void moveDown() {
  digitalWrite(PIN_IN1, LOW);  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, HIGH); digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENA, DEFAULT_MOTOR_SPEED);
}

void stopMotors() {
  digitalWrite(PIN_IN1, LOW);  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENA, 0);
}