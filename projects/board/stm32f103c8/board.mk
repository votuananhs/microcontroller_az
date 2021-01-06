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

# linker file
LINKER_FILE			:= $(BOARD_DIR)/linker/stm32f103c8.ld

# setting compiler option
CC_OPT			+= -march=armv7-m -mcpu=cortex-m3 -c -g -mthumb $(INC_DIR) -DCLI_STAND_ALONE
ASM_OPT			+= -march=armv7-m -mcpu=cortex-m3 -c -mthumb --defsym __STARTUP_CLEAR_BSS=1 --defsym __STACK_SIZE=0x300 --defsym __HEAP_SIZE=0x800
LD_OPT			+= -T $(LINKER_FILE) -Map $(BUILD_DIR)/bin/$(PROJ_NAME).map $(OBJECT_FILE) -L $(COMPILER_DIR)/arm-none-eabi/lib/thumb/v7-m/nofp -lc_nano -lnosys -L $(COMPILER_DIR)/lib/gcc/arm-none-eabi/10.2.1/thumb/v7-m/nofp -lgcc

