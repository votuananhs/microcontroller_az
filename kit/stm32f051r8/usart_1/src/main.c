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

    interrupt_init();

    /* send "Hello world -MCU" to terminal app on PC */
    usart_send_string("Hello world - MCU\r\n");
    led_on(LD4_PIN);
    delay(0xff);
    led_off(LD4_PIN);
    delay(0xff);

    while(1)
    {
        #if 1
        if (0 != rx_data)
        {
            usart_send_byte(rx_data);
            rx_data = 0;
        }
        #else
        usart_send_byte(0x55);
        delay(0xf);
        #endif
    }
}

