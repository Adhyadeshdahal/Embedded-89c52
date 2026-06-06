# Embedded 89C52 Projects

Embedded 89C52 Projects is a collection of beginner-friendly embedded systems experiments built around the 8051/AT89C52 microcontroller family. The repository includes Keil C source code, generated HEX files, Proteus simulation projects, and supporting utilities for learning microcontroller I/O, seven-segment displays, LCD interfacing, UART serial communication, timers, and digital clock design.

## Project Description

This repository demonstrates core embedded programming concepts using the 89C52 microcontroller. Each folder contains a focused experiment, usually with C source code, a Keil project, a compiled HEX file, and a Proteus design that can be simulated without physical hardware. The projects are useful for students learning 8051 architecture, port control, display multiplexing, timer interrupts, serial communication, and peripheral interfacing.

## Features

- 8051/AT89C52 embedded C examples
- Keil uVision project files
- Proteus simulation circuits
- Precompiled HEX files for simulation
- Seven-segment display exercises
- LM016L LCD interfacing
- UART serial communication using polling and interrupts
- Timer-based digital clock implementation
- Timer helper utility for calculating delay register values

## Repository Structure

```text
Embedded-89c52/
|-- 2.1/                  # Single seven-segment digit counting example
|-- 2.2/                  # Two-digit seven-segment multiplexing
|-- 2.3/                  # Fibonacci sequence display on seven-segment display
|-- 2.4/                  # Multiplication table display
|-- 2.5/                  # Multi-digit seven-segment display exercise
|-- 2.6/                  # Multi-digit seven-segment display exercise
|-- Digital Clock/        # Timer interrupt based digital clock
|-- LM016 Interfacing/    # 16x2 LCD display interfacing
|-- Timer Helper/         # Utility for timer TH/TL calculation
|-- UART/                 # UART polling and interrupt examples
|-- Year/                 # Additional display simulation/project files
|-- Report.pdf            # Project/report document
`-- codes-2.txt           # Additional code notes
```

## Main Modules

### Seven-Segment Display Exercises

The folders `2.1` to `2.6` contain basic to intermediate seven-segment display programs. These examples cover digit encoding, port output, display enable pins, multiplexing, numeric sequences, Fibonacci numbers, multiplication tables, and multi-digit display logic.

### LM016 LCD Interfacing

The `LM016 Interfacing` folder demonstrates how to interface a 16x2 LCD with an 89C52 microcontroller. The code uses control pins for `RS`, `RW`, and `EN`, sends LCD commands, initializes the display, and writes text such as `Hello World`.

### UART Communication

The `UART` folder contains serial communication experiments. One example sends text through UART using polling, while another uses serial interrupts to receive characters, echo them back, and display them on an LCD.

### Digital Clock

The `Digital Clock` folder contains a timer-based clock project using multiplexed seven-segment displays. It uses timer interrupts to update seconds/minutes/hours and displays the time with AM/PM indication.

### Timer Helper

The `Timer Helper` folder includes a helper executable and source code for calculating timer register values based on delay time and microcontroller frequency.

## Tools Required

- Keil uVision for opening and compiling `.uvproj` projects
- Proteus Design Suite for running `.pdsprj` simulations
- 8051/AT89C52 compatible toolchain
- Basic understanding of embedded C and 8051 registers

## How to Run

1. Open the desired folder.
2. Open the `.pdsprj` file in Proteus to view or simulate the circuit.
3. Open the `.uvproj` file in Keil uVision if you want to edit or rebuild the source code.
4. Build the project in Keil to generate a `.hex` file.
5. In Proteus, assign the generated `.hex` file to the 89C52 microcontroller.
6. Run the simulation.

## Example Workflow

For the LCD project:

1. Open `LM016 Interfacing/LM016L_interfacing.pdsprj` in Proteus.
2. Open `LM016 Interfacing/test.uvproj` in Keil.
3. Build the Keil project to generate `test.hex`.
4. Load `test.hex` into the microcontroller component in Proteus.
5. Start the simulation and observe the LCD output.

## Learning Outcomes

By working through these examples, you can learn:

- How to control 8051 ports
- How seven-segment digit patterns work
- How display multiplexing is implemented
- How to interface a 16x2 LCD
- How UART serial transmission and reception work
- How timer interrupts are used in real-time embedded applications
- How to simulate embedded circuits in Proteus

## Suggested GitHub Description

```text
8051/AT89C52 embedded systems experiments with Keil C code, HEX files, and Proteus simulations for seven-segment displays, LCD interfacing, UART communication, timers, and a digital clock.
```

## Notes

- Many folders include generated build artifacts such as `.OBJ`, `.LST`, `.M51`, `.plg`, and `.hex` files.
- The `.hex` files can be loaded directly into Proteus simulations.
- If you modify source code, rebuild the corresponding Keil project and update the HEX file used by Proteus.

## Author

Adhyadesh Dahal
