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
#include "usart.h"

#if defined(HAL_UART_ENABLED)

void usart_init(void)
{
    unsigned int temp_reg;

    /* disable usart1 */
    write_reg(USART_CR1, 0x00000000);

    /* length data: 8 bits */
    temp_reg = read_reg(USART_CR1, ~((1<<28)||(1<<12)));
    temp_reg |= (0<<28)||(0<<12);
    write_reg(USART_CR1, temp_reg);

    /* parity : none */
    temp_reg = read_reg(USART_CR1, ~(1<<10));
    temp_reg |= (0<<10);
    write_reg(USART_CR1, temp_reg);

    /* stop bit - 1 bit */
    temp_reg = read_reg(USART_CR2, ~(0x3<<12));
    temp_reg |= (0<<12);
    write_reg(USART_CR2, temp_reg);

    /* oversampling: 16 bits */
    temp_reg = read_reg(USART_CR1, ~(1<<15));
    temp_reg |= (0<<15);
    write_reg(USART_CR1, temp_reg);

    /* baudrate = 9600 bps; fCK = 48 MHz */
    /* write_reg(USART_BRR, 0x1388); */
    /* baudrate = 115200 bps; fCK = 48 MHz */
    write_reg(USART_BRR, 0x1A1);

    /* enable usart1 */
    temp_reg = read_reg(USART_CR1, ~(1<<0));
    temp_reg |= (1<<0);
    write_reg(USART_CR1, temp_reg);

    /* Tx Enable */
    temp_reg = read_reg(USART_CR1, ~(1<<3));
    temp_reg |= (1<<3);
    write_reg(USART_CR1, temp_reg);

    /* Rx Enable */
    temp_reg = read_reg(USART_CR1, ~(1<<2));
    temp_reg |= (1<<2);
    write_reg(USART_CR1, temp_reg);

}


char usart_send_byte(unsigned char data_input)
{
    unsigned int temp_reg;
    char state = 0;

    /* kiểm tra xem TDR sẵn sàng nhận dữ liệu mới chưa */
    temp_reg = read_reg(USART_ISR, (1<<7));
    if (0 != temp_reg)
    {
        write_reg(USART_TDR, (unsigned int)data_input);
    }
    else
    {
        state = -1;
    }
    return state;
}

char usart_send_string(unsigned char *str_data)
{
    char state = 0;
    while(*str_data)
    {
        if (0 == usart_send_byte(*str_data))
        {
            str_data++;
        }
    }
    return state;
}


#endif /* HAL_UART_ENABLED */
