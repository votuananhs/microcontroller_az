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

board 				:= stm32f051r8
BOARD_NAME			:= $(board)
PROJ_NAME			:= cli_project


DEMO_DIR			:= $(PRO_DIR)/demo
HAL_DIR				:= $(PRO_DIR)/hal
LIB_DIR				:= $(PRO_DIR)/lib
BOARD_DIR			:= $(PRO_DIR)/board/$(BOARD_NAME)

# output building folder
BUILD_DIR 			:= ./output


# list folder contains C language files
CC_DIRS				+= $(DEMO_DIR)/basic_mcu/$(PROJ_NAME)/src
CC_DIRS				+= $(HAL_DIR)/stm32/src
CC_DIRS				+= $(LIB_DIR)/cli/src
CC_DIRS				+= $(LIB_DIR)/common/src
CC_DIRS				+= $(BOARD_DIR)/src


# list folder contains ASM language files
ASM_DIRS			+= $(BOARD_DIR)/src

# include folders:
INC_DIRS			+= $(DEMO_DIR)/basic_mcu/$(PROJ_NAME)/inc
INC_DIRS			+= $(HAL_DIR)/stm32/inc
INC_DIRS			+= $(LIB_DIR)/cli/inc
INC_DIRS			+= $(LIB_DIR)/common/inc
INC_DIRS			+= $(BOARD_DIR)/inc

# include setting board to build project
include $(BOARD_DIR)/board.mk

# include build system to use common taget rules:
BUILD_SYSTEM		:= $(PRO_DIR)/build_system
include	$(BUILD_SYSTEM)/common.mk
