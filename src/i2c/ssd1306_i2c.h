/*
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
*/
/**
 * @file ssd1306_i2c.h SSD1306 i2c communication functions
 */


#ifndef _SSD1306_I2C_H_
#define _SSD1306_I2C_H_

#include "ssd1306_i2c_conf.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup LCD_INTERFACE_API LCD communication interface functions
 * @{
 */

/**
 * Inits display interface to use i2c bus.
 * The function automatically selects available type of i2c implementation
 * 1. Wire library
 * 2. sw i2c implementation
 * In case of using Wire library this function calls Wire.begin() and
 * sets speed to fast i2c (400kHz). If you prefer to use your own Wire settings
 * or avoid reinitializing of Wire library, please use ssd1306_i2cInit_Wire().
 * If you want to use embedded i2c (if it is supported), use ssd1306_i2cInit_Embedded().
 */
void         ssd1306_i2cInit();

/**
 * Inits display interface to use i2c bus.
 * The function automatically selects available type of i2c implementation
 * 1. Wire library
 * 2. sw i2c implementation
 * In case of using Wire library this function calls Wire.begin() and
 * sets speed to fast i2c (400kHz). If you prefer to use your own Wire settings
 * or avoid reinitializing of Wire library, please use ssd1306_i2cInit_Wire().
 * If you want to use embedded i2c (if it is supported), use ssd1306_i2cInit_Embedded().
 *
 * @param scl - i2c clock pin. Use -1 if you don't need to change default pin number
 * @param sda - i2c data pin. Use -1 if you don't need to change default pin number
 * @param sa  - i2c address of lcd display. Use 0 to leave default
 *
 * @note scl and sda parameters depend on used hardware. For many hardware boards these
 * parameters do not have any effect. ESP8266 allows to specify these parameters
 */
void ssd1306_i2cInitEx(int8_t scl, int8_t sda, int8_t sa);

/**
 * Switches i2c chip to command transmission mode.
 */
void         ssd1306_i2cCommandStart();

/**
 * Switches i2c chip to data transmission mode.
 */
void         ssd1306_i2cDataStart();

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
#endif // _SSD1306_I2C_H_
