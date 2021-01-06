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
#include "board.h"
#include "driver.h"


void led_on(uint8_t led_id)
{
    if (LD3 == led_id)
    {
        write_pin(LD3_PORT, LD3_PIN, HIGH);
        #if defined(HAL_UART_ENABLED)
        usart_send_string("\n\r--> Turn on LED3 successfully");
        #endif
    }
    else if (LD4 == led_id)
    {
        write_pin(LD4_PORT, LD4_PIN, HIGH);
        #if defined(HAL_UART_ENABLED)
        usart_send_string("\n\r--> Turn on LED4 successfully");
        #endif
    }
    else
    {
        #if defined(HAL_UART_ENABLED)
        usart_send_string("\n\r--> Don't support the led_id");
        #endif
    }
}

void led_off(uint8_t led_id)
{
    if (LD3 == led_id)
    {
        write_pin(LD3_PORT, LD3_PIN, LOW);
        #if defined(HAL_UART_ENABLED)
        usart_send_string("\n\r--> Turn off LED3 successfully");
        #endif
    }
    else if (LD4 == led_id)
    {
        write_pin(LD4_PORT, LD4_PIN, LOW);
        #if defined(HAL_UART_ENABLED)
        usart_send_string("\n\r--> Turn off LED4 successfully");
        #endif
    }
    else
    {
        #if defined(HAL_UART_ENABLED)
        usart_send_string("\n\r--> Don't support the led_id");
        #endif
    }
}

void led_func(uint8_t argc, uint8_t **argv)
{
    uint8_t temp = argv[1][0] - '0';

    if(!strcmp("on", argv[0]))
    {
        led_on(temp);
    }
    else if(!strcmp("off", argv[0]))
    {
        led_off(temp);
    }
    else
    {
        /* nothing to be run here */
        /* printf("\n\rDon't support the input parameter !"); */
    }
}

void test_func(uint8_t argc, uint8_t **argv)
{
	#if defined(HAL_UART_ENABLED)
    usart_send_string("\n\rCall test_func");
	#endif
}


