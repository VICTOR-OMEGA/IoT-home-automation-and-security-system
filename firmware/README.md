# Firmware - IoT Home Automation and Security System

This folder contains the core firmware for the dual-microcontroller smart home automation and security system. 
It integrates a **local ESP32-based control dashboard** and a **secure Arduino Mega–based access control unit**, connected wirelessly via NRF24L01 modules.

---

## Files

- `central_control.ino` – Runs on the **ESP32**. Hosts the local web server, controls connected appliances, reads sensors, and communicates with the Mega.
- `access_control.ino` – Runs on the **Arduino Mega**. Handles RFID + keypad two-step access control and relays validated access attempts to the ESP32.

---

## Microcontroller Roles

### ESP32 – `central_control.ino`
- Hosts local web server (Wi-Fi AP or STA)
- Web login interface for secured access
- Controls:
  - Relays for lights, fans, appliances
- Reads sensors:
  - DHT11 (temperature & humidity)
  - Rain sensor
  - PIR sensor (for automated lighting)
  - Flame sensor (fire detection)
- Communicates with Mega via **nRF24L01**

### Arduino Mega – `access_control.ino`
- Handles two-factor access control:
  - **MFRC522 RFID reader**
  - **4x4 Matrix keypad** for PIN input
- Validates user identity
- Sends access decisions to ESP32 via **nRF24L01**
- Can trigger door lock relay or alert modules

---

## Dependencies

### ESP32
- `WiFi.h`, `WebServer.h`
- `DHT.h` (for DHT11)
- `RF24.h` (nRF24L01 communication)
- `ArduinoJson.h` (optional)

### Arduino Mega
- `RFID.h` (MFRC522)
- `Keypad.h`
- `RF24.h` (nRF24L01 communication)

---

## Communication Protocol

- Wireless: **nRF24L01 modules** (both ends)
- Message format (example):  
  - From Mega to ESP32: `"ACCESS:GRANTED"` or `"ACCESS:DENIED"`
  - From ESP32 to Mega: control/response instructions (if needed)

---

## System Highlights

- Fully **offline** operation (local network only)
- Modular and scalable: sensors, access units, and relays can be expanded
- Environmental monitoring + appliance automation + secure entry
- Customizable web interface hosted on ESP32

---

## Optimized Version

- Added SD logging for access events and sensor data
- Mobile-friendly UI styling
- Added web-based user management (RFID/PIN registration)
---
