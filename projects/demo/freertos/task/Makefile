#
# The MIT License (MIT)
#
# Copyright (c) 2018 Anh Vo Tuan <votuananhs@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software
# and associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
# is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies
# or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
# BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
# AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# build system for C project


PRO_DIR				:= ../../../../projects

# board support
board 				= stm32f051r8
BOARD_NAME			:= $(board)
PROJ_NAME			:= task


DEMO_DIR			:= $(PRO_DIR)/demo
HAL_DIR				:= $(PRO_DIR)/hal
LIB_DIR				:= $(PRO_DIR)/lib
BOARD_DIR			:= $(PRO_DIR)/board/$(BOARD_NAME)

FREERTOS_DIR 		:= $(LIB_DIR)/FreeRTOS

# output building folder
BUILD_DIR 			:= ./output


# list folder contains C language files
CC_DIRS				+= $(DEMO_DIR)/freertos/$(PROJ_NAME)/src
CC_DIRS				+= $(HAL_DIR)/stm32/src
CC_DIRS				+= $(FREERTOS_DIR)/FreeRTOS/Source
CC_DIRS				+= $(FREERTOS_DIR)/FreeRTOS/Source/portable/GCC/ARM_CM0
CC_DIRS				+= $(LIB_DIR)/common/src
CC_DIRS				+= $(BOARD_DIR)/src

FREERTOS_HEAP_DIR	:= $(FREERTOS_DIR)/FreeRTOS/Source/portable/MemMang

# list folder contains ASM language files
ASM_DIRS			+= $(BOARD_DIR)/src

# include folders:
INC_DIRS			+= $(DEMO_DIR)/freertos/task/inc
INC_DIRS			+= $(HAL_DIR)/stm32/inc
INC_DIRS			+= $(FREERTOS_DIR)/FreeRTOS/Source/include
INC_DIRS			+= $(FREERTOS_DIR)/FreeRTOS/Source/portable/GCC/ARM_CM0
INC_DIRS			+= $(LIB_DIR)/common/inc
INC_DIRS			+= $(BOARD_DIR)/inc
INC_DIRS			+= $(COMPILER_DIR)/arm-none-eabi/include/sys

# select heap file for FreeRTOS
CC_FILES			+= $(FREERTOS_HEAP_DIR)/heap_2.c

# setting compiler option
CC_OPT				+= -D__STDINT_GCC__
ASM_OPT				+=
LD_OPT				+=

# include setting board to build project
include $(BOARD_DIR)/board.mk

# include build system to use common taget rules:
BUILD_SYSTEM		:= $(PRO_DIR)/build_system
include	$(BUILD_SYSTEM)/common.mk

