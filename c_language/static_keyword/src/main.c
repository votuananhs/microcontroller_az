
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

static int var_s_g;
int var_g;

static int xyz_func(void)
{
    return 40;
}

int abc_func(void)
{
    int temp_abc;
    static int var_s_l = xyz_func();
    //static int var_s_l = 2;
    var_s_l++;
    return var_s_l;
}

void main(void)
{
    int temp = 0;
    temp = abc_func();
    temp = abc_func();
    while(1);
}

