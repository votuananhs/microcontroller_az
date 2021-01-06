
#ifndef __USART_H__
#define __USART_H__

#include "hw_stm32f051r8.h"

extern void usart_init(void);
extern char usart_send_byte(unsigned char data_input);
extern char usart_send_string(unsigned char *str_data);


/* end file */
#endif /* __USART_H__ */
