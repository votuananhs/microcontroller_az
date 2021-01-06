
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

/* Led LD3 - PC9 */
#define LD3_PIN				9

/* user button (B1) - PA0 */
#define USER_BUTTON			0

/* end file */
#endif /* __HW_STM32F051R8_H__ */

