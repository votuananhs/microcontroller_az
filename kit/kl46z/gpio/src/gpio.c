
#include "type.h"
#include "gpio.h"

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
void set_mode_pin(u8_t port, u8_t pin, u32_t mode_option)
{

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
void write_pin(u8_t port, u8_t pin, u8_t value)
{

}

/*************************************************************************************************/
/* Function     :   read_pin
 * Brief        :   The function is called to read data of a pin
 * Parameter    :
 *                  [IN] port : port number which will be set up
 *                  [IN] pin : pin number which will be set up
 * Return       :   0 - low loggic; 1 - high loggic
/*************************************************************************************************/
u8_t read_pin(u8_t port, u8_t pin)
{

}

/*************************************************************************************************/
/* Function     :   toggle_pin
 * Brief        :   The function is called to inverse value of a pin
 * Parameter    :
 *                  [IN] port : port number which will be set up
 *                  [IN] pin : pin number which will be set up
 * Return       :   Return value which is set to pin
/*************************************************************************************************/
u8_t toggle_pin(u8_t port, u8_t pin)
{

}

/*************************************************************************************************/
/* Function     :   init_pin
 * Brief        :   The function is called to initialize all pins in program
 * Parameter    :   None
 * Return       :   None
/*************************************************************************************************/
void init_pin(void)
{

}





