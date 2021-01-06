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

#ifndef __CLI_H__
#define __CLI_H__

#include "type.h"

#define DELIMITER_CHARACTERS    " -"
#define LEN_INPUT_BUFFER        100

/* ============================== Type ============================= */
typedef struct _cli_t_ {
    const uint8_t *command;
    const void (*entry_function)(uint8_t argc, uint8_t **argv);
    int8_t num_input_par;
    const uint8_t *description;
    struct _cli_t_ *next_command;
} cli_t;

/* ============================== Global Variable ================== */


/* ============================== API ============================== */
extern void help(uint8_t argc, uint8_t **argv);
extern void init_cli(void);
extern int8_t add_cli(cli_t *new_command, uint8_t num_command);
extern void parse_cli(const uint8_t *str_command, const uint8_t len_command);
extern uint8_t prepare_command_cli(const uint8_t character);
extern void clear_buffer_cli(void);


/* end file */
#endif /* __CLI_H__ */
