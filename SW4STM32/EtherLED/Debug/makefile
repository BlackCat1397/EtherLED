################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/ioLibrary_Driver/Internet/httpServer/subdir.mk
-include Drivers/ioLibrary_Driver/Internet/TFTP/subdir.mk
-include Drivers/ioLibrary_Driver/Internet/SNTP/subdir.mk
-include Drivers/ioLibrary_Driver/Internet/SNMP/subdir.mk
-include Drivers/ioLibrary_Driver/Internet/DNS/subdir.mk
-include Drivers/ioLibrary_Driver/Internet/DHCP/subdir.mk
-include Drivers/ioLibrary_Driver/Ethernet/W5100/subdir.mk
-include Drivers/ioLibrary_Driver/Ethernet/subdir.mk
-include Drivers/ioLibrary_Driver/Application/loopback/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/subdir.mk
-include Application/SW4STM32/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: EtherLED.elf

# Tool invocations
EtherLED.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=nosys.specs -specs=nano.specs -T"../STM32F401RETx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "EtherLED.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "EtherLED.elf" "EtherLED.bin"
	arm-none-eabi-size "EtherLED.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
