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
#ifndef __BOARD_H__
#define __BOARD_H__


#include "type.h"
#include "hw_platform.h"



/* Led LD3 - PC9 */
#define LD3                     0
#define LD3_PORT                PORT_C
#define LD3_PIN                 9
/* Led LD4 - PC8 */
#define LD4                     1
#define LD4_PORT                PORT_C
#define LD4_PIN                 8

/* user button (B1) - PA0 */
#define USER_BUTTON             0

extern void led_on(uint8_t led_id);
extern void led_off(uint8_t led_id);
extern void led_func(uint8_t argc, uint8_t **argv);
extern void test_func(uint8_t argc, uint8_t **argv);


#endif /* __BOARD_H__ */

