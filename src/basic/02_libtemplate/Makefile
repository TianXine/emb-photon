# ==================================================
#        File : Makefile
# Description : Makefile for project
#      Author : xine
#     Created : 2022-02-18 21:00:25
#   Copyright : (c) 2022 xinedev.org
#    Modified : 2022-02-18 21:00:25
# ==================================================

## Chip and board settings
OPENOCD_INTERFACE = interface/cmsis-dap.cfg # interface/cmsis-dap.cfg
OPENOCD_TARGET = target/stm32f4x.cfg # target/stm32f4x.cfg
OPENOCD_FLASH_ORIG = 0x08000000 # STM32F407ZE
WORKDIR = $(shell pwd)

# Tools
CC=arm-none-eabi-gcc
CXX=arm-none-eabi-g++
LD=arm-none-eabi-ld
AS=arm-none-eabi-as
RM=rm -vf
OBJCOPY=arm-none-eabi-objcopy

## Options
CPUFLAGS = -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
CFLAGS += -Wall -Werror -std=gnu11 $(CPUFLAGS)
CXXFLAGS += -Wall -Werror $(CPUFLAGS)
# text write into flash, use stm32f4_ram.ld for RAM
LDFLAGS = -T stm32f4_flash.ld -lc -lm -u Reset_Handler
# LDXFLAGS = -T stm32f4_flash.ld -nostdlib -cref -u Reset_Handler -Map=$(TARGET).map --gc-sections --defsym=malloc_getpagesize_P=0x80 $(CPUFLAGS)

## Targets
TARGET=flatled
HEXTARGET=$(TARGET).hex
BINTARGET=$(TARGET).bin
OBJS=main.o startup_stm32f4xx.o

.PHONY: all download
all: $(HEXTARGET) $(BINTARGET)

$(TARGET) : $(OBJS)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

$(HEXTARGET) : $(TARGET)
	$(OBJCOPY) -O ihex $< $@

$(BINTARGET) : $(TARGET)
	$(OBJCOPY) -O binary $< $@

download : $(BINTARGET)
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) -c init -c halt -c "flash write_image erase $(WORKDIR)/$(BINTARGET) $(OPENOCD_FLASH_ORIG)" -c halt -c reset -c shutdown
## Clean
.PHONY: clean
clean:
	$(RM) *.o $(TARGET) *.hex *.bin *.map

