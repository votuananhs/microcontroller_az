
#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include "hw_stm32f051r8.h"

/* global variable */
extern volatile unsigned char rx_data;

/* function */
extern void Reserved_IRQHandler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void SVC_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);
extern void EXTI0_1_IRQHandler(void);
extern void EXTI2_3_IRQHandler(void);
extern void interrupt_init(void);

/* end file */
#endif /* __INTERRUPT_H__ */
