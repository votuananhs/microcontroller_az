
#include "project.h"

void systick_init(void)
{
    unsigned int tempreg;

    /* Disable Systick - Disable exception - Clear interrupt flag */
    write_reg(SYST_CSR, 0x00000000u);

    /* source clock */
    tempreg = read_reg(SYST_CSR, ~(1 << 2));
    tempreg |= 1 << 2;
    write_reg(SYST_CSR, tempreg);

    /* clear current value */
    write_reg(SYST_CVR, 0x0u);
}

void start_systick(unsigned int value)
{
    unsigned int tempreg;

    write_reg(SYST_RVR, value);
    write_reg(SYST_CVR, 0);

    /* start timer */
    tempreg = read_reg(SYST_CSR, ~(1 << 0));
    tempreg |= 1 << 0;
    write_reg(SYST_CSR, tempreg);
}

unsigned int get_state_systick(void)
{
    unsigned int tempreg;

    /* COUNTFLAG */
    tempreg = read_reg(SYST_CSR, 1 << 16);
    tempreg = tempreg >> 16;

    return tempreg;
}

void delay_ms_systick(unsigned int value)
{
    while(value--)
    {
        start_systick(0xBB7F); /* 1 ms */
        while(0 == get_state_systick());
    }
}

