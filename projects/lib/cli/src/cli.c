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

/*
#include <stddef.h>
#include <stdio.h>
*/
#include "stdlib.h"
#include "string.h"

#include "cli.h"

/* ============================== Global Variable ================== */
static cli_t *data_list_command = NULL;
static cli_t *start_point_command = NULL;

static uint8_t command_buffer[LEN_INPUT_BUFFER];
static uint8_t num_char;
/* ============================== API ============================== */

/*
 * Name function    : help
 * Brief            :
 * Parameter        :
 * Return           : None
*/
void help(uint8_t argc, uint8_t **argv)
{
    cli_t *temp_command = start_point_command;

    while(temp_command != NULL)
    {
        if (0 == argc)
        {
            #ifdef CLI_STAND_ALONE
            usart_send_string("\n\r");
            usart_send_string(temp_command->command);
            usart_send_string("\n\r\t");
            usart_send_string(temp_command->description);
            usart_send_string("\n\r");
            #else
            printf("\n\r%s\t: %s", temp_command->command, temp_command->description);
            #endif /* CLI_STAND_ALONE */

        }
        else
        {
            if (!(strcmp (argv, temp_command->command)))
            {
                #ifdef CLI_STAND_ALONE
                usart_send_string("\n\r");
                usart_send_string(temp_command->command);
                usart_send_string("\n\r\t");
                usart_send_string(temp_command->description);
                usart_send_string("\n\r");
                #else
                printf("%s\t: %s\n\r", temp_command->command, temp_command->description);
                #endif /* CLI_STAND_ALONE */
            }
        }
        temp_command = temp_command->next_command;
    }
}


/*
 * Name function    : init_cli
 * Brief            :
 * Parameter        :
 * Return           : None
*/
void init_cli(void)
{
    const uint8_t *help_command = "help";
    const uint8_t *help_desciption = "Show all commands on the terminal";
    cli_t *temp_command = (cli_t *)malloc(sizeof(cli_t));

    if(NULL == temp_command)
    {
        /* lock program here, because it can't allocate new
            area memory for this variable */
        while(1);
    }
    temp_command->command = help_command;
    temp_command->entry_function = help;
    temp_command->num_input_par = 0;
    temp_command->description = help_desciption;
    temp_command->next_command = NULL;

    data_list_command = temp_command;
    start_point_command = temp_command;
}


/*
 * Name function    : add_cli
 * Brief            :
 * Parameter        :
 * Return           : None
*/
int8_t add_cli(cli_t *new_command, uint8_t num_command)
{
	uint8_t i;
	int8_t result = 0;

	if (num_command < 1)
	{
		result = -1;
	}
	else
	{
		for(i = 0; i < num_command; i++)
		{
			data_list_command->next_command = &new_command[i];
			data_list_command = data_list_command->next_command;
			data_list_command->next_command = NULL;
		}
	}

	return result;
}


/*
 * Name function    : parse_cli
 * Brief            :
 * Parameter        :
 * Return           : None
*/
void parse_cli(const uint8_t *str_command, const uint8_t len_command)
{
    uint8_t *temp_str = NULL;
    uint8_t num_of_input = 0;
    cli_t *temp_command = start_point_command;
    uint8_t **input_parameter;

    temp_str = strtok(str_command, DELIMITER_CHARACTERS);
    while(temp_command != NULL)
    {
        if (!(strcmp (temp_str, temp_command->command)))
        {
            input_parameter = (uint8_t *)malloc(sizeof(uint32_t) * temp_command->num_input_par);
            num_of_input = 0;
            temp_str = strtok(NULL, DELIMITER_CHARACTERS);
            while(NULL != temp_str)
            {
                if( num_of_input > temp_command->num_input_par)
                {
                    break;
                }
                else
                {
                    input_parameter[num_of_input] = temp_str;
                    temp_str = strtok(NULL, DELIMITER_CHARACTERS);
                    num_of_input++;
                }
            }
            break;
        }
        temp_command = temp_command->next_command;
    }
    if (NULL != temp_command)
    {
        if (num_of_input == temp_command->num_input_par)
        {
            temp_command->entry_function(num_of_input, input_parameter);
        }
        else
        {
            /* message error */
            #ifdef CLI_STAND_ALONE
            usart_send_string("Wrong number of input parameter of command !\n\r");
            #else
            printf("Wrong number of input parameter of command: %s !\n\r", temp_command->command);
            #endif /* CLI_STAND_ALONE */
        }
        free(input_parameter);
    }
    else
    {
        /* don't support the command */
        #ifdef CLI_STAND_ALONE
        usart_send_string("Don't support the command !\n\r");
        #else
        printf("Don't support the command !\n\r");
        #endif /* CLI_STAND_ALONE */
    }

}


/*
 * Name function    : prepare_command_cli
 * Brief            :
 * Parameter        :
 * Return           : return 0 - command didn't finish; 1 - command finished
*/
uint8_t prepare_command_cli(const uint8_t character)
{
    uint8_t result = 0;
    if (13 == character) /* key code of Enter */
    {
        parse_cli(command_buffer, num_char);
        num_char = 0;
        memset(command_buffer, 0, LEN_INPUT_BUFFER);
        result = 1;
    }
    else if(8 == character) /* key code of Backspace */
    {
        num_char--;
        command_buffer[num_char] = 0;
    }
    else
    {
        command_buffer[num_char] = character;
        num_char++;
    }
    return result;
}


/*
 * Name function    : clear_buffer_cli
 * Brief            :
 * Parameter        :
 * Return           : None
*/
void clear_buffer_cli(void)
{
    num_char = 0;
    memset(command_buffer, 0, LEN_INPUT_BUFFER);
}


