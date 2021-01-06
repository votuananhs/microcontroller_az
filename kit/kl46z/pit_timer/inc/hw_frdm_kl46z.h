
#ifndef __hw_frdm_kl46z_h__
#define __hw_frdm_kl46z_h__

#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)

#define BASE_ADDRESS_PORT(port)   (0x40049000u + 0x1000*(port))
#define BASE_ADDRESS_GPIO(port)   (0x400FF000u + 0x40*(port))

#define PORTA                     0u
#define PORTB                     1u
#define PORTC                     2u
#define PORTD                     3u
#define PORTE                     4u

#define LED_GPIO_MODE             0x00000100u
#define PCR_MUX_MASK              0xFFFFF8FF


/* LCD pins: PORTx, PIN */
#define LCD_01            0   /* PORT D */
#define LCD_02            4   /* PORT E */
#define LCD_03            23  /* PORT B */
#define LCD_04            22  /* PORT B */
#define LCD_05            17  /* PORT C */
#define LCD_06            21  /* PORT B */
#define LCD_07            7   /* PORT B */
#define LCD_08            8   /* PORT B */
#define LCD_09            5   /* PORT E */
#define LCD_10            18  /* PORT C */
#define LCD_11            10  /* PORT B */
#define LCD_12            11  /* PORT B */

/* PORT */
#define PORT_PCR(port, pin)   (BASE_ADDRESS_PORT(port) + 4*(pin))
#define PORT_ISFR(port)   		(BASE_ADDRESS_PORT(port) + 0xA0)

#define GPIO_PSOR(port)       (BASE_ADDRESS_GPIO(port) + 0x04)
#define GPIO_PCOR(port)       (BASE_ADDRESS_GPIO(port) + 0x08)
#define GPIO_PTOR(port)       (BASE_ADDRESS_GPIO(port) + 0x0C)
#define GPIO_PDDR(port)       (BASE_ADDRESS_GPIO(port) + 0x14)

/* clock */
#define SIM_SCGC5         0x40048038U
#define MASK_CLK_PORT_A   (1<<9)
#define MASK_CLK_PORT_B   (1<<10)
#define MASK_CLK_PORT_C   (1<<11)
#define MASK_CLK_PORT_D   (1<<12)
#define MASK_CLK_PORT_E   (1<<13)
#define MASK_CLK_ALL_PORT (MASK_CLK_PORT_A | MASK_CLK_PORT_B | MASK_CLK_PORT_C | MASK_CLK_PORT_D | MASK_CLK_PORT_E)

#define enabled_clk()     do { \
                              unsigned long int tmpreg; \
                              tmpreg = read_reg(SIM_SCGC5, ~MASK_CLK_ALL_PORT);\
                              tmpreg = tmpreg | MASK_CLK_ALL_PORT; \
                              write_reg(SIM_SCGC5, tmpreg);\
                              delay(10); \
                            } while(0U)

/* NVIC */
#define NVIC_ISER         			0xE000E100
#define NVIC_ICER         			0xE000E180
#define NVIC_ISPR         			0xE000E200
#define NVIC_ICPR         			0xE000E280
#define NVIC_IPR(n)       			0xE000E41C
#define NVIC_IPR_MASK(n)				0xff000000
#define SET_PRIORITY(n, value)	((value) << 30)

/* red led - PTE29 */
#define RED_LED_PIN       29
#define red_led_on()      write_reg(GPIO_PCOR(PORTE), 1 << RED_LED_PIN)

#define red_led_off()     write_reg(GPIO_PSOR(PORTE), 1 << RED_LED_PIN)

/* green led - PTD5 */
#define GREEN_LED_PIN     5
#define green_led_on()    write_reg(GPIO_PCOR(PORTD), 1 << GREEN_LED_PIN)

#define green_led_off()   write_reg(GPIO_PSOR(PORTD), 1 << GREEN_LED_PIN)

/* SW1 button - PTC3 */
#define SW1_BUTTON_PORT		PORTC
#define SW1_BUTTON_PIN		3
#define ID_INTERRUPT_SW1	31

/* end file */
#endif /* __hw_frdm_kl46z_h__ */

