
#include "project.h"

volatile unsigned int led_state = 0;
volatile unsigned char rx_data = 0;

/*************************************************************************************************/
void Reserved_IRQHandler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void NMI_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void HardFault_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void SVC_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void PendSV_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void SysTick_Handler(void)
{
    while(1)
    {
        /* nothing to be run here */
    }
}

void EXTI0_1_IRQHandler(void)
{
    volatile unsigned int temp;
    /* Ngat cua PA0 */
    temp = read_reg(EXTI_PR, (1 << 0));
    if (1 == temp)
    {
        if(0 == led_state)
        {
            led_on(LD3_PIN);
            led_state = 1;
        }
        else
        {
            led_off(LD3_PIN);
            led_state = 0;
        }
    }
    /* xoa co ngat */
    temp = 1 << 0;
    write_reg(EXTI_PR, temp);
    write_reg(NVIC_ICPR, (1 << 5));
}

void EXTI2_3_IRQHandler(void)
{
    volatile unsigned int temp;
    /* xoa co ngat */
    temp = 1 << 2;
    write_reg(EXTI_PR, temp);
    write_reg(NVIC_ICPR, (1 << 6));
}

void USART1_IRQHandler(void)
{
    volatile unsigned int temp;
    
    temp = read_reg(USART_ISR, 1 << 6);
    if (0 != temp) /* Tx - TC flag */
    {
        write_reg(USART_ICR, (1<<6));
    }
    temp = read_reg(USART_ISR, 1 << 5);
    if (0 != temp)  /* Rx - RXNE flag */
    {
        rx_data = read_reg(USART_RDR, 0x000000FF);
        write_reg(USART_RQR, (1<<3)); /* ghi giá trị 1 tới USART_RQR[RXFRQ] để xóa cờ USART_ISR[RXNE] */
    }
}

/*************************************************************************************************/

void interrupt_init(void)
{
    unsigned int tempreg;
    /* enable interrupt for EXTI0 */
    tempreg = read_reg(EXTI_IMR, ~(1 << 0));
    tempreg |= 1 << 0;
    write_reg(EXTI_IMR, tempreg);

    tempreg = read_reg(EXTI_RTSR, ~(1 << 0));
    tempreg |= 1 << 0;
    write_reg(EXTI_RTSR, tempreg);
    /* enable interrupt for EXTI2 */
    tempreg = read_reg(EXTI_IMR, ~(1 << 2));
    tempreg |= 1 << 2;
    write_reg(EXTI_IMR, tempreg);

    tempreg = read_reg(EXTI_RTSR, ~(1 << 2));
    tempreg |= 1 << 2;
    write_reg(EXTI_RTSR, tempreg);
    /* SYSCFG */
    tempreg = read_reg(SYSCFG_EXTICR1, ~(0x0F << 0));
    tempreg |= 0x00 << 0;
    write_reg(SYSCFG_EXTICR1, tempreg);
    /* NVIC */
    /* user button */
    tempreg = read_reg(NVIC_PRI1, ~(0xFF << 8));
    tempreg |= 0x01 << 14;
    write_reg(NVIC_PRI1, tempreg);

    /* PA2 - EXTI2 */
    tempreg = read_reg(NVIC_PRI1, ~(0xFF << 16));
    tempreg |= 0x02 << 22;
    write_reg(NVIC_PRI1, tempreg);

    /* user button */
    tempreg = read_reg(NVIC_ISER, ~(1 << 5));
    tempreg |= 1 << 5;
    write_reg(NVIC_ISER, tempreg);

    /* PA2 - EXTI2 */
    tempreg = read_reg(NVIC_ISER, ~(1 << 6));
    tempreg |= 1 << 6;
    write_reg(NVIC_ISER, tempreg);
    
    /* usart1 */
    write_reg(USART_ICR, 0xFFFFFFFF);
    write_reg(USART_RQR, 0xFFFFFFFF);

    /* Tx interrupt */
    tempreg = read_reg(USART_CR1, ~(1 << 6));
    tempreg |= 1 << 6;
    write_reg(USART_CR1, tempreg);

    /* Rx interrupt - RXNEIE */
    tempreg = read_reg(USART_CR1, ~(1 << 5));
    tempreg |= 1 << 5;
    write_reg(USART_CR1, tempreg);
    
    
    tempreg = read_reg(NVIC_ISER, ~(1 << 27));
    tempreg |= 1 << 27;
    write_reg(NVIC_ISER, tempreg);

    tempreg = read_reg(NVIC_PRI7, ~(0xFF << 24));
    tempreg |= 0x01 << 30;
    write_reg(NVIC_PRI7, tempreg);
    
    
    /* enable global interrupt */
    asm("cpsie i");
}

