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
#include "clock.h"

#if defined(HAL_CLOCK_ENABLED)

uint32_t SystemCoreClock;


/**
  * @brief  Setup the microcontroller system.
  *         Initialize the default HSI clock source, vector table location and the PLL configuration is reset.
  * @param
  *         hsi_prediv: hệ số chia clock từ HSI RC đưa vào PLL Source Mux
  *         pullmux: hệ số chia clock trong khối PLL
  *         pllsrc: hệ số chia clock trong khối PLL
  *         ahb_div: hệ số chia clock cho AHB prescaler
  *         system_source: lựa chọn source clock cho system thông qua System Clock Mux
  *         apb1_div: hệ số chia clock cho APB1 prescaler
  * @retval None
  */
void system_init(uint32_t hsi_prediv, uint32_t pullmux, uint32_t pllsrc, uint32_t ahb_div, uint32_t system_source, uint32_t apb1_div)
{
    uint32_t temp_reg;
    volatile uint32_t timeout;

    /* Disable all interrupts */
    write_reg(RCC_CIR, 0x00000000U);


    /* This infomation gets from SystemClock_Config() function which was generated from STM32CubeMX */
    /* Disable the Internal High Speed oscillator (HSI). */
    temp_reg = read_reg(RCC_CR, ~0x00000001U);
    write_reg(RCC_CR, temp_reg);

    /* Wait till HSI is disabled */
    timeout = 0xFFF;
    do {
        temp_reg = read_reg(RCC_CR, 0x00000002U);
        timeout--;
    } while ((0 != temp_reg) && (timeout > 0));

    /* Disable the main PLL. */
    temp_reg = read_reg(RCC_CR, ~(1 << 24));
    write_reg(RCC_CR, temp_reg);

    /* Wait till PLL is disabled */
    timeout = 0xFFFFFFFF;
    do {
        temp_reg = read_reg(RCC_CR, (1 << 25));
        timeout--;
    } while ((0 != temp_reg) && (timeout > 0));

    /* Configure the main PLL clock source, predivider and multiplication factor. */
    temp_reg = read_reg(RCC_CFGR2, ~0xFFFFFFF0U);
    temp_reg |= hsi_prediv;
    write_reg(RCC_CFGR2, temp_reg);

    temp_reg = read_reg(RCC_CFGR, ~(0xF << 18));
    temp_reg |= pullmux << 18;
    write_reg(RCC_CFGR, temp_reg);

    temp_reg = read_reg(RCC_CFGR, ~(0x3 << 15));
    temp_reg |= pllsrc << 15;
    write_reg(RCC_CFGR, temp_reg);

    /* Enable the main PLL. */
    temp_reg = read_reg(RCC_CR, ~(1 << 24));
    temp_reg |= 1 << 24;
    write_reg(RCC_CR, temp_reg);

    /* Wait till PLL is ready */
    timeout = 0xFFFFFFFF;
    do {
        temp_reg = read_reg(RCC_CR, (1 << 25));
        timeout--;
    } while ((0 == temp_reg) && (timeout > 0));

    /* Initializes the CPU, AHB and APB busses clocks */
    /* HCLK configration */
    temp_reg = read_reg(RCC_CFGR, ~(0xF << 4));
    temp_reg |= ahb_div << 4;
    write_reg(RCC_CFGR, temp_reg);

    /* HSE is selected as System Clock Source */
    temp_reg = read_reg(RCC_CFGR, ~(0x3 << 0));
    temp_reg |= system_source << 0;
    write_reg(RCC_CFGR, temp_reg);

    /* Wait till System clock switch is ready */
    timeout = 0xFFFFFFFF;
    do {
        temp_reg = read_reg(RCC_CFGR, (0x3 << 2));
        timeout--;
    } while (((2<<2) != temp_reg) && (timeout > 0));

    /* APB1 prescaler */
    temp_reg = read_reg(RCC_CFGR, ~(0x7 << 8));
    temp_reg |= apb1_div << 8;
    write_reg(RCC_CFGR, temp_reg);

    /* USART1 */
    temp_reg = read_reg(RCC_CFGR3, ~(0x3 << 0));
    temp_reg |= 0 << 0; /* PCLK1 */
    write_reg(RCC_CFGR3, temp_reg);

	SystemCoreClock = 48000000;
}

void enabled_clock(void)
{
    unsigned int tempreg;
    /* set mode led ld3 */
    tempreg = read_reg(RCC_AHBENR, ~(1 << 19));
    tempreg = tempreg | (1 << 19);
    write_reg(RCC_AHBENR, tempreg);
    /* user button */
    tempreg = read_reg(RCC_AHBENR, ~(1 << 17));
    tempreg = tempreg | (1 << 17);
    write_reg(RCC_AHBENR, tempreg);
    /* usart1 */
    tempreg = read_reg(RCC_APB2ENR, ~(1 << 14));
    tempreg = tempreg | (1 << 14);
    write_reg(RCC_APB2ENR, tempreg);

}

#endif /* HAL_CLOCK_ENABLED */
