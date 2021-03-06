# SSD1306/SSD1331/SSD1351/IL9163/ST7735 OLED display driver, PCD8544 LED display driver

[tocstart]: # (toc start)

  * [Introduction](#introduction)
  * [Key Features](#key-features)
  * [Supported displays](#supported-displays)
  * [Supported platforms](#supported-platforms)
  * [Setting up](#setting-up)
  * [License](#license)

[tocend]: # (toc end)


## Introduction

SSD1306 driver is Arduino style C/C++ library with unicode support. The library can be compiled for plain Linux
(for example, raspberry spi), or you can use it with plain avr-gcc compiler without Arduino IDE. It supports
monochrome and RGB oleds and has debug mode, allowing to execute code on PC, using SDL2.0.
Initially the library is intended for very small microcontrollers (with a little of RAM). It was developed to use as
few resources as possible, but still has powerful capabilities (NanoEngine), allowing to develop nice animation.
It works on any powerful devices like raspberry pi, esp32; and can be easily ported to new platform.

## Key Features

 * Supports color, monochrome OLED displays, and VGA monitor
 * The library has modular structure, and some modules can be excluded from compilation at all to reduce flash usage.
 * Needs very little RAM (Attiny85 with Damellis package needs minimum 25 bytes of RAM to communicate with OLED)
 * Fast implementation to provide reasonable speed on slow microcontrollers
 * Supports i2c and spi interfaces:
   * i2c (software implementation, Wire library, AVR Twi, Linux i2c-dev)
   * spi (4-wire spi via Arduino SPI library, AVR Spi, AVR USI module)
 * Primitive graphics functions (lines, rectangles, pixels, bitmaps)
 * Printing text to display (using fonts of different size, you can use GLCD Font Creator to create new fonts)
 * Includes [graphics engine](https://github.com/lexus2k/ssd1306/wiki/Using-NanoEngine-for-systems-with-low-resources) to support
   double buffering on tiny microcontrollers.
 * Can be used for game development (bonus examples):
   * Arkanoid game ([arkanoid](examples/games/arkanoid) in old style API and [arkanoid8](examples/games/arkanoid8) in new style API)
   * Simple [Lode runner](examples/games/lode_runner) game.
   * [Snowflakes](examples/nano_engine/snowflakes)

![Image of arkanoid intro](imgs/arkanoid.png)
![Image of lode runner](imgs/lode_runner.gif)

![Image of menu example](imgs/mainmenu_top.png)
![Image of color oled](imgs/fonts.png)

The i2c pins can be changed via API functions. Please, refer to documentation. Keep in mind,
that the pins, which are allowed for i2c or spi interface, depend on the hardware.
The default spi SCLK and MOSI pins are defined by SPI library, and DC, RST, CES pins are configurable
through API.

## Supported displays:

| **Display** | **I2C** | **SPI** | **Orientation** | **Comments** |
| :-------- |:---:|:---:|:---:|:---------|
| sh1106 128x64 | X |   |   |   |
| ssd1306 128x64 | X | X |   |   |
| ssd1306 128x32 | X | X |   |   |
| ssd1331 96x64 |   | X | X |   |
| ssd1351 128x128 |   | X |   |   |
| il9163 128x128 |   | X | X |   |
| st7735 128x160 |   | X | X |   |
| pcd8544 84x48 |   | X  |   | Nokia 5110 |
| vga 96x40 color |   |   |   | direct D-sub output, atmega328p only |
| vga 128x64 bw |   |   |   | direct D-sub output, atmega328p only |

## Supported platforms

| **Platforms** | **I2C** | **SPI** | **Comments** |
| :-------- |:---:|:---:|:---------|
| **Arduino** |     |     |          |
| Attiny85, Attiny45  |  X  |  X  | Refer to [Damellis attiny package](https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json) |
| Attiny84, Attiny44  |  X  |  X  | Refer to [Damellis attiny package](https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json) |
| Atmega328p, Atmega168  |  X  |  X  |    |
| Atmega32u4  |  X  |  X  |    |
| Atmega2560  |  X  |  X  |    |
| Digispark, including PRO version  |  X  |  X  |  check [examples compatibility list](examples/Digispark_compatibility.txt)  |
| ESP8266  |  X  |  X  | check [examples compatibility list](examples/ESP8266_compatibility.txt)   |
| ESP32  |  X  |  X  | check [examples compatibility list](examples/ESP8266_compatibility.txt)   |
| STM32  |  X  |  X  | [stm32duino](https://github.com/stm32duino/wiki/wiki)  |
| Arduino Zero | X  | X  |    |
| Nordic nRF5 (nRF51, nRF52) | X | X | nRF users, enable c++11 in platform.txt `-std=gnu++11`   |
| **Plain AVR** |   |     |          |
| Attiny85, Attiny45 |  X  |  X  |         |
| Atmega328p, Atmega168 |  X  |  X  |         |
| Atmega32u4  |  X  |  X  |    |
| **Plain ESP32** |   |     |          |
| ESP32 |  X  | X  |  library can be used as IDF component  |
| **Linux**  |    |     |          |
| Raspberry Pi |  X  |  X  | i2c-dev, spidev, sys/class/gpio  |
| [SDL Emulation](https://github.com/lexus2k/ssd1306/wiki/How-to-run-emulator-mode) |  X  |  X  | demo code can be run without real OLED HW via SDL library |
| **Windows**  |    |     |          |
| [SDL Emulation](https://github.com/lexus2k/ssd1306/wiki/How-to-run-emulator-mode) |  X  |  X  | demo code can be run without real OLED HW via MinGW32 + SDL library |

Digispark users, please check compilation options in your Arduino prior to using this library.
Ssd1306 library requires at least c++11 and c99 (by default Digispark package misses the options
-std=gnu11, -std=gnu++11).

## The goals of ssd1306 library

 * To use as few RAM as possible
 * To use as few Flash as possible
 * To be as fast as possible
 * To fit [Arkanoid game example](examples/games/arkanoid) to Attiny85 microcontroller

## Setting up

*Hardware setup is described [here](https://github.com/lexus2k/ssd1306/wiki/Hardware-setup)

*Setting up for Arduino: (variant 1)*
 * Download source from https://github.com/lexus2k/ssd1306
 * Put the sources to Arduino/libraries/ folder

*Setting up for Arduino: (variant 2)*
 * Install ssd1306 library via Arduino IDE library manager

*Using with plain avr-gcc:*
 * Download source from https://github.com/lexus2k/ssd1306
 * Build the library (variant 1)
   * cd ssd1306/src && make -f Makefile.avr MCU=<your_mcu>
   * Link library to your project (refer to [Makefile.avr](examples/Makefile.avr) in examples folder).
 * Build demo code (variant 2)
   * cd ssd1306/tools && ./build_and_run.sh -p avr -m <your_mcu> ssd1306_demo

For more information about this library, please, visit https://github.com/lexus2k/ssd1306.
Doxygen documentation can be found at [github.io site](http://lexus2k.github.io/ssd1306).
If you found any problem or have any idea, please, report to Issues section.

## License

The library is free. If this project helps you, you can give me a cup of coffee.
[![Donate via Paypal](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/lexus2k)


MIT License

Copyright (c) 2016-2018, Alexey Dynda

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


