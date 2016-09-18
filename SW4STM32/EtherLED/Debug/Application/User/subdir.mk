################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/rpavlov/Documents/workspace/stm/EtherLED/Src/gpio.c \
/Users/rpavlov/Documents/workspace/stm/EtherLED/Src/main.c \
/Users/rpavlov/Documents/workspace/stm/EtherLED/Src/spi.c \
/Users/rpavlov/Documents/workspace/stm/EtherLED/Src/stm32f4xx_hal_msp.c \
/Users/rpavlov/Documents/workspace/stm/EtherLED/Src/stm32f4xx_it.c \
/Users/rpavlov/Documents/workspace/stm/EtherLED/Src/tim.c 

OBJS += \
./Application/User/gpio.o \
./Application/User/main.o \
./Application/User/spi.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o \
./Application/User/tim.o 

C_DEPS += \
./Application/User/gpio.d \
./Application/User/main.d \
./Application/User/spi.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d \
./Application/User/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/gpio.o: /Users/rpavlov/Documents/workspace/stm/EtherLED/Src/gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Internet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: /Users/rpavlov/Documents/workspace/stm/EtherLED/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Internet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/spi.o: /Users/rpavlov/Documents/workspace/stm/EtherLED/Src/spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Internet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_msp.o: /Users/rpavlov/Documents/workspace/stm/EtherLED/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Internet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: /Users/rpavlov/Documents/workspace/stm/EtherLED/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Internet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/tim.o: /Users/rpavlov/Documents/workspace/stm/EtherLED/Src/tim.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Internet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/SW4STM32/EtherLED/Drivers/ioLibrary_Driver/Ethernet/W5100" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Include" -I"/Users/rpavlov/Documents/workspace/stm/EtherLED/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


