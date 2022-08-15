# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.2.0] - 2022-08-15

- Change interface for `sensirion_uart_hal_init` in `sensirion_uart_hal` to allow passing
  the serial device to use. 

  New method declaration is `int16_t sensirion_uart_hal_init(char* device_descr);`

  In your script call it e.g. with `sensirion_uart_hal_init("/dev/ttyUSB0");`

- Updating instructions in README to connect sensor over UART Pins

[0.2.0]: https://github.com/Sensirion/raspberry-pi-uart-svm41/releases/tag/0.2.0

## [0.1.0] - 2021-11-17

Initial release

[0.1.0]: https://github.com/Sensirion/raspberry-pi-uart-svm41/releases/tag/0.1.0

