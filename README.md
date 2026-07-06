# Button-to-LED Mapper using 8051

## Overview

This project implements a Button-to-LED Mapper using the 8051 microcontroller (STC89C52RC) in Embedded C.
Instead of using multiple hardcoded conditional statements, the project maps button inputs to LED pattern functions using structures and function pointers. This demonstrates a scalable firmware architecture commonly used in embedded systems.

## Features

- GPIO Input and Output
- Software Debouncing
- Modular firmware design
- Structures and Function Pointers
- Mapping Table
- Easily extendable architecture

- ## Hardware Used
- STC89C52RC (8051 Microcontroller)
- 8051 Development Board
- 8 LEDs and 3 Push Buttons
- Jumper Wires
- USB Programmer
  
## Software Used
- Keil uVision
- Embedded C

## Working Principle

Each push button is associated with an LED pattern using a mapping table. The firmware continuously scans all configured buttons. When a valid button press is detected:
1. Button press is debounced.
2. The corresponding mapping entry is identified.
3. The associated function pointer is executed.
4. The selected LED pattern is displayed.
5. The firmware waits until the button is released.

## Challenges Faced
- Hardware issue with one push button requiring debugging and isolation.
- Understanding function pointers and mapping-based firmware architecture.
- Implementing generic button handling using structures.

## Learning Outcomes
This project helped reinforce the following embedded systems concepts:
- GPIO Programming
- Bit Manipulation
- Software Debouncing
- Modular Programming
- Structures
- Function Pointers
- Mapping Tables
- Embedded Firmware Design
- Hardware Debugging

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
