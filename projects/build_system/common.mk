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

COMPILER_DIR 	:= $(GCC_COMPILER)

# board support
board 			:= stm32f051r8
list_board		:= stm32f051r8 stm32f103c8

ifeq ($(filter $(board),$(list_board)),)
$(error Undefined board selection '$(board)', select one from list: $(list_board))
endif

# list of C language files:
CC_FILES 		+= $(foreach __dir,$(CC_DIRS),$(wildcard $(__dir)/*.c))

# list of ASM language files:
ASM_FILES 		+= $(foreach __dir,$(ASM_DIRS),$(wildcard $(__dir)/*.s))
ASM_FILES 		+= $(foreach __dir,$(ASM_DIRS),$(wildcard $(__dir)/*.S))

# include folder
INC_DIR 		= $(foreach __dir,$(INC_DIRS),$(addprefix -I , $(__dir)))

PREFIX_GCC_COMPILER	:= arm-none-eabi
CC				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
ASM				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-as
LD				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-ld
SIZE			:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-size
OBJCPY			:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-objcopy
NM				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-nm

BUILD_FILE		= $(CC_FILES) $(ASM_FILES)
OBJECT_FILE		= $(addprefix $(BUILD_DIR)/obj/,$(addsuffix .o,$(basename $(notdir $(BUILD_FILE)))))
DEPS 			= $(OBJECT_FILE:.o=.d)

.PHONY: all

all: clean build hex size

# generate object file of c file
ifndef generate_c_rule
define generate_c_rule
$(addprefix $(BUILD_DIR)/obj/,$(addsuffix .o,$(basename $(notdir $(1))))): $(1)
	@echo Processing $$<
	$(CC) $(CC_OPT) $$< -o $$@
endef
endif # generate_c_rule

# generate object file of c file
ifndef generate_asm_rule
define generate_asm_rule
$(addprefix $(BUILD_DIR)/obj/,$(addsuffix .o,$(basename $(notdir $(1))))): $(1)
	@echo Processing $$<
	$(ASM) $(ASM_OPT) $$< -o $$@
endef
endif # generate_asm_rule

#generate all c and asm file of project
$(foreach file,$(CC_FILES),$(eval $(call generate_c_rule,$(file))))
$(foreach file,$(ASM_FILES),$(eval $(call generate_asm_rule,$(file))))

size: $(BUILD_DIR)/bin/$(PROJ_NAME).elf
	@echo "Size area memories in binary image $(BUILD_DIR)/bin/$(PROJ_NAME).elf"
	$(SIZE) $(BUILD_DIR)/bin/$(PROJ_NAME).elf

d_size: $(BUILD_DIR)/bin/$(PROJ_NAME).elf
	$(NM) --demangle --print-size --size-sort --reverse-sort -S $(BUILD_DIR)/bin/$(PROJ_NAME).elf

show_flag:
	@echo "\r\nCOMPILER_DIR :"
	@echo $(COMPILER_DIR)
	@echo "\r\nCC_DIRS :"
	@echo $(CC_DIRS)
	@echo "\r\nCC_FILES :"
	@echo $(CC_FILES)
	@echo "\r\nASM_DIRS :"
	@echo $(ASM_DIRS)
	@echo "\r\nASM_FILES :"
	@echo $(ASM_FILES)
	@echo "\r\nINC_DIR :"
	@echo $(INC_DIR)
	@echo "\r\nOBJECT_FILE :"
	@echo $(OBJECT_FILE)
	@echo "\r\nCC_OPT :"
	@echo $(CC_OPT)
	@echo "\r\nASM_OPT :"
	@echo $(ASM_OPT)
	@echo "\r\nLD_OPT :"
	@echo $(LD_OPT)
	@echo "\r\nBUILD_DIR :"
	@echo $(BUILD_DIR)
	@echo "\r\n"

hex: $(BUILD_DIR)/bin/$(PROJ_NAME).elf
	$(OBJCPY) -O ihex $(BUILD_DIR)/bin/$(PROJ_NAME).elf $(BUILD_DIR)/bin/$(PROJ_NAME).hex

build: $(OBJECT_FILE)
	@echo "Linking object files to create new binary image $(BUILD_DIR)/bin/$(PROJ_NAME).elf"
	$(LD) $(LD_OPT) -o $(BUILD_DIR)/bin/$(PROJ_NAME).elf

clean:
	@rm -rf $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/bin
	@mkdir -p $(BUILD_DIR)/obj

-include $(DEPS)


