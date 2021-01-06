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

#include "gpio.h"

#if defined(HAL_GPIO_ENABLED)


/*===============================================================================================*/
/*===================== Global variable =========================================================*/
/*===============================================================================================*/

/*===============================================================================================*/
/*===================== Private function ========================================================*/
/*===============================================================================================*/

/*===============================================================================================*/
/*===================== Global function =========================================================*/
/*===============================================================================================*/

/*************************************************************************************************/
/* Function     :   set_mode_pin
 * Brief        :   The function is called to setup mode of pin
 * Parameter    :
 *                  [IN] port : port number which will be set up
 *                  [IN] pin : pin number which will be set up
 *                  [IN] mode_option : contain setting options include
 *                                  - mode
 *                                  - alternate mode
 *                                  - direction
 *                                  - pull up/down
 * Return       :   None
/*************************************************************************************************/
status_driver_t set_mode_pin(uint8_t port, uint8_t pin, uint32_t mode_option)
{
    uint32_t temp;
    uint32_t temp_reg;
    status_driver_t result = STATUS_OK;

    /* mode */
    temp = mode_option & 0x03;
    temp_reg = read_reg(GPIO_MODER(port), ~(0x03 << (pin*2)));
    if(GPIO_MODE_OPTION_ANALOG == temp)
    {
        temp_reg |= GPIO_MODE_OPTION_ANALOG << (pin*2);
        write_reg(GPIO_MODER(port), temp_reg);
    }
    else if (GPIO_MODE_OPTION_ALT == temp)
    {
        temp_reg |= GPIO_MODE_OPTION_ALT << (pin*2);
        write_reg(GPIO_MODER(port), temp_reg);
    }
    else if (GPIO_MODE_OPTION_OUTPUT == temp)
    {
        temp_reg |= GPIO_MODE_OPTION_OUTPUT << (pin*2);
        write_reg(GPIO_MODER(port), temp_reg);
    }
    else if (GPIO_MODE_OPTION_INPUT == temp)
    {
        temp_reg |= GPIO_MODE_OPTION_INPUT << (pin*2);
        write_reg(GPIO_MODER(port), temp_reg);
    }

    /* pull-up/down */
    temp = mode_option & 0x0C;
    temp_reg = read_reg(GPIO_PUPDR(port), ~(0x03 << (pin*2)));
    if(GPIO_MODE_OPTION_PULLUP == temp)
    {
        temp_reg |= 0x01 << (pin*2);
        write_reg(GPIO_PUPDR(port), temp_reg);
    }
    else if (GPIO_MODE_OPTION_PULLDOWN == temp)
    {
        temp_reg |= 0x02 << (pin*2);
        write_reg(GPIO_PUPDR(port), temp_reg);
    }

    /* alt mode */
    temp = (mode_option & (0x0F << 4)) >> 4;
    if (pin > 7)
    {
        temp_reg = read_reg(GPIO_AFRH(port), ~(0x0F << (pin*4)));
        temp_reg |= temp << ((pin-8)*4);
        write_reg(GPIO_AFRH(port), temp_reg);
    }
    else
    {
        temp_reg = read_reg(GPIO_AFRL(port), ~(0x0F << (pin*4)));
        temp_reg |= temp << (pin*4);
        write_reg(GPIO_AFRL(port), temp_reg);
    }

    return result;
}

/*************************************************************************************************/
/* Function     :   write_pin
 * Brief        :   The function is called to write new data to a pin
 * Parameter    :
 *                  [IN] port : port number which will be set up
 *                  [IN] pin : pin number which will be set up
 *                  [IN] value : 0 - low loggic; 1 - high loggic
 * Return       :   None
/*************************************************************************************************/
status_driver_t write_pin(uint8_t port, uint8_t pin, uint8_t value)
{
    status_driver_t result = STATUS_OK;

    if(LOW == value)
    {
        write_reg(GPIO_BSRR(port), 1 << (pin + 16));
    }
    else if (HIGH == value)
    {
        write_reg(GPIO_BSRR(port), 1 << pin);
    }
    else
    {
        /* Error input parameter */
        result = STATUS_WRONG_INPUT;
    }

    return result;
}

/*************************************************************************************************/
/* Function     :   read_pin
 * Brief        :   The function is called to read data of a pin
 * Parameter    :
 *                  [IN] port : port number which will be set up
 *                  [IN] pin : pin number which will be set up
 * Return       :   0 - low loggic; 1 - high loggic
/*************************************************************************************************/
uint8_t read_pin(uint8_t port, uint8_t pin)
{
    uint32_t temp;

    temp = read_reg(GPIO_IDR(port), 1 << pin);
    temp = temp >> pin;

    return (uint8_t)temp;
}

/*************************************************************************************************/
/* Function     :   toggle_pin
 * Brief        :   The function is called to inverse value of a pin
 * Parameter    :
 *                  [IN] port : port number which will be set up
 *                  [IN] pin : pin number which will be set up
 * Return       :   Return value which is set to pin
/*************************************************************************************************/
uint8_t toggle_pin(uint8_t port, uint8_t pin)
{
    uint32_t temp;

    temp = read_reg(GPIO_ODR(port), 1 << pin);
    temp = temp >> pin;

    if (LOW == temp)
    {
        write_reg(GPIO_BSRR(port), 1 << pin);
    }
    else
    {
        write_reg(GPIO_BSRR(port), 1 << (pin + 16));
    }

    return temp;
}

/*************************************************************************************************/
/* Function     :   init_pin
 * Brief        :   The function is called to initialize all pins in program
 * Parameter    :   None
 * Return       :   None
/*************************************************************************************************/
status_driver_t init_pin(const gpio_pin_t *list_pins, const uint8_t num_pin)
{
    uint8_t i;
    status_driver_t result = STATUS_OK;

    for(i = 0; i < num_pin; i++)
    {
        result = set_mode_pin(list_pins[i].port, list_pins[i].pin, list_pins[i].mode_option);
        if (STATUS_OK != result)
        {
            break;
        }
    }

    return result;
}




#endif /* HAL_GPIO_ENABLED */
