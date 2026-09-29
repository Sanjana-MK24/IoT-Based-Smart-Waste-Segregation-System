# ♻️ Smart Waste Segregation System

An IoT-based smart waste segregation system that automatically detects waste, identifies it as wet or dry using a moisture sensor, and directs it into the appropriate compartment using a servo motor.

## 📌 Project Overview

Manual waste segregation can be time-consuming and unhygienic. This project provides a simple automated solution using an Arduino UNO, ultrasonic sensor, soil moisture sensor, and servo motor.

The system detects when waste is placed near the bin, checks its moisture level, and rotates the servo to direct the waste toward the corresponding compartment.

## 🎯 Objectives

* ♻️ Automatically detect waste
* 💧 Identify wet and dry waste
* ⚙️ Automatically direct waste into the correct compartment
* 🚮 Reduce manual waste segregation
* 💡 Develop a low-cost IoT-based prototype

## 🔄 Working Principle

```text
Waste Placed
     ↓
HC-SR04 Detects Waste
     ↓
Distance < 15 cm
     ↓
Moisture Sensor Reads Waste
     ↓
 ┌───────────────┐
 │ Moisture Value│
 └───────┬───────┘
         ↓
   ┌─────┴─────┐
   ↓           ↓
 Wet Waste   Dry Waste
   ↓           ↓
Servo 45°    Servo 135°
   ↓           ↓
   └─────┬─────┘
         ↓
   Servo Returns
      to 90°
```

## 🧰 Components Used

* Arduino UNO
* HC-SR04 Ultrasonic Sensor
* Soil Moisture Sensor
* SG90 Servo Motor
* Jumper Wires
* Breadboard
* USB Cable
* Waste Segregation Container

## 🔌 Pin Connections

| Component            | Arduino UNO Pin |
| -------------------- | --------------- |
| HC-SR04 Trig         | D8              |
| HC-SR04 Echo         | D9              |
| Soil Moisture Sensor | A0              |
| Servo Signal         | D6              |
| Sensor VCC           | 5V              |
| Sensor GND           | GND             |

## ⚙️ System Logic

The HC-SR04 ultrasonic sensor detects whether waste is present within 15 cm.

When waste is detected:

* The moisture sensor measures the waste.
* If the sensor value is below the configured threshold, the waste is classified as **wet**.
* The servo moves to **45°** for wet waste.
* Otherwise, the waste is classified as **dry**.
* The servo moves to **135°** for dry waste.
* After the waste falls into the corresponding compartment, the servo returns to **90°**.

## 💻 Technologies Used

* Arduino UNO
* Embedded C/C++
* Ultrasonic sensing
* Moisture sensing
* Servo motor control

## 📂 Project Structure

```text
Smart Waste Segregation/
│
├── smart_waste_segregation.ino
├── README.md
├── .gitignore
├── circuit_diagram.png
└── prototype.jpg
```

> `circuit_diagram.png` and `prototype.jpg` can be added after capturing the final circuit and prototype.

## 🚀 Future Scope

* Add more waste categories
* Add IoT connectivity for monitoring
* Add a mobile/web dashboard
* Add waste-level monitoring
* Add cloud-based analytics
* Improve waste classification using machine learning

## 👩‍💻 Project Author

**Sanjana M Kanaki**

B.Tech – IoT Specialization
GM University

---

⭐ This project demonstrates how IoT and embedded systems can be used to automate basic waste segregation.
