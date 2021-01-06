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
#include "interrupt.h"

#if defined(HAL_INTERRUPT_ENABLED)


/*************************************************************************************************/
void Reserved_IRQHandler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void NMI_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void HardFault_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}


/*************************************************************************************************/

void interrupt_init(void)
{
    unsigned int tempreg;
    /* enable interrupt for EXTI0 */
    tempreg = read_reg(EXTI_IMR, ~(1 << 0));
    tempreg |= 1 << 0;
    write_reg(EXTI_IMR, tempreg);

    tempreg = read_reg(EXTI_RTSR, ~(1 << 0));
    tempreg |= 1 << 0;
    write_reg(EXTI_RTSR, tempreg);
    /* enable interrupt for EXTI2 */
    tempreg = read_reg(EXTI_IMR, ~(1 << 2));
    tempreg |= 1 << 2;
    write_reg(EXTI_IMR, tempreg);

    tempreg = read_reg(EXTI_RTSR, ~(1 << 2));
    tempreg |= 1 << 2;
    write_reg(EXTI_RTSR, tempreg);
    /* SYSCFG */
    tempreg = read_reg(SYSCFG_EXTICR1, ~(0x0F << 0));
    tempreg |= 0x00 << 0;
    write_reg(SYSCFG_EXTICR1, tempreg);
    /* NVIC */
    /* user button */
    tempreg |= 0x01 << 6;
    write_1_byte(NVIC_PRI(5), tempreg);

    /* PA2 - EXTI2 */
    tempreg |= 0x02 << 6;
    write_1_byte(NVIC_PRI(6), tempreg);

    /* user button */
    tempreg = read_reg(NVIC_ISER, ~(1 << 5));
    tempreg |= 1 << 5;
    write_reg(NVIC_ISER, tempreg);

    /* PA2 - EXTI2 */
    tempreg = read_reg(NVIC_ISER, ~(1 << 6));
    tempreg |= 1 << 6;
    write_reg(NVIC_ISER, tempreg);

    /* usart1 */
    write_reg(USART_ICR, 0xFFFFFFFF);
    write_reg(USART_RQR, 0xFFFFFFFF);

    /* Tx interrupt */
    tempreg = read_reg(USART_CR1, ~(1 << 6));
    tempreg |= 1 << 6;
    write_reg(USART_CR1, tempreg);

    /* Rx interrupt - RXNEIE */
    tempreg = read_reg(USART_CR1, ~(1 << 5));
    tempreg |= 1 << 5;
    write_reg(USART_CR1, tempreg);


    tempreg = read_reg(NVIC_ISER, ~(1 << 27));
    tempreg |= 1 << 27;
    write_reg(NVIC_ISER, tempreg);

    tempreg |= 0x01 << 6;
    write_1_byte(NVIC_PRI(31), tempreg);


    /* enable global interrupt */
    asm("cpsie i");
}

#endif /* HAL_INTERRUPT_ENABLED */
