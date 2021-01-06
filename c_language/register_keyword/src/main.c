
#include "hw_stm32f051r8.h"


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
/*************************************************************************************************/

int abc_func(int input)
{
	int abc_temp = 20;

	abc_temp = abc_temp + input;

	return abc_temp;
}

void main(void)
{
    register int temp = 50;
    // int temp = 1;
    // int *p = &temp;
    int abc;
    register int *temp_2 = abc;

    abc = temp + 10;
    temp--;
    // temp = abc_func(abc);

    while(1);
}

