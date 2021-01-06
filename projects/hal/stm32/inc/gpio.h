/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Anh Vo Tuan <votuananhs@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include "driver.h"
#include "hw_platform.h"

/* GPIO mode option */
#define GPIO_MODE_OPTION_INPUT             (0 << 0)
#define GPIO_MODE_OPTION_OUTPUT            (1 << 0)
#define GPIO_MODE_OPTION_ALT               (2 << 0)
#define GPIO_MODE_OPTION_ANALOG            (3 << 0)

#define GPIO_MODE_OPTION_PULLUP            (1 << 2)
#define GPIO_MODE_OPTION_PULLDOWN          (2 << 2)

#define GPIO_MODE_OPTION_AF0               ((AF0) << 4)
#define GPIO_MODE_OPTION_AF1               ((AF1) << 4)
#define GPIO_MODE_OPTION_AF2               ((AF2) << 4)
#define GPIO_MODE_OPTION_AF3               ((AF3) << 4)
#define GPIO_MODE_OPTION_AF4               ((AF4) << 4)
#define GPIO_MODE_OPTION_AF5               ((AF5) << 4)
#define GPIO_MODE_OPTION_AF6               ((AF6) << 4)
#define GPIO_MODE_OPTION_AF7               ((AF7) << 4)

typedef struct
{
    const uint8_t port;
    const uint8_t pin;
    const uint32_t mode_option;
} gpio_pin_t;

extern status_driver_t set_mode_pin(uint8_t port, uint8_t pin, uint32_t mode_option);
extern status_driver_t write_pin(uint8_t port, uint8_t pin, uint8_t value);
extern uint8_t read_pin(uint8_t port, uint8_t pin);
extern uint8_t toggle_pin(uint8_t port, uint8_t pin);
extern status_driver_t init_pin(const gpio_pin_t *list_pins, const uint8_t num_pin);

/* end file */
#endif /* __GPIO_H__ */
