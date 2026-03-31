# Automated Elevator Control System with Ultrasonic Feedback 🏗️

This repository contains the firmware and documentation for an automated vertical motion control system. The project utilizes an ultrasonic sensor to provide real-time distance feedback, allowing the controller to manage elevator levels and safety boundaries autonomously.

---

## 🚀 Project Overview
The system is designed to simulate a smart elevator that monitors its position relative to the floor or ceiling. It uses a **threshold-based logic** (Guard Bands) to decide whether to move up, move down, or stop, ensuring a safe operational range between **5cm and 45cm**.

Unlike basic "if-equal" logic, this system is engineered to handle sensor noise and mechanical jitter, making it robust for real-world prototyping.

## 🛠️ Key Features
* **Dynamic Motion Control:** Automated direction switching based on real-time distance telemetry.
* **Precision Sensing:** High-frequency distance measurement using the **HC-SR04** ultrasonic sensor.
* **H-Bridge Actuation:** Direction and speed (**PWM**) control via the **L298N** motor driver.
* **Fail-Safe Logic:** Implementation of safety thresholds to prevent mechanical collisions and handle signal instability.
* **Serial Telemetry:** Real-time data streaming for system monitoring and debugging.

## 🧱 Hardware Stack
* **Microcontroller:** Arduino Uno / Mega
* **Sensors:** HC-SR04 Ultrasonic Distance Sensor
* **Motor Driver:** L298N Dual H-Bridge
* **Actuators:** DC Gear Motors
* **Power Supply:** 9V-12V DC External Input

## 💻 Technical Skills Applied
* **Embedded C++:** Developing non-blocking control loops and sensor-actuator synchronization.
* **Control Theory:** Implementing state-based decisions for mechanical safety and level management.
* **Hardware Interfacing:** PWM signal generation, GPIO management, and H-Bridge logic.
* **Signal Processing:** Calculating distance from pulse-width timing and filtering outliers.

## 📂 Installation & Usage
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/halissaltan01/Automated-Elevator-System.git](https://github.com/halissaltan01/Automated-Elevator-System.git)
    ```
2.  Open the `.ino` file in the **Arduino IDE**.
3.  Wire the components according to the pin definitions in the source code.
4.  Upload the code and open the **Serial Monitor** (9600 baud) to track real-time distance data.

---
*Developed by **Halis Saltan** as part of an iterative engineering series focused on industrial automation and control systems.*