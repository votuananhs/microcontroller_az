/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Anh Vo Tuan <votuananhs@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "project.h"
#include "driver.h"
#include "clock.h"
#include "gpio.h"
#include "interrupt.h"
#include "systick.h"
#include "usart.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "board.h"

extern volatile unsigned char rx_data;

TaskHandle_t xHandle_led3 = NULL;
TaskHandle_t xHandle_led4 = NULL;

/*************************************************************************************************/
#define NUM_LIST_PINS       4
const gpio_pin_t init_list_pins[NUM_LIST_PINS] =
{
    /* led 3 - PC9 */
    {
        LD3_PORT,
        LD3_PIN,
        GPIO_MODE_OPTION_OUTPUT,
    },
    /* led 4 - PC8 */
    {
        LD4_PORT,
        LD4_PIN,
        GPIO_MODE_OPTION_OUTPUT,
    },
    /* Tx - PA9 */
    {
        PORT_A,
        9,
        GPIO_MODE_OPTION_ALT | GPIO_MODE_OPTION_AF1,
    },
    /* Rx - PA10 */
    {
        PORT_A,
        10,
        GPIO_MODE_OPTION_ALT | GPIO_MODE_OPTION_AF1,
    },
};

/*************************************************************************************************/



void led3_task( void * pvParameters )
{
    static uint8_t state_led3 = 0;
    while (1)
    {
        if(0 == state_led3)
        {
            led_on(LD3);
            state_led3 = 1;
        }
        else
        {
            led_off(LD3);
            state_led3 = 0;
        }
        vTaskDelay(100);
    }
}


void led4_task( void * pvParameters )
{
    static uint8_t state_led4 = 0;

    // while (1)
    // {
        if(0 == state_led4)
        {
            led_on(LD4);
            state_led4 = 1;
        }
        else
        {
            led_off(LD4);
            state_led4 = 0;
        }
        vTaskDelete(xHandle_led4);
    // }
}

void led_task(void * pvParameters)
{
    uint8_t temp = *(uint8_t *)pvParameters;
    uint32_t temp_delay;
    static uint8_t state_led = 0;

    if (LD3 == temp)
    {
        temp_delay = 100;
    }
    else
    {
        temp_delay = 150;
    }
    while(1)
    {
        if(0 == state_led)
        {
            led_on(temp);
            state_led = 1;
        }
        else
        {
            led_off(temp);
            state_led = 0;
        }
        vTaskDelay(temp_delay);
    }
}

void main(void)
{

    uint8_t par_led3 = LD3;
    uint8_t par_led4 = LD4;

    system_init(PREDIV_1, PLL_MUL_12, PLL_SCR_HSI, PREDIV_1, SYSCLKSOURCE_PLLCLK, APB1_HCLK_1);
    enabled_clock();
    init_pin(init_list_pins, NUM_LIST_PINS);
    /*
    usart_init();
    systick_init();
    interrupt_init();
    */




    /* create led3 task */
    #if 0
    xTaskCreate(	led3_task,	/* pvTaskCode */
                    "led 3", /* pcName */
                    100, /* usStackDepth */
                    NULL, /* pvParameters */
                    3, /* uxPriority */
                    &xHandle_led3 /* pxCreatedTask */
                );

    /* create led4 task */
    xTaskCreate(	led4_task,	/* pvTaskCode */
                    "led 4", /* pcName */
                    100, /* usStackDepth */
                    NULL, /* pvParameters */
                    2, /* uxPriority */
                    &xHandle_led4 /* pxCreatedTask */
                );
    #else
    xTaskCreate(	led_task,	/* pvTaskCode */
                    "led 3", /* pcName */
                    100, /* usStackDepth */
                    &par_led3, /* pvParameters */
                    3, /* uxPriority */
                    NULL /* pxCreatedTask */
                );
    xTaskCreate(	led_task,	/* pvTaskCode */
                    "led 4", /* pcName */
                    100, /* usStackDepth */
                    &par_led4, /* pvParameters */
                    3, /* uxPriority */
                    NULL /* pxCreatedTask */
                );
    #endif

    vTaskStartScheduler();


    while(1);
}

/* configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static – otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task’s
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task’s stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
/*———————————————————–*/

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     uint32_t *pulTimerTaskStackSize )
{
/* If the buffers to be provided to the Timer task are declared inside this
function then they must be declared static – otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task’s state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task’s stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}