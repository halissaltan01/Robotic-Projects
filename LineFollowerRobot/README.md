# Autonomous 5-Channel Line-Tracking Robot with Differential Drive 🏎️🤖

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-orange.svg)](https://www.arduino.cc/)

## 📌 Project Overview
This project features an autonomous mobile robot engineered for high-precision line navigation. Utilizing a **5-channel Infrared (IR) sensor array**, the robot implements a sophisticated decision-making algorithm to manage differential steering and speed control. The system is designed to handle complex track geometries, including sharp turns and intersections, by processing real-time spatial feedback.

## 🚀 Key Technical Features
* **High-Fidelity Tracking:** Employs 5 x TCRT5000 IR sensors to provide a high-resolution "digital image" of the track, enabling smoother transitions compared to standard 2 or 3-channel systems.
* **Differential Steering Logic:** Implements precise motor control via the **L298N H-Bridge Driver**, managing dual brushed DC motors for agile maneuvering.
* **Dynamic Speed Modulation:** Features **PWM (Pulse Width Modulation)** based speed control to optimize torque during sharp turns and maximize velocity on straight paths.
* **Fail-Safe Protocol:** Integrated "End-of-Track" detection that automatically halts the motors when no reference line is identified, ensuring mechanical safety.

## 🛠️ Hardware Architecture
* **Microcontroller:** ATmega328P (Arduino Family)
* **Sensing Array:** 5-Channel TCRT5000 Infrared Reflectance Sensors
* **Motor Driver:** L298N Dual H-Bridge Module
* **Actuators:** 2 x High-Torque Brushed DC Motors
* **Power Management:** Integrated battery solution for mobile operation.

## 🔌 System Pin Map
| Arduino Pin | Functional Unit | Description |
| :--- | :--- | :--- |
| **9 / 10** | **PWM Control** | Motor A & B Velocity (ENA / ENB) |
| **7 / 8** | **Motor A Logic** | Direction Control (IN1 / IN2) |
| **5 / 6** | **Motor B Logic** | Direction Control (IN3 / IN4) |
| **12, 11, 4, 13, 2** | **Sensor Array (S1-S5)** | IR Digital Signal Inputs |

## ⚙️ Engineering Principles Applied
* **Logic State Programming:** Developing a truth-table-based algorithm to interpret sensor array data for directional decision-making.
* **Motion Control:** Applying PWM techniques to manage inertia and motor response times.
* **Sensor Fusion (Basic):** Aggregating data from multiple infrared inputs to determine the robot's relative position to the center of the track.

## 📂 Installation & Deployment
1.  **Hardware Assembly:** Connect the IR array and L298N module according to the Pin Map above.
2.  **Firmware Upload:** Open `LineFollower.ino` in the Arduino IDE and upload it to the board.
3.  **Calibration:** Place the robot on a high-contrast (Black/White) track. The 5-channel logic will handle standard width lines autonomously.

---
*Developed by **Halis Saltan** - Electrical & Electronics Engineering student, focusing on Autonomous Systems and Robotics.*