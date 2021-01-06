#include "project.h"


/*************************************************************************************************/

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void main(void)
{
    system_init(PREDIV_1, PLL_MUL_12, PLL_SCR_HSI, PREDIV_1, SYSCLKSOURCE_PLLCLK, APB1_HCLK_1);
    enabled_clock();
    pin_init();
    usart_init();
    systick_init();

    interrupt_init();

    while(1)
    {
        led_on(LD3_PIN);
        delay_ms_systick(500);
        led_off(LD3_PIN);
        delay_ms_systick(500);
    }
}

