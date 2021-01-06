
#ifndef __HW_STM32F051R8_H__
#define __HW_STM32F051R8_H__


#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)


#define write_4_byte(addr, value)    *((unsigned int *)(addr)) = value
#define write_2_byte(addr, value)    *((unsigned short *)(addr)) = value
#define write_1_byte(addr, value)    *((unsigned char *)(addr)) = value

/* RCC - clock */
#define BASE_ADDR_RCC		0x40021000u
#define RCC_AHBENR			(BASE_ADDR_RCC + 0x14)

/* GPIO */
#define BASE_ADDR_GPIO		0x48000800u
#define GPIOC_MODER			(BASE_ADDR_GPIO + 0x00u)
#define GPIO_MODER_INPUT	0x00u
#define GPIO_MODER_OUTPUT	0x01u
#define GPIO_MODER_ALT		0x02u

#define GPIOC_BSRR			(BASE_ADDR_GPIO + 0x18u)



/* Led LD3 - PC9 */
#define LD3_PIN				9

/* end file */
#endif /* __HW_STM32F051R8_H__ */

