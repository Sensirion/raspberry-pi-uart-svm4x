# Sensirion Raspberry Pi UART SVM41 Driver

This document explains how to set up the [SEK-SVM41](https://www.sensirion.com/my-sgp-ek/) evaluation kit to run on a
Raspberry Pi using the provided code.

[<center><img src="images/SVM4x.png" width="500px"></center>](https://www.sensirion.com/my-sgp-ek/)

## Setup Guide

### Connecting the Sensor

Plug the provided USB cable into your Raspberry Pi.

If you don't have a suitable cable at hand, please find the SEK-SVM4x technical description [here](https://www.sensirion.com/my-sgp-ek):

| *Pin* | *Cable Color* | *Name* | *Description* | *Comments* |
|-------|---------------|--------|---------------|------------|
| 1     | Red           | VDD    | Supply Voltage | 3.3 or 5.0 V
| 2     | Black         | Ground |
| 3     | Green         | RX     | UART: Receiving pin for communication |
|       |               | SDA    | I2C: Serial data, bidirectional |
| 4     | Yellow        | TX     | UART: Transmission pin for communication |
|       |               | SCL    | I2C: Serial clock |
| 5     | Blue          | SEL    | Interface select | Leave floating or pull to VDD to select UART
|       |               |        |  | Pull to GND to select I2C
| 6     | Purple        | NC     | Do not connect |

### Raspberry Pi

- [Install the Raspberry Pi OS on to your Raspberry Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)
- Download the driver from the [Sensirion GitHub Page](https://github.com/Sensirion/raspberry-pi-uart-svm41/tags)
  and extract the `.zip` on your Raspberry Pi
- Compile the driver
    1. Open a [terminal](https://www.raspberrypi.org/documentation/usage/terminal/)
    2. Navigate to the driver directory. E.g. `cd ~/raspberry-pi-uart-svm41`
    3. Run the `make` command to compile the driver

       Output:
       ```
       rm -f svm41_uart_example_usage
       cc -Os -Wall -fstrict-aliasing -Wstrict-aliasing=1 -Wsign-conversion -fPIC -I. -o svm41_uart_example_usage svm41_uart.h svm41_uart.c sensirion_uart_hal.h sensirion_shdlc.h sensirion_shdlc.c \
        sensirion_uart_hal.c sensirion_config.h sensirion_common.h sensirion_common.c svm41_uart_example_usage.c
       ```

- Test your connected sensor
    - Run `./svm41_uart_example_usage` in the same directory you used to compile the driver.

      Output:
      ```
      Serial number: 0FA3F1F7000003392A3D0240
      Product type: 00141000
      Product name: SVM41
      Firmware: 3.0 Debug: 1
      Hardware: 3.0
      Protocol: 1.0
      Temperature Offset: 0.00 °C
      Humidity: 55.20 % RH
      Temperature: 25.82 °C
      VOC index: 0.0 VOC index
      NOx index: 0.0 NOx index
      Humidity: 55.20 % RH
      Temperature: 25.84 °C
      VOC index: 0.0 VOC index
      NOx index: 0.0 NOx index
      ...
      ```
    
