
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__

/* LED D2 - PA4 */
#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)

#define BASE_ADDRESS_GPIOA        0x48000000u

#define LED_D2_PIN_MODE           0x00000100u
#define LED_D2_OFF                0x00000010u
#define LED_D2_ON                 0x00000000u


#define GPIOA_MODER               BASE_ADDRESS_GPIOA + 0x00
#define GPIOA_IDR                 BASE_ADDRESS_GPIOA + 0x10
#define GPIOA_ODR                 BASE_ADDRESS_GPIOA + 0x14
#define GPIOA_BSRR                BASE_ADDRESS_GPIOA + 0x18

#define BASE_ADDRESS_RCC          0x40021000u

#define RCC_AHBENR                BASE_ADDRESS_RCC + 0x14
#define RCC_AHBENR_IOPAEN         0x00020000u

#define enabled_clk()       do { \
                              unsigned long int tmpreg; \
                              tmpreg = read_reg(RCC_AHBENR, ~RCC_AHBENR_IOPAEN);\
                              tmpreg = tmpreg | RCC_AHBENR_IOPAEN; \
                              write_reg(RCC_AHBENR, tmpreg);\
                              delay(10); \
                            } while(0U)

#define init_led_pin()      do { \
                              unsigned long int tmpreg; \
                              tmpreg = read_reg(GPIOA_MODER, 0xFFFFFCFF); \
                              tmpreg = tmpreg | LED_D2_PIN_MODE; \
                              write_reg(GPIOA_MODER, tmpreg); \
                            } while(0U)

#define led_on()            write_reg(GPIOA_ODR, LED_D2_ON);

#define led_off()           write_reg(GPIOA_ODR, LED_D2_OFF);

/* end file */
#endif /* __HW_STM32F030_MINI_H__ */

