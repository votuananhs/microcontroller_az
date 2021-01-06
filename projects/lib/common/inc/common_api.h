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
#ifndef __COMMON_API_H__
#define __COMMON_API_H__

#include "type.h"

#define write_reg(addr, value)      *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)        *((unsigned long int *)(addr)) & (mask)

#define write_4_byte(addr, value)   *((unsigned int *)(addr)) = value
#define write_2_byte(addr, value)   *((unsigned short *)(addr)) = value
#define write_1_byte(addr, value)   *((unsigned char *)(addr)) = value

#define read_4_byte(addr, mask)     *((unsigned int *)(addr)) & (mask)
#define read_2_byte(addr, mask)     *((unsigned short *)(addr)) & (mask)
#define read_1_byte(addr, mask)     *((unsigned char *)(addr)) & (mask)

extern void delay(uint32_t timeout);

#endif /* __COMMON_API_H__ */
