
#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "hw_frdm_kl46z.h"

extern void systick_init(void);
extern void start_systick(unsigned int value);
extern unsigned int get_state_systick(void);
extern void delay_ms_systick(unsigned int value);

/* end file */
#endif /* __SYSTICK_H__ */
