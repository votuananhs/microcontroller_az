
#include "hw_stm32f051r8.h"


unsigned int led_state = 0;

void led_on(unsigned char pin_number);
void led_off(unsigned char pin_number);
void delay(unsigned int timeout);

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
	unsigned int temp;
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
	unsigned int temp;
	delay(0xff);
	/* xoa co ngat */
	temp = 1 << 2;
	write_reg(EXTI_PR, temp);
	write_reg(NVIC_ICPR, (1 << 6));
}

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

void enabled_clock(void)
{
	unsigned int tempreg;
	/* set mode led ld3 */
	tempreg = read_reg(RCC_AHBENR, ~(1 << 19));
	tempreg = tempreg | (1 << 19);
	write_reg(RCC_AHBENR, tempreg);
	/* user button */
	tempreg = read_reg(RCC_AHBENR, ~(1 << 17));
	tempreg = tempreg | (1 << 17);
	write_reg(RCC_AHBENR, tempreg);
}

void init_pin(void)
{
	unsigned int tempreg;
	/* set mode led ld3 */
	tempreg = read_reg(GPIOC_MODER, ~(0x03 << 18));
	tempreg = tempreg | (GPIO_MODER_OUTPUT << 18);
	write_reg(GPIOC_MODER, tempreg);
	/* set mode led ld4 */
	tempreg = read_reg(GPIOC_MODER, ~(0x03 << 16));
	tempreg = tempreg | (GPIO_MODER_OUTPUT << 16);
	write_reg(GPIOC_MODER, tempreg);
	/* set mode user button */
	tempreg = read_reg(GPIOA_MODER, ~(0x03 << 0));
	tempreg = tempreg | (GPIO_MODER_INPUT << 0);
	write_reg(GPIOA_MODER, tempreg);
	/* set mode PA2 */
	tempreg = read_reg(GPIOA_MODER, ~(0x03 << 4));
	tempreg = tempreg | (GPIO_MODER_INPUT << 4);
	write_reg(GPIOA_MODER, tempreg);
	/* pull up */
	tempreg = read_reg(GPIOA_PUPDR, ~(0x03 << 4));
	tempreg = tempreg | (0x01 << 4);
	write_reg(GPIOA_PUPDR, tempreg);
}

void init_interrupt(void)
{
	unsigned int tempreg;
	/* enable interrupt for EXTI0 */
	tempreg = read_reg(EXTI_IMR, ~(1 << 0));
	tempreg = tempreg | (1 << 0);
	write_reg(EXTI_IMR, tempreg);

	tempreg = read_reg(EXTI_RTSR, ~(1 << 0));
	tempreg = tempreg | (1 << 0);
	write_reg(EXTI_RTSR, tempreg);
	/* enable interrupt for EXTI2 */
	tempreg = read_reg(EXTI_IMR, ~(1 << 2));
	tempreg = tempreg | (1 << 2);
	write_reg(EXTI_IMR, tempreg);

	tempreg = read_reg(EXTI_RTSR, ~(1 << 2));
	tempreg = tempreg | (1 << 2);
	write_reg(EXTI_RTSR, tempreg);
	/* SYSCFG */
	tempreg = read_reg(SYSCFG_EXTICR1, ~(0x0F << 0));
	tempreg = tempreg | (0x00 << 0);
	write_reg(SYSCFG_EXTICR1, tempreg);
	/* NVIC */
	/* user button */
	tempreg = read_reg(NVIC_PRI1, ~(0xFF << 8));
	tempreg = tempreg | (0x01 << 14);
	write_reg(NVIC_PRI1, tempreg);
	
	/* PA2 - EXTI2 */
	tempreg = read_reg(NVIC_PRI1, ~(0xFF << 16));
	tempreg = tempreg | (0x02 << 22);
	write_reg(NVIC_PRI1, tempreg);
	
	/* user button */
	tempreg = read_reg(NVIC_ISER, ~(1 << 5));
	tempreg = tempreg | (1 << 5);
	write_reg(NVIC_ISER, tempreg);
	
	/* PA2 - EXTI2 */
	tempreg = read_reg(NVIC_ISER, ~(1 << 6));
	tempreg = tempreg | (1 << 6);
	write_reg(NVIC_ISER, tempreg);
	/* enable global interrupt */
	asm("cpsie i");
	//asm("cpsid i");
}

void led_on(unsigned char pin_number)
{
	write_reg(GPIOC_BSRR, 1u << pin_number);
}

void led_off(unsigned char pin_number)
{
	write_reg(GPIOC_BSRR, 1u << (pin_number + 16u));
}

void main(void)
{
	enabled_clock();
	init_pin();
	init_interrupt();
	while(1)
	{
		led_on(LD4_PIN);
		delay(0xff);
		led_off(LD4_PIN);
		delay(0xff);
	}
}

