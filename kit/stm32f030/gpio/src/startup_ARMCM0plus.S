/**************************************************************************//**
 * @file     startup_ARMCM0plus.s
 * @brief    CMSIS Core Device Startup File for
 *           ARMCM0plus Device Series
 * @version  V5.00
 * @date     02. March 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

	.syntax	unified
	.arch	armv6-m

	.section .stack
	.align	3
	.equ	Stack_Size, 0x00000400
	.globl	__StackTop
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

	.section .heap
	.align	3
	.equ	Heap_Size, 0x00000C00
	.globl	__HeapBase
	.globl	__HeapLimit
__HeapBase:
	.if	Heap_Size
	.space	Heap_Size
	.endif
	.size	__HeapBase, . - __HeapBase
__HeapLimit:
	.size	__HeapLimit, . - __HeapLimit

	.section .vectors
	.align 2
	.globl	__Vectors
__Vectors:
	.long	__StackTop            /* Top of Stack                   */
	.long	Reset_Handler         /* Reset Handler                  */
	.long	NMI_Handler           /* NMI Handler                    */
	.long	HardFault_Handler     /* Hard Fault Handler             */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	SVC_Handler           /* SVCall Handler                 */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	Reserved_IRQHandler   /* Reserved                       */
	.long	PendSV_Handler        /* PendSV Handler                 */
	.long	SysTick_Handler       /* SysTick Handler                */

	/* External interrupts */
	.long	Reserved_IRQHandler   /*  0: DMA channel 0 transfer complete and error  */
	.long	Reserved_IRQHandler   /*  1: DMA channel 1 transfer complete and error  */
	.long	Reserved_IRQHandler   /*  2: DMA channel 2 transfer complete and error  */
	.long	Reserved_IRQHandler   /*  3: DMA channel 3 transfer complete and error  */
	.long	Reserved_IRQHandler   /*  4: Reserved                                   */
	.long	Reserved_IRQHandler   /*  5: FTFA                                       */
	.long	Reserved_IRQHandler   /*  6: PMC                                        */
	.long	Reserved_IRQHandler   /*  7: LLWU                                       */
	.long	Reserved_IRQHandler   /*  8: I2C0                                       */
	.long	Reserved_IRQHandler   /*  9: I2C1                                       */
	.long	Reserved_IRQHandler   /* 10: SPI0                                       */
	.long	Reserved_IRQHandler   /* 11: SPI1                                       */
	.long	Reserved_IRQHandler   /* 12: UART0                                      */
	.long	Reserved_IRQHandler   /* 13: UART1                                      */
	.long	Reserved_IRQHandler   /* 14: UART2                                      */
	.long	Reserved_IRQHandler   /* 15: ADC0                                       */
	.long	Reserved_IRQHandler   /* 16: CMP0                                       */
	.long	Reserved_IRQHandler   /* 17: TPM0                                       */
	.long	Reserved_IRQHandler   /* 18: TPM1                                       */
	.long	Reserved_IRQHandler   /* 19: TPM2                                       */
	.long	Reserved_IRQHandler   /* 20: RTC - Alarm interrupt                      */
	.long	Reserved_IRQHandler   /* 21: RTC - Second interrupt                     */
	.long	Reserved_IRQHandler   /* 22: PIT                                        */
	.long	Reserved_IRQHandler   /* 23: I2S0                                       */
	.long	Reserved_IRQHandler   /* 24: USB OTG                                    */
	.long	Reserved_IRQHandler   /* 25: DAC0                                       */
	.long	Reserved_IRQHandler   /* 26: TSI0                                       */
	.long	Reserved_IRQHandler   /* 27: MCG                                        */
	.long	Reserved_IRQHandler   /* 28: LPTMR0                                     */
	.long	Reserved_IRQHandler   /* 29: SLCD                                       */
	.long	Reserved_IRQHandler   /* 30: Port control module - PORTA                */
	.long	Sw1_IRQHandler        /* 31: Port control module - PORTC and PORT D     */

	.size	__Vectors, . - __Vectors

	.text
	.globl	Reset_Handler
Reset_Handler:
	/* disable watchdog to avoid reset trigger */
	movs r0, #0x0
	ldr	r1, =0x40048100
	str r0, [r1]
	/* refer to new vector table interrupt */

	/* jump into main() function */
	bl	main

	.end
