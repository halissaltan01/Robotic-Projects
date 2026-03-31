# BLDC Motor Actuation & Performance Profiling (ZS-X11H Interface) 🏎️⚡

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
[![Category: Power Electronics](https://img.shields.io/badge/Category-Power%20Electronics-red.svg)]()

## 📌 Project Overview
This project focuses on the implementation of a control system for **High-Torque Brushless DC (BLDC)** motors, commonly found in electric hoverboards. Using an Arduino and the **ZS-X11H Motor Controller**, the system manages motor commutation, bi-directional rotation, and speed modulation. The project demonstrates a robust method for testing and profiling BLDC performance through **PWM (Pulse Width Modulation)** duty cycle ramping.

## 🚀 Key Technical Features
* **Bi-directional Motion Control:** Seamless switching between forward and reverse rotation via hardware-level direction pins.
* **Dynamic Speed Ramping:** Implementation of an acceleration/deceleration algorithm to prevent high-current spikes and mechanical stress during startup.
* **PWM Duty Cycle Modulation:** Precise control over motor RPM using high-frequency PWM signals.
* **Power Electronic Interfacing:** Managing 3-phase (MA, MB, MC) motor commutation through an industrial-grade ZS-X11H driver module.

## 🛠️ System Architecture
* **Microcontroller:** ATmega328P (Arduino Family)
* **Motor Driver:** ZS-X11H Brushless DC Controller
* **Actuator:** High-Torque Hoverboard BLDC Motor (3-Phase)
* **Control Method:** Open-loop Speed Control with Pulse Width Modulation

## 🔌 System Pin Configuration
### Arduino to Controller Interface
| Arduino Pin | Function | Description |
| :--- | :--- | :--- |
| **6** | PWM 1 | Motor Speed Control (Duty Cycle) |
| **7** | PWM 2 | Secondary Speed/Braking Control |
| **9** | DIR 1 | Rotation Direction Pin 1 |
| **10** | DIR 2 | Rotation Direction Pin 2 |

### Motor to Controller (3-Phase)
| Motor Phase | Controller Terminal | Function |
| :--- | :--- | :--- |
| **MA (Yellow)** | MA | Stator Phase A |
| **MB (Blue)** | MB | Stator Phase B |
| **MC (Green)** | MC | Stator Phase C |

## ⚙️ Engineering Principles Applied
* **BLDC Commutation Logic:** Understanding the logic required to drive 3-phase brushless systems in an open-loop configuration.
* **Power Management:** Managing the interface between low-power logic (Arduino) and high-power actuators (Motor).
* **Motion Profiling:** Developing code-based "Soft Start" routines to optimize motor longevity and battery efficiency.

## 📂 Installation & Usage
1.  **Hardware Connection:** Connect the BLDC phases and Arduino pins according to the tables above.
2.  **Safety Check:** Ensure your power supply matches the motor's voltage requirements (typically 24V-36V).
3.  **Firmware Upload:** Upload `HoverboardMotorTest.ino` to the board.
4.  **Observation:** The system will automatically cycle through: **Ramp Up (Forward) → Hold → Stop → Ramp Up (Reverse) → Stop.**

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering student, specializing in Power Electronics and Electric Vehicle Systems.*