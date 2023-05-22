# Arduino_alarmclock_withwaterfn
Arduino alarm clock which uses water to wake you up

# Arduino Alarm Clock with Water Fountain

This project combines an Arduino board, a real-time clock (RTC) module, and a water pump to create an alarm clock that activates a water fountain as an alarm.

## Table of Contents
1. [Overview](#overview)
2. [Prerequisites](#prerequisites)
3. [Hardware Requirements](#hardware-requirements)
4. [Software Requirements](#software-requirements)
5. [Installation and Setup](#installation-and-setup)
6. [Usage](#usage)
7. [Troubleshooting](#troubleshooting)
8. [Contributing](#contributing)
9. [License](#license)

## Overview
The Arduino Alarm Clock with Water Fountain is an open-source project that uses Arduino Uno or compatible boards, an RTC module (such as DS3231), and a water pump to create an alarm clock that incorporates a water fountain as an alarm mechanism. The system is controlled through a simple user interface, allowing users to set the alarm time and activate/deactivate the water fountain alarm.

## Prerequisites
Before setting up the Arduino Alarm Clock with Water Fountain, you should have the following knowledge and prerequisites:

- Basic understanding of Arduino programming.
- Familiarity with Arduino Uno or compatible boards.
- Knowledge of how to connect electronic components (e.g., wires, resistors) to an Arduino board.
- Basic understanding of the Arduino development environment (IDE).
- Understanding of how to upload code to an Arduino board.

## Hardware Requirements
To build the Arduino Alarm Clock with Water Fountain, you will need the following hardware components:

- Arduino Uno or compatible board
- DS3231 RTC module
- Water pump (compatible with Arduino)
- Transistor module or relay module (to control the water pump)
- Jumper wires
- Breadboard or PCB (Printed Circuit Board)
- Power supply for the water pump (based on the pump's specifications)
- USB cable for connecting the Arduino board to your computer

## Software Requirements
To program the Arduino board and upload the necessary code, you will need the following software:

- Arduino IDE (Integrated Development Environment): Download and install the latest version from the official Arduino website (https://www.arduino.cc/en/software).

## Installation and Setup
Follow these steps to set up the Arduino Alarm Clock with Water Fountain:

1. Connect the Arduino board to your computer using a USB cable.
2. Open the Arduino IDE on your computer.
3. Install the necessary libraries by navigating to **"Sketch" -> "Include Library" -> "Manage Libraries"** in the Arduino IDE. Search for and install the following libraries if not already present:
   - `DS3231` (RTC module library)
4. Clone or download the project repository from GitHub: [Arduino Alarm Clock with Water Fountain](https://github.com/Hariwo711/Arduino_alarmclock_withwaterfn.git).
5. Extract the downloaded repository files to a convenient location on your computer.
6. Open the Arduino sketch file (`config.ino`) from the extracted files in the Arduino IDE.
7. Connect the hardware components following the wiring diagram provided in the repository's **README.md** file.
8. Modify the code if necessary to match your specific pin connections or preferences (e.g., alarm sound, alarm duration).
9. Select the appropriate board from the **"Tools" -> "Board"** menu in the Arduino IDE (e.g., Arduino Uno).
10. Choose the correct port from the **"Tools" -> "Port"** menu in the Arduino IDE.
11. Click the **"Upload"** button in the Arduino IDE to compile and upload the code to the Arduino board.

## Usage
Once the Arduino Alarm Clock with Water Fountain is set up and the code is uploaded to the Arduino board, you can use the following instructions to use the alarm clock:

1. Set the alarm time using the provided user interface.
2. Activate the water fountain alarm by setting the corresponding option.
3. The alarm will trigger at the specified time, activating the water pump and creating a fountain effect.
4. To deactivate the alarm, you can either reset the Arduino board or turn off the water pump manually.

## Troubleshooting
If you encounter any issues while setting up or using the Arduino Alarm Clock with Water Fountain, consider the following troubleshooting steps:

- Double-check the wiring connections to ensure they are correct and secure.
- Verify that the required libraries are installed correctly in the Arduino IDE.
- Check the Arduino board's settings (board type, port) in the Arduino IDE.
- Review the code for any potential errors or inconsistencies.
- Consult the project's issue tracker on GitHub to see if others have experienced and solved similar problems.

## Contributing
Contributions to the Arduino Alarm Clock with Water Fountain project are welcome. If you find any bugs, have suggestions for improvements, or would like to add new features, please follow these steps:

1. Fork the project repository on GitHub.
2. Create a new branch for your contributions.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your forked repository.
5. Submit a pull request to the original repository, describing your changes in detail.

## License
The Arduino Alarm Clock with Water Fountain project is released under the [MIT License](LICENSE). Please review the license file for more information.

