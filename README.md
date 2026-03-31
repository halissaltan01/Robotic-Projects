# Integrated Smart Logistics Elevator System: From Sensing to Automation 🏗️⚖️

This repository showcases the iterative development of an industrial-grade elevator prototype. The project is structured into three distinct modules, demonstrating a transition from individual sensor instrumentation to a fully integrated, safety-critical autonomous system.

## 📌 Project Architecture
To maintain high modularity and clean engineering standards, the project is divided into the following phases:

### 📁 [1. Digital Scale Module](./1_Digital_Scale_Module)
* **Focus:** Precision Instrumentation & Measurement.
* **Core Tech:** Strain Gauge Load Cell, HX711 (24-bit ADC).
* **Summary:** Implements signal conditioning and digital filtering to convert raw analog data into precise mass measurements.

### 📁 [2. Elevator Motion Module](./2_Elevator_Motion_Module)
* **Focus:** Autonomous Vertical Navigation.
* **Core Tech:** HC-SR04 Ultrasonic Sensor, L298N Motor Driver.
* **Summary:** Uses real-time distance feedback and threshold-based logic (Guard Bands) to manage elevator levels autonomously without mechanical collisions.

### 📁 [3. Integrated Smart System](./3_Integrated_Smart_System)
* **Focus:** System Integration & Safety Engineering.
* **Core Tech:** Full Sensor Fusion (Weight + Distance + HMI).
* **Summary:** The "Capstone" of the project. It integrates both modules to create a **Safety Interlock System**. The elevator prevents all movement if the payload exceeds 100kg and provides a 3-stage visual/audible alert system (Green/Yellow/Red + Buzzer).

---

## 🚀 Key Engineering Features
* **Safety Interlocks:** Hard-coded logic preventing motor actuation during overload conditions.
* **Signal Processing:** Average filtering for weight stability and pulse-width timing for distance precision.
* **HMI (Human-Machine Interface):** Real-time feedback via I2C LCD and multi-stage status indicators.
* **Fail-Safe Design:** Threshold-based decision making to handle sensor noise and environmental jitter.

## 🛠️ Hardware Stack
* **Microcontroller:** Arduino Uno / Mega
* **Sensors:** Load Cell (Weight), HC-SR04 (Ultrasonic Distance)
* **Actuators:** DC Gear Motors with L298N H-Bridge
* **UI Elements:** 16x2 I2C LCD, LEDs, Piezo Buzzer

## 💻 Tech Stack
* **Language:** Embedded C++ (Arduino)
* **Logic:** Asynchronous Control Loops, State-Based Decision Making.

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering student, specializing in System Integration and Industrial Automation.*
