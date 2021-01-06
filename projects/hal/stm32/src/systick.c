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
#include "systick.h"

#if defined(HAL_SYSTICK_ENABLED)

void systick_init(void)
{
    unsigned int tempreg;

    /* Disable Systick - Disable exception - Clear interrupt flag */
    write_reg(SYST_CSR, 0x00000000u);

    /* source clock */
    tempreg = read_reg(SYST_CSR, ~(1 << 2));
    tempreg |= 1 << 2;
    write_reg(SYST_CSR, tempreg);

    /* clear current value */
    write_reg(SYST_CVR, 0x0u);
}

void start_systick(unsigned int value)
{
    unsigned int tempreg;

    write_reg(SYST_RVR, value);
    write_reg(SYST_CVR, 0);

    /* start timer */
    tempreg = read_reg(SYST_CSR, ~(1 << 0));
    tempreg |= 1 << 0;
    write_reg(SYST_CSR, tempreg);
}

unsigned int get_state_systick(void)
{
    unsigned int tempreg;

    /* COUNTFLAG */
    tempreg = read_reg(SYST_CSR, 1 << 16);
    tempreg = tempreg >> 16;

    return tempreg;
}

void delay_ms_systick(unsigned int value)
{
    while(value--)
    {
        start_systick(0xBB7F); /* 1 ms */
        while(0 == get_state_systick());
    }
}


void start_systick_test(unsigned int value)
{
    unsigned int tempreg;

    write_reg(SYST_RVR, value);
    write_reg(SYST_CVR, 0);

    /* start timer */
    tempreg = read_reg(SYST_CSR, ~(1 << 0));
    tempreg |= 3 << 0;
    write_reg(SYST_CSR, tempreg);
}

#endif /* HAL_SYSTICK_ENABLED */
