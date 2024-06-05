# Solenoid Door Lock System
<img align="float:center" width="640" alt="Screenshot 2024-06-05 at 9 54 11 PM" src="https://github.com/CodeBeginner000001/Solenoid-Door-Lock-using-EM-18/assets/92913917/b5b814de-c009-4192-9bbd-34d57518d691">

## Table of Contents
1. [Introduction](#introduction)
2. [Components Required](#components-required)
3. [Components Overview](#components-overview)
   - [16x2 LCD Display](#16x2-lcd-display)
   - [LCD Display Module](#lcd-display-module)
   - [EM-18 RFID Reader Module](#em-18-rfid-reader-module)
   - [Solenoid Door Lock](#solenoid-door-lock)
4. [Setup and Usage](#setup-and-usage)
   - [Hardware Connections](#hardware-connections)
   - [Software Implementation](#software-implementation)
   - [Testing and Deployment](#testing-and-deployment)
5. [Conclusion](#conclusion)

## Introduction
This project involves creating a solenoid door lock system using an EM-18 RFID reader and a keypad. The system provides enhanced security and controlled access using RFID cards and a keypad.

## Components Required
1. **16x2 LCD Display**
2. **LCD Display Module**
3. **EM-18 RFID Reader Module**
4. **Solenoid Door Lock**
5. **Relay Module**
6. **Arduino Board**
7. **3x3 Keypad**

## Components Overview

### 16x2 LCD Display
<img align="float:center" width="640" src="https://github.com/CodeBeginner000001/Solenoid-Door-Lock-using-EM-18/assets/92913917/ead527c8-2ac8-48fb-a245-cc7164919d0c">

- **Description:** Displays up to 32 characters on two lines.
- **Operating Voltage:** 4.7V to 5.3V.
- **Pixel Resolution:** 5x8 per character.

### LCD Display Module
- **Description:** Detachable module for easy replacement.
- **Features:** Includes potentiometer for brightness control.

### EM-18 RFID Reader Module
- **Operating Frequency:** 125 KHz.
- **Interface:** UART communication with microcontrollers.

### Solenoid Door Lock
- **Description:** Electromechanical device controlling access through electromagnetism.

## Setup and Usage

### Hardware Connections
1. **LCD Display:** Connect the 16x2 LCD display to the Arduino, ensuring correct pin alignment.
2. **RFID Reader:** Interface the EM-18 RFID reader with the Arduino using UART pins.
3. **Solenoid Lock:** Connect the solenoid lock to a relay module which is controlled by the Arduino.
4. **Keypad:** Attach the 3x3 keypad to the Arduino for input.

### Software Implementation
1. **Arduino Code:** Write the code to manage RFID reading and keypad input.
2. **Control Logic:** Program the Arduino to control the solenoid lock based on authorized RFID tags and keypad codes.

### Testing and Deployment
1. **System Testing:** Test the system by scanning RFID tags and entering keypad codes.
2. **Deployment:** Deploy the system for controlled access to secure areas.

## Conclusion
This project provides a secure and efficient way to control access using a combination of RFID and keypad authentication.

---

For detailed code and schematic diagrams, please refer to the repository files.
