# Autonomous Industrial Elevator System with Load-Sensitive Safety Protocols 🏗️

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

## 📌 Executive Summary
This project presents a high-fidelity prototype of an **Integrated Industrial Elevator System**. It combines ultrasonic distance tracking with load-cell weight sensing to create an autonomous, safety-first vertical transport solution. The system is engineered to handle real-time sensor data and execute hardware-level safety interrupts (Interlocks) during critical overload conditions.

## 🛠️ System Architecture & Engineering Principles
The system operates on an asynchronous control loop, managing two primary feedback systems:

1.  **Safety Interlock (Weight Management):** Utilizing an **HX711 Load Cell Amplifier**, the system monitors payload in real-time. A hard-coded safety threshold (100kg) acts as a digital circuit breaker, disabling motor actuation and triggering a 3-stage visual/audible HMI (Human-Machine Interface).
2.  **Autonomous Navigation (Vertical Control):** An **HC-SR04 Ultrasonic Sensor** provides spatial feedback. The controller implements threshold-based logic to manage floor leveling and automated direction switching.
3.  **Fail-Safe Design:** The firmware includes guard bands for sensor noise and immediate "Stop-on-Failure" protocols.

## ⚙️ Technical Specifications & Stack
* **Microcontroller:** ATmega328P (Arduino Uno)
* **Sensors:** Load Cell (Precision Strain Gauge), HC-SR04 (Ultrasonic)
* **Actuators:** Dual DC Gear Motors with **L298N H-Bridge** speed/direction control
* **HMI/Display:** I2C 16x2 LCD, Multi-colored Status LEDs, Piezo Acoustic Alarm
* **Communication:** I2C Protocol, Serial Telemetry (9600 baud)

## 🚦 Safety Protocol Logic
| Payload Range | Status | LED Indicator | Acoustic Alarm | Motor State |
| :--- | :--- | :--- | :--- | :--- |
| < 80kg | Safe | 🟢 Green | Silent | Active |
| 80kg - 99kg | Warning | 🟡 Yellow | Silent | Active |
| ≥ 100kg | **CRITICAL OVERLOAD** | 🔴 Red | **ACTIVE** | **LOCKED (Disabled)** |

## 📂 Installation
1. Ensure the `HX711` and `LiquidCrystal_I2C` libraries are installed in your Arduino IDE.
2. Clone the repository: `git clone https://github.com/halissaltan01/Integrated-Smart-Elevator.git`
3. Wire the hardware according to the `/docs/schematics.png`.
4. Upload `src/SmartElevator.ino` and monitor via Serial Port.

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering Student at Adana Alparslan Türkeş Science and Technology University.*