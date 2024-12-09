include makefile.conf

PROJECT = test

.PHONY: clean

DEFINES = -D__STARTUP_CLEAR_BSS -D__START=main -DSTM32F4 -DSTM32F411xx -DSTM32F411xE

TOOLCHAIN = arm-none-eabi-
CFLAGS = $(ARCH_FLAGS) $(DEFINES) $(CPU_DEFINES) $(INCLUDES) -Wall -ffunction-sections -fdata-sections -fno-builtin
LFLAGS = --specs=nosys.specs -Wl,--gc-sections -Wl,-Map=$(PROJECT).map -Tlink_stm32f411.ld

# Add HAL source files
#HAL_SRC = ./STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
#          ./STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
#          ./STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
#          ./STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
#          ./STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c

# Add HAL object files to the build
#OBJECTS += $(HAL_SRC:.c=.o)
#OBJECTS += ./STM32CubeF4/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o
OBJECTS += main.o
OBJECTS += ./Includes/syscalls.o
OBJECTS += startup_ARMCM4.o


#INCLUDES = -I./STM32CubeF4/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
#	   -I./STM32CubeF4/Drivers/CMSIS/Include \
#	   -I./STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Inc \
#	   -I./ \

INCLUDES += -I./Includes

%.o: %.S
	$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

$(PROJECT).bin: $(PROJECT).elf
	$(TOOLCHAIN)objcopy -O binary $< $@

$(PROJECT).elf: $(OBJECTS)
	$(TOOLCHAIN)gcc $(LFLAGS) $^ $(CFLAGS) -o $@
clean:
	rm -f *.bin *.map *.elf $(CPUDIR) output.txt
	find . -name '*.o' -delete

burn:
	st-flash write $(PROJECT).bin 0x8000000
