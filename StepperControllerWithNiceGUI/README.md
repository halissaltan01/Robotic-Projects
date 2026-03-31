# IoT-Based Stepper Motor Control via Python NiceGUI & Serial Communication 🤖🌐

[![Language: Python](https://img.shields.io/badge/Language-Python-blue.svg)](https://www.python.org/)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-orange.svg)](https://www.arduino.cc/)
[![Framework: NiceGUI](https://img.shields.io/badge/Framework-NiceGUI-green.svg)](https://nicegui.io/)

## 📌 Project Overview
This project implements a **cross-platform Human-Machine Interface (HMI)** to manage a 28BYJ-48 stepper motor's motion profile. By bridging **Python's NiceGUI framework** with **Arduino's AccelStepper library**, the system enables real-time, bi-directional motor control and telemetry data visualization through a web-based dashboard.

It demonstrates a robust implementation of **Asynchronous Serial Communication** between high-level software (Python) and low-level embedded hardware (C++/Arduino).

## 🚀 Key Features
* **Web-Based HMI:** Responsive Graphical User Interface for real-time motor actuation (Forward, Backward, Emergency Stop).
* **Bi-directional Telemetry:** Continuous feedback loop reflecting the motor's real-time step count and position on the web dashboard.
* **Non-Blocking Execution:** Utilizes the `AccelStepper` library to ensure smooth motor movement without interrupting serial data processing or UI responsiveness.
* **Full-Stack Hardware Control:** Integrated Python `pyserial` for reliable data packet exchange over USB/Serial.

## 🛠️ Technical Stack
* **High-Level:** Python 3.x, NiceGUI (Web Framework), PySerial.
* **Embedded:** C++, Arduino IDE, AccelStepper Library.
* **Hardware:** Arduino Uno/Nano, 28BYJ-48 Stepper Motor, ULN2003 Driver Module.

## 🔌 System Architecture (Pin Map)
| Component | Arduino Pin | Driver Input | Function |
| :--- | :--- | :--- | :--- |
| **Stepper Motor** | 8 | IN1 | Phase A |
| **Stepper Motor** | 9 | IN2 | Phase B |
| **Stepper Motor** | 10 | IN3 | Phase C |
| **Stepper Motor** | 11 | IN4 | Phase D |

## ⚙️ Engineering Principles Applied
* **Serial Protocol Design:** Implementing a command-response pattern for robust motor state management.
* **Asynchronous UI Updates:** Managing GUI state transitions without blocking the main control loop.
* **Motion Profiling:** Utilizing acceleration and speed curves for mechanical longevity and motion precision.

## 📂 Installation & Deployment
1.  **Hardware Setup:** Connect the motor and ULN2003 driver according to the pin map above.
2.  **Firmware:** Upload `StepperMotorNiceGUI.ino` to your Arduino board.
3.  **Environment Setup:** ```bash
    pip install nicegui pyserial
    ```
4.  **Configuration:** Update the `port` variable in the Python script (e.g., `COM3` for Windows or `/dev/ttyUSB0` for Linux).
5.  **Execution:** ```bash
    python StepperMotorNiceGUI.py
    ```

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering student focusing on Robotics and System Integration.*