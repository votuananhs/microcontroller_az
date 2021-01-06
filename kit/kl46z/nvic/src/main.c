
#include "hw_frdm_kl46z.h"

char state_sw1 = 0;

volatile char var1 = 0;
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

void init_led_pin(unsigned int port, unsigned int pin)
{
  unsigned int tmpreg;

  tmpreg = read_reg(PORT_PCR(port, pin), PCR_MUX_MASK);
  tmpreg = tmpreg | LED_GPIO_MODE;
  write_reg(PORT_PCR(port, pin), tmpreg);

  tmpreg = read_reg(GPIO_PDDR(port), 1<<pin);
  tmpreg = tmpreg | 1<<pin; /*output pin */
  write_reg(GPIO_PDDR(port), tmpreg);
}

void init_interrupt_sw1(void)
{
  unsigned int tmpreg;

  /* setting PORT peripheral */
  tmpreg = read_reg(PORT_PCR(SW1_BUTTON_PORT, SW1_BUTTON_PIN), PCR_MUX_MASK);
  tmpreg = tmpreg | (1<<8) | (9<<16) | (1<<1) | 1;
  write_reg(PORT_PCR(SW1_BUTTON_PORT, SW1_BUTTON_PIN), tmpreg);

  /* setting GPIO peripheral */
  tmpreg = read_reg(GPIO_PDDR(SW1_BUTTON_PORT), 1<<SW1_BUTTON_PIN);
  write_reg(GPIO_PDDR(SW1_BUTTON_PORT), tmpreg);

	/* clean ISFR */
	write_reg(PORT_ISFR(SW1_BUTTON_PORT), 0xFFFFFFFF);

  /* setting NVIC */
  tmpreg = read_reg(NVIC_ICPR, 1<<31);
  tmpreg = tmpreg | (1<<31);
  write_reg(NVIC_ICPR, tmpreg);

  tmpreg = read_reg(NVIC_ISER, 1<<31);
  tmpreg = tmpreg | (1<<31);
  write_reg(NVIC_ISER, tmpreg);


  tmpreg = read_reg(NVIC_IPR(ID_INTERRUPT_SW1), NVIC_IPR_MASK(ID_INTERRUPT_SW1));
  tmpreg = tmpreg | SET_PRIORITY(ID_INTERRUPT_SW1, 1);
  write_reg(NVIC_IPR(ID_INTERRUPT_SW1), tmpreg);

  /* global enable interrupt */
  asm("cpsie i" : : : "memory");

}

void clean_interrupt_sw1(void)
{
  unsigned int tmpreg;

  /* clean ISF flag in PORT module */
  tmpreg = read_reg(PORT_ISFR(SW1_BUTTON_PORT), 1<<SW1_BUTTON_PIN);
  tmpreg = tmpreg | (1<<SW1_BUTTON_PIN);
  write_reg(PORT_ISFR(SW1_BUTTON_PORT), tmpreg);

  /* clean pending register of NVIC */
  tmpreg = read_reg(NVIC_ICPR, 1<<31);
  tmpreg = tmpreg | (1<<31);
  write_reg(NVIC_ICPR, tmpreg);
}

void main(void)
{
  /* int clock */
  enabled_clk();
  /* init red led */
  init_led_pin(PORTE, RED_LED_PIN);
  /* init green led */
  init_led_pin(PORTD, GREEN_LED_PIN);
  /* sw1 */
  init_interrupt_sw1();
  while(1)
  {
    green_led_on();
    delay(0xff);
    green_led_off();
    delay(0xff);
  }
}

void Sw1_IRQHandler(void)
{
  clean_interrupt_sw1();
  if(0 == state_sw1)
  {
    state_sw1 = 1;
    /* turn on led */
    red_led_on();
  }
  else
  {
    state_sw1 = 0;
    /* turn off led */
    red_led_off();
  }
	delay(0xff);
}

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

