/*
  Weight Measurement System with HX711, LED, and Buzzer
  ------------------------------------------------------
  This Arduino sketch demonstrates how to measure weight using the HX711 load
  cell amplifier. The system provides a simple safety/alert mechanism: 
  if the measured weight exceeds a predefined threshold, an LED and a buzzer 
  are activated.

  Hardware:
    - HX711 Load Cell Amplifier
    - Load Cell Sensor
    - Arduino (Uno, Nano, etc.)
    - Red LED (connected to pin 10)
    - Buzzer (connected to pin 11)

  Pin Connections:
    HX711 DOUT -> Arduino pin 4
    HX711 SCK  -> Arduino pin 5
    LED        -> Arduino pin 10
    Buzzer     -> Arduino pin 11

  Features:
    - Calibrated weight measurement using HX711
    - Adjustable calibration factor for accurate readings
    - Audible and visual alert when weight ≥ 50 units
    - Serial Monitor feedback

  How it works:
    1. The system reads weight from the HX711 load cell.
    2. If weight ≥ 50, the LED and buzzer turn on.
    3. Otherwise, they remain off.
    4. Real-time readings are printed in Serial Monitor.

  Author: Halis Mustafa
  Date: September 2025
*/

#include "HX711.h"

#define DOUT_PIN 4
#define SCK_PIN  5
#define RED_LED  10
#define BUZZER   11

HX711 scale;

float calibration_factor = 1700; // Adjust this value for proper calibration

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  scale.begin(DOUT_PIN, SCK_PIN);
  scale.set_scale(calibration_factor); 
  scale.tare(); // Reset the scale to zero
}

void loop() {
  float weight = scale.get_units(10); // Average of 10 readings

  Serial.print("Weight: ");
  Serial.println(weight);

  if (weight >= 50) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  delay(100);
}
