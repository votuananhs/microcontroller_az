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

/*
 * MCU:     STM32F051R8
 */

#ifndef __HW_PLATFORM_H__
#define __HW_PLATFORM_H__


/* =================== RCC =================== */
#define BASE_ADDR_RCC           0x40021000u
#define RCC_CR                  (BASE_ADDR_RCC + 0x00)
#define RCC_CFGR                (BASE_ADDR_RCC + 0x04)
#define RCC_CIR                 (BASE_ADDR_RCC + 0x08)
#define RCC_AHBENR              (BASE_ADDR_RCC + 0x14)
#define RCC_APB2ENR             (BASE_ADDR_RCC + 0x18)
#define RCC_CFGR2               (BASE_ADDR_RCC + 0x2C)
#define RCC_CFGR3               (BASE_ADDR_RCC + 0x30)
#define RCC_CR2                 (BASE_ADDR_RCC + 0x34)

#define PREDIV_1                0u
#define PREDIV_2                1u
#define PREDIV_3                2u
#define PREDIV_4                3u
#define PREDIV_5                4u
#define PREDIV_6                5u
#define PREDIV_7                6u
#define PREDIV_8                7u
#define PREDIV_9                8u
#define PREDIV_10               9u
#define PREDIV_11               10u
#define PREDIV_12               11u
#define PREDIV_13               12u
#define PREDIV_14               13u
#define PREDIV_15               14u
#define PREDIV_16               15u

#define PLL_MUL_2               0u
#define PLL_MUL_3               1u
#define PLL_MUL_12              10u

#define PLL_SCR_HSI             0u

#define SYSCLKSOURCE_PLLCLK     2u

#define APB1_HCLK_1             0u
#define APB1_HCLK_2             4u
#define APB1_HCLK_4             5u
#define APB1_HCLK_8             6u
#define APB1_HCLK_16            7u


/* =================== GPIO =================== */
#define BASE_ADDR_GPIO          0x48000000u
#define GPIO_MODER(port)        (BASE_ADDR_GPIO + (0x400u * (port)) + 0x00u)
#define GPIO_OTYPER(port)       (BASE_ADDR_GPIO + (0x400u * (port)) + 0x04u)
#define GPIO_OSPEEDR(port)      (BASE_ADDR_GPIO + (0x400u * (port)) + 0x08u)
#define GPIO_PUPDR(port)        (BASE_ADDR_GPIO + (0x400u * (port)) + 0x0Cu)
#define GPIO_IDR(port)          (BASE_ADDR_GPIO + (0x400u * (port)) + 0x10u)
#define GPIO_ODR(port)          (BASE_ADDR_GPIO + (0x400u * (port)) + 0x14u)
#define GPIO_BSRR(port)         (BASE_ADDR_GPIO + (0x400u * (port)) + 0x18u)
#define GPIO_LCKR(port)         (BASE_ADDR_GPIO + (0x400u * (port)) + 0x1Cu)
#define GPIO_AFRL(port)         (BASE_ADDR_GPIO + (0x400u * (port)) + 0x20u)
#define GPIO_AFRH(port)         (BASE_ADDR_GPIO + (0x400u * (port)) + 0x24u)
#define GPIO_BRR(port)          (BASE_ADDR_GPIO + (0x400u * (port)) + 0x28u)

/* definition port id */
#define PORT_A                  0u
#define PORT_B                  1u
#define PORT_C                  2u
#define PORT_D                  3u
#define PORT_E                  4u
#define PORT_F                  5u

/* pin mode */
#define GPIO_MODER_INPUT        0x00u
#define GPIO_MODER_OUTPUT       0x01u
#define GPIO_MODER_ALT          0x02u

/* alternate */
#define AF0                     0x0
#define AF1                     0x1
#define AF2                     0x2
#define AF3                     0x3
#define AF4                     0x4
#define AF5                     0x5
#define AF6                     0x6
#define AF7                     0x7


/* =================== EXTI =================== */
#define BASE_ADDR_EXTI          0x40010400u
#define EXTI_IMR                (BASE_ADDR_EXTI + 0x00u)
#define EXTI_RTSR               (BASE_ADDR_EXTI + 0x08u)
#define EXTI_PR                 (BASE_ADDR_EXTI + 0x14u)


/* =================== SYSCFG =================== */
#define BASE_ADDR_SYSCFG        0x40010000u
#define SYSCFG_EXTICR1          (BASE_ADDR_SYSCFG + 0x08u)


/* =================== NVIC =================== */
#define NVIC_ISER               0xE000E100u
#define NVIC_ICER               0xE000E180u
#define NVIC_ISPR               0xE000E200u
#define NVIC_ICPR               0xE000E280u
#define NVIC_PRI(n)             (0xE000E404u + (n)) /* This register will be accessed as a byte */


/* =================== USART =================== */
#define BASE_ADDR_USART1        0x40013800u

#define USART_CR1               (BASE_ADDR_USART1 + 0x00)
#define USART_CR2               (BASE_ADDR_USART1 + 0x04)
#define USART_CR3               (BASE_ADDR_USART1 + 0x08)
#define USART_BRR               (BASE_ADDR_USART1 + 0x0C)
#define USART_RQR               (BASE_ADDR_USART1 + 0x18)
#define USART_ISR               (BASE_ADDR_USART1 + 0x1C)
#define USART_ICR               (BASE_ADDR_USART1 + 0x20)
#define USART_RDR               (BASE_ADDR_USART1 + 0x24)
#define USART_TDR               (BASE_ADDR_USART1 + 0x28)


/* =================== System Timer - Systick =================== */
#define SYST_CSR                0xE000E010u
#define SYST_RVR                0xE000E014u
#define SYST_CVR                0xE000E018u
#define SYST_CALIB              0xE000E01Cu


/* =================== System Controller Block - SCB =================== */
#define SHPR2                   0xE000ED1Cu
#define SHPR3                   0xE000ED20u

/* end file */
#endif /* __HW_PLATFORM_H__ */

