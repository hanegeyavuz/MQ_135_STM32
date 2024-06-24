# MQ135 Sensor Integration with STM32

This project demonstrates the integration of an MQ135 gas sensor with an STM32 microcontroller. The setup reads gas concentration levels and transmits the data via UART. It also includes real-time clock (RTC) functionality and toggles an LED at a regular interval.

## Table of Contents
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup and Configuration](#setup-and-configuration)
- [How to Use](#how-to-use)
- [Contributing](#Contributing)
- [License](#license)
- [Authors](#Authors)

## Features
- Reads gas concentration using the MQ135 sensor.
- Transmits sensor data over UART.
- Retrieves and displays real-time clock (RTC) data.
- Toggles an LED every 100 ms for status indication.

## Hardware Requirements
- STM32 microcontroller (e.g., STM32F4 series)
- MQ135 gas sensor
- UART interface for data transmission
- RTC module (if not integrated in the MCU)
- LED and resistor for status indication

## Software Requirements
- STM32CubeIDE or any suitable IDE for STM32 development
- STM32CubeMX for generating initialization code
- HAL (Hardware Abstraction Layer) library

## Setup and Configuration
1. **Hardware Setup:**
   - Connect the MQ135 sensor to the ADC pin of the STM32.
   - Connect the UART TX and RX pins to a serial communication module.
   - Connect an LED with a resistor to a GPIO pin for status indication.
   - Ensure the RTC module is connected properly if not integrated.

2. **Software Configuration:**
   - Use STM32CubeMX to configure the peripherals: ADC, UART, GPIO, and RTC.
   - Generate the initialization code and import it into your STM32CubeIDE project.


## How-To-Use
- **Build the Project**
    - Open the project in STM32CubeIDE, build, and upload it to your STM32 microcontroller.
- **Monitor Output**
    - Use a serial terminal (e.g., PuTTY) to monitor the UART output. The sensor data and RTC time/date will be transmitted periodically.
- **Adjust Transmission Interval**
    - Send a string in the format `$<interval>\n` via UART to set the data transmission interval in milliseconds.
## Contributing
- Contributions are welcome! If you have any suggestions or find any bugs, please open an Issue or submit a Pull Request.
## License
This project is licensed under the GPL License - see the `LICENSE` file for details.
## Authors
- Muhammed Yavuz Hanege

