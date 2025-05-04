# 🚗 STM32-Based Car Parking System

## 📌 Project Overview

This project simulates a smart car parking system using an STM32 development board Nucleo 64.It utilizes sensors, LEDs, and 7-segment displays to monitor and indicate the availability of parking spaces.

---
> ![image](https://github.com/user-attachments/assets/71671126-50f5-49a3-902b-f93d9fc84a62)

## 🔧 System Features

- **Total Parking Spaces:** 200
- **Inputs:**
  - `ENTRY` sensor – triggers when a car enters
  - `EXIT` sensor – triggers when a car exits
- **Outputs:**
  - **Three 7-Segment Displays** – show current available parking spaces
  - **Green LED** – lights up for 1s when a car enters
  - **Red LED** – lights up for 1s when a car exits

---

## 🛠️ System Behavior

- On startup:
  - Displays a custom startup message (e.g., "G01") on the 7-segment displays for 4 seconds
- When a car enters (`ENTRY` sensor goes LOW):
  - Available space decreases by 1
  - Green LED lights up for 1 second
- When a car exits (`EXIT` sensor goes LOW):
  - Available space increases by 1
  - Red LED lights up for 1 second
- If no spaces are left (count = 0):
  - The 7-segment displays show the characters `"F"`, `"U"`, `"L"`, `"L"` in sequence with 500ms delay

---

## 🧪 Tools & Components Used

-  STM32F411RET6 board.
- 4 x 7-Segment Displays
- 2 x LEDs (Green & Red)
- 2 x Infrared Sensors 
- Resistors, jumper wires, breadboard

---

## 🖥️ Simulation Using Proteus

In the simulation version of the system, **push buttons were used instead of physical sensors** to simulate car entry and exit events. Each push button is connected to a digital input pin of the STM32, mimicking the behavior of IR sensors or gate switches.

- **Entry Button:** Simulates a car entering the parking lot.
- **Exit Button:** Simulates a car exiting the parking lot.
- When the button is pressed (logic LOW), the system reacts just as it would to a real sensor:
  - Updates available spaces
  - Activates the corresponding LED
  - Updates the 7-segment displays
- This simulation allows easy debugging and visualization of the logic without requiring full hardware setup.

> Proteus configuration screenshots or files are included in the `diagram/` folder.


---

## 📽️ Demo Video

The demonstration video showcases:

- Entry and exit simulation using sensors
- 7-segment updates and LED indication
- FULL condition display when parking is unavailable

🎥 **[Watch Demo Video](https://drive.google.com/file/d/1m9mqUlmmuRYD6eMm1ERSVUqHrxCAi9Tw/view?usp=sharing)**  

---



