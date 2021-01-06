
#ifndef __GPIO_H__
#define __GPIO_H__

#include "hw_stm32f051r8.h"

extern void pin_init(void);
extern void led_on(unsigned char pin_number);
extern void led_off(unsigned char pin_number);

/* end file */
#endif /* __GPIO_H__ */
