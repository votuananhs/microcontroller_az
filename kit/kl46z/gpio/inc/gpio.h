
#ifndef __GPIO_H__
#define __GPIO_H__

#include "hw_frdm_kl46z.h"

/*===============================================================================================*/
/*===================== Global function =========================================================*/
/*===============================================================================================*/

extern void set_mode_pin(u8_t port, u8_t pin, u32_t mode_option);
extern void write_pin(u8_t port, u8_t pin, u8_t value);
extern u8_t read_pin(u8_t port, u8_t pin);
extern u8_t toggle_pin(u8_t port, u8_t pin);

extern void init_pin(void);


/* end file */
#endif /* __GPIO_H__ */
