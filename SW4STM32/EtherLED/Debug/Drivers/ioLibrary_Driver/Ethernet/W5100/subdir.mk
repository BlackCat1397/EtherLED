################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ioLibrary_Driver/Ethernet/W5100/w5100.c 

OBJS += \
./Drivers/ioLibrary_Driver/Ethernet/W5100/w5100.o 

C_DEPS += \
./Drivers/ioLibrary_Driver/Ethernet/W5100/w5100.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ioLibrary_Driver/Ethernet/W5100/%.o: ../Drivers/ioLibrary_Driver/Ethernet/W5100/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


