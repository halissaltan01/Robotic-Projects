# High-Torque BLDC Propulsion & Remote Steering System (ZS-X11H ESC) 🏎️💨

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
[![Category: Robotics](https://img.shields.io/badge/Category-Robotics-red.svg)]()

## 📌 Project Overview
This project involves the development of a manual control system for a high-performance **Brushless DC (BLDC)** powered vehicle. Utilizing an Arduino and the **ZS-X11H ESC**, the system manages multi-directional navigation (Forward, Backward, Left, Right) via a 4-button tactile interface. The core innovation lies in the **Dynamic Speed Profiling** algorithm, which ensures smooth acceleration and constant speed holding to prevent high-current surges.

## 🚀 Key Technical Features
* **Manual UI Integration:** A 4-button control matrix for real-time actuation and steering.
* **Soft-Start & Ramping Algorithm:** Implements gradual PWM duty cycle increases to manage motor inertia and protect the power electronics from sudden torque demands.
* **H-Bridge Directional Logic:** Hardware-level signal management for seamless switching between clockwise and counter-clockwise rotation.
* **Constant Speed Maintenance:** Optimized control loop that holds the target velocity once the desired ramp-up is achieved.

## 🛠️ Hardware Architecture
* **Microcontroller:** Arduino Uno / Nano / Mega
* **Electronic Speed Controller (ESC):** ZS-X11H High-Power Brushless Driver
* **Actuator:** High-Torque 3-Phase BLDC Motor
* **Control Interface:** 4 x Tactile Push Buttons (Pulldown Configuration)

## 🔌 System Pin Configuration
### Arduino to Controller & UI
| Arduino Pin | Functional Unit | Description |
| :--- | :--- | :--- |
| **6 / 11** | **PWM Control** | Primary & Secondary Speed Signals |
| **4 / 5** | **Direction Logic** | DIR 1 & DIR 2 Pins |
| **8 / 9** | **Y-Axis Input** | Forward & Backward Buttons |
| **10 / 12** | **X-Axis Input** | Left & Right Steering Buttons |

## ⚙️ Engineering Principles Applied
* **User-Machine Interaction:** Mapping tactile digital inputs to complex analog motor responses.
* **Motion Profiling:** Calculating acceleration curves for high-inertia brushless systems.
* **Signal Integrity:** Managing multiple input signals simultaneously in a non-blocking execution loop.
* **Power Electronics Interfacing:** Handling high-voltage motor phases through low-voltage logic control.

## 📂 Installation & Usage
1.  **Wiring:** Connect the BLDC phases (MA, MB, MC) and the button matrix as defined in the Pin Map.
2.  **Safety First:** Ensure the power supply matches the motor's rated voltage (e.g., 24V-36V) before testing.
3.  **Deployment:** Upload `RC_BrushlessCar.ino` and use the 4-button remote to navigate.
4.  **Observation:** Notice the gradual speed buildup, designed to protect the drivetrain.

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering student, specializing in Power Systems and Mobility.*