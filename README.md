# RFID-Based Access Control System

This project is an **RFID-based access control system** using Arduino. It uses an **MFRC522 RFID module**, **servo motor**, **LEDs**, and a **buzzer** to grant or deny access based on authorized RFID cards.

## Features

- **Authorized Access**: Detects authorized RFID cards and opens a door using a servo motor.
- **Access Denied Alert**: Displays a green LED and buzzer if an unauthorized card is scanned.
- **Real-time UID display**: Shows the UID of the scanned card in the Serial Monitor.
- Easy to modify to add multiple authorized cards.

## Components Used

- Arduino Uno (or any compatible board)
- MFRC522 RFID module
- Servo motor
- LEDs (Blue & Green)
- Buzzer
- Jumper wires & breadboard

## Circuit Diagram

- Connect **MFRC522** to SPI pins of Arduino.
- Servo connected to **pin 6**.
- LEDs and buzzer connected to **pins 3, 4, 5** respectively.

## Installation

1. Clone this repository:

```bash
git clone https://github.com/Vashitva1356/rfid-access-control.git
