# sharing basic makefile

PRO_DIR		:= .
PROJ_NAME	:= stm32f0_discovery_systick
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR		:= $(PRO_DIR)/inc
SRC_DIR 	:= $(PRO_DIR)/src
LINKER_FILE	:= $(PRO_DIR)/linker/stm32f0_discovery.ld

COMPILER_DIR 	?= C:/tools/gcc_7_2017-q4-major
# COMPILER_DIR 	:= /Users/anhvt6/tools/gcc-arm-none-eabi-7-2017-q4-major

PREFIX_GCC_COMPILER	:= arm-none-eabi
CC				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
ASM				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-as
LD				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-ld

FILE_TO_LINK	:= $(OUTPUT_PATH)/clock.o $(OUTPUT_PATH)/gpio.o $(OUTPUT_PATH)/interrupt.o $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_ARMCM0.o $(OUTPUT_PATH)/systick.o $(OUTPUT_PATH)/usart.o

CC_OPT			:= -march=armv6-m -mcpu=cortex-m0 -c -O0 -g -mthumb -I$(INC_DIR)
ASM_OPT			:= -march=armv6-m -mcpu=cortex-m0 -c -mthumb
LD_OPT			:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

all: clean build

$(OUTPUT_PATH)/clock.o: $(SRC_DIR)/clock.c
	@echo "compile $(SRC_DIR)/clock.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/clock.c -o $(OUTPUT_PATH)/clock.o

$(OUTPUT_PATH)/gpio.o: $(SRC_DIR)/gpio.c
	@echo "compile $(SRC_DIR)/gpio.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/gpio.c -o $(OUTPUT_PATH)/gpio.o

$(OUTPUT_PATH)/interrupt.o: $(SRC_DIR)/interrupt.c
	@echo "compile $(SRC_DIR)/interrupt.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/interrupt.c -o $(OUTPUT_PATH)/interrupt.o

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
	@echo "compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o

$(OUTPUT_PATH)/startup_ARMCM0.o: $(SRC_DIR)/startup_ARMCM0.S
	@echo "compile $(SRC_DIR)/startup_ARMCM0.S file"
	$(ASM) $(ASM_OPT) $(SRC_DIR)/startup_ARMCM0.s -o $(OUTPUT_PATH)/startup_ARMCM0.o

$(OUTPUT_PATH)/systick.o: $(SRC_DIR)/systick.c
	@echo "compile $(SRC_DIR)/systick.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/systick.c -o $(OUTPUT_PATH)/systick.o

$(OUTPUT_PATH)/usart.o: $(SRC_DIR)/usart.c
	@echo "compile $(SRC_DIR)/usart.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/usart.c -o $(OUTPUT_PATH)/usart.o

build: $(FILE_TO_LINK) $(LINKER_FILE)
	@echo "link object files to create new binary image ($(PROJ_NAME).elf)"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf

clean:
	@rm -rf $(OUTPUT_PATH)/*

