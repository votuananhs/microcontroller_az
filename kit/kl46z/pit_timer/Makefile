# makefile
# target … : prerequisites …
#		recipe
#		…
#		…

board         := nxp

list_board    := stm32 nxp

ifeq ($(filter $(board),$(list_board)),)
$(error Undefined core selection: '$(board)', use one from: $(list_board))
endif

ifeq ($(board),stm32)
PROJ_NAME			:= stm32f030f4p6_mini
endif

ifeq ($(board),nxp)
PROJ_NAME			:= frdm-kl46z
endif

# Toolchain dir
# GCC_TOOLCHAIN_DIR := $(GCC_DIR)
GCC_TOOLCHAIN_DIR	:= /Users/anhvt6/tools/gcc-arm-none-eabi-7-2017-q4-major
# GCC_TOOLCHAIN_DIR	:= C:/tools/gcc_7_2017-q4-major

# PREFIX_GCC		:= $(PREFIX_GCC_ARM)
PREFIX_GCC			:= arm-none-eabi

# Output folder
OUTPUT_PATH			:= ./output_gcc

# Input folder
WORKSPACE_PATH		:= .

# demo project
INC_PATH			:= $(WORKSPACE_PATH)/inc
LIB_PATH			:= $(GCC_TOOLCHAIN_DIR)/arm-none-eabi/lib

# CMSIS

ifeq ($(board),stm32)
LINKER_FILE			:= $(WORKSPACE_PATH)/linker/STM32F030_mini_board.ld
FILE_TO_LINK := $(OUTPUT_PATH)/startup_ARMCM0.o $(OUTPUT_PATH)/main.o
endif

ifeq ($(board),nxp)
LINKER_FILE			:= $(WORKSPACE_PATH)/linker/MKL46Z256xxx4_flash.ld
FILE_TO_LINK := $(OUTPUT_PATH)/startup_ARMCM0plus.o $(OUTPUT_PATH)/main.o
endif


# Setting compiler
CC		  := $(GCC_TOOLCHAIN_DIR)/bin/$(PREFIX_GCC)-gcc
ASM		  := $(GCC_TOOLCHAIN_DIR)/bin/$(PREFIX_GCC)-as
LD		  := $(GCC_TOOLCHAIN_DIR)/bin/$(PREFIX_GCC)-ld
CP_OPT	:= -I$(INC_PATH) -D__STACK_SIZE=0x500
LD_OPT	:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

# compiler option
CC_OPT	:= -march=armv6-m -mcpu=cortex-m0 -c -O0 -g -mthumb
ASM_OPT	:= -march=armv6-m -mcpu=cortex-m0 -c -mthumb

ifeq ($(board),stm32)
CP_OPT	+= -DSTM32
endif

ifeq ($(board),nxp)
CP_OPT	+= -DNXP
endif

.PHONY : all

$(OUTPUT_PATH)/main.o: $(WORKSPACE_PATH)/src/main.c
	$(CC)	$(CC_OPT) $(CP_OPT)	$(WORKSPACE_PATH)/src/main.c -o  $(OUTPUT_PATH)/main.o

ifeq ($(board),stm32)

# compilation ASM source code files
$(OUTPUT_PATH)/startup_ARMCM0.o: $(WORKSPACE_PATH)/src/startup_ARMCM0.S
	$(ASM)	$(ASM_OPT)	$(WORKSPACE_PATH)/src/startup_ARMCM0.S -o  $(OUTPUT_PATH)/startup_ARMCM0.o
endif

ifeq ($(board),nxp)

# compilation ASM source code files
$(OUTPUT_PATH)/startup_ARMCM0plus.o: $(WORKSPACE_PATH)/src/startup_ARMCM0plus.S
	$(ASM)	$(ASM_OPT)	$(WORKSPACE_PATH)/src/startup_ARMCM0plus.S -o  $(OUTPUT_PATH)/startup_ARMCM0plus.o
endif

#linking

$(OUTPUT_PATH)/$(PROJ_NAME).elf: $(FILE_TO_LINK) $(LINKER_FILE)
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf


all: $(FILE_TO_LINK) $(OUTPUT_PATH)/$(PROJ_NAME).elf

clean:
	rm -rf $(OUTPUT_PATH)/*

