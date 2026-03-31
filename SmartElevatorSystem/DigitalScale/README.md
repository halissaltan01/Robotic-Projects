# High-Precision Load Cell Instrumentation & Digital Weighing System ⚖️🚨

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-orange.svg)](https://www.arduino.cc/)

## 📌 Project Overview
This project focuses on the development of a digital weighing system utilizing a **strain gauge load cell** and the **HX711 24-bit Analog-to-Digital Converter (ADC)**. The system is engineered to provide high-precision mass measurement with a real-time safety alert mechanism. It implements signal conditioning and digital filtering (averaging) to ensure stable readings in industrial prototyping environments.

## 🚀 Key Technical Features
* **High-Resolution Data Acquisition:** Leverages the HX711 amplifier to process micro-volt level signals from the load cell into digital weight data.
* **Safety HMI (Human-Machine Interface):** Features a dual-alert system (Visual Red LED & Audible Piezo Buzzer) that triggers when a predefined weight threshold is exceeded.
* **Dynamic Calibration:** Implements a software-based calibration factor and a "Tare" function to ensure zero-point accuracy before measurement.
* **Real-time Telemetry:** Provides continuous data streaming via Serial Monitor for system debugging and payload tracking.

## 🛠️ Hardware Architecture
* **Microcontroller:** Arduino Uno / Nano / Mega
* **Instrumentation:** HX711 Load Cell Amplifier (24-bit High-Precision ADC)
* **Sensing:** Strain Gauge Load Cell (Weight Sensor)
* **Feedback:** High-Intensity Red LED & Piezoelectric Buzzer
* **Power:** USB or External DC Supply

## 🔌 System Pin Configuration
| Component | Arduino Pin | Function |
| :--- | :--- | :--- |
| **HX711 DOUT** | 4 | Data Output |
| **HX711 SCK** | 5 | Serial Clock Input |
| **Red LED** | 10 | Visual Alarm Output |
| **Buzzer** | 11 | Audible Alarm Output |

## ⚙️ Engineering Principles Applied
* **Signal Conditioning:** Amplifying low-voltage differential signals from a Wheatstone bridge circuit.
* **Digital Filtering:** Implementing sample averaging to reduce noise and enhance measurement stability.
* **Threshold Detection:** Developing conditional logic for automated safety protocols in payload management.
* **Instrumentation Calibration:** Calculating and applying linear scaling factors for accurate physical unit conversion.

## 📂 Installation & Usage
1.  **Hardware Connection:** Wire the HX711 and Load Cell according to the pin map provided.
2.  **Calibration:**
    * Find the `calibration_factor` in the source code.
    * Adjust this value by testing with a known reference weight until the output is accurate.
3.  **Deployment:** Upload the firmware and monitor real-time weight data via the Serial Monitor (9600 baud).

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering student, specializing in Embedded Systems and Instrumentation.*