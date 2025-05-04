# 🚗 STM32-Based Car Parking System

## 📌 Project Overview

This project simulates a smart car parking system using an STM32 development board Nucleo 64.It utilizes sensors, LEDs, and 7-segment displays to monitor and indicate the availability of parking spaces.

---

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


