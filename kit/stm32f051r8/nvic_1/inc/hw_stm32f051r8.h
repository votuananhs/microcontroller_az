
#ifndef __HW_STM32F051R8_H__
#define __HW_STM32F051R8_H__


#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)

/* RCC - clock */
#define BASE_ADDR_RCC		0x40021000u
#define RCC_AHBENR			(BASE_ADDR_RCC + 0x14)

/* GPIO */
#define BASE_ADDR_GPIOA		0x48000000u
#define BASE_ADDR_GPIOC		0x48000800u
#define GPIOC_MODER			(BASE_ADDR_GPIOC + 0x00u)
#define GPIOA_MODER			(BASE_ADDR_GPIOA + 0x00u)
#define GPIO_MODER_INPUT	0x00u
#define GPIO_MODER_OUTPUT	0x01u
#define GPIO_MODER_ALT		0x02u

#define GPIOC_BSRR			(BASE_ADDR_GPIOC + 0x18u)

#define GPIOA_IDR			(BASE_ADDR_GPIOA + 0x10u)

#define GPIOA_PUPDR			(BASE_ADDR_GPIOA + 0x0Cu)

/* Led LD3 - PC9 */
#define LD3_PIN				9
#define LD4_PIN				8

/* user button (B1) - PA0 */
#define USER_BUTTON			0

/* EXTI */
#define BASE_ADDR_EXTI		0x40010400u
#define EXTI_IMR			(BASE_ADDR_EXTI + 0x00u)
#define EXTI_RTSR			(BASE_ADDR_EXTI + 0x08u)
#define EXTI_PR				(BASE_ADDR_EXTI + 0x14u)

/* SYSCFG */
#define BASE_ADDR_SYSCFG	0x40010000u
#define SYSCFG_EXTICR1		(BASE_ADDR_SYSCFG + 0x08u)

/* NVIC */
#define NVIC_ISER			0xE000E100u
#define NVIC_ICER			0xE000E180u
#define NVIC_ISPR			0xE000E200u
#define NVIC_ICPR			0xE000E280u
#define NVIC_PRI1			0xE000E404u

/* end file */
#endif /* __HW_STM32F051R8_H__ */

