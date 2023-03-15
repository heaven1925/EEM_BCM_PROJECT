################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/EEMProtocol/src/CAN_SPI.c \
../Drivers/EEMProtocol/src/EEMProtocol.c \
../Drivers/EEMProtocol/src/EEMProtocol_Config.c \
../Drivers/EEMProtocol/src/MCP2515.c 

OBJS += \
./Drivers/EEMProtocol/src/CAN_SPI.o \
./Drivers/EEMProtocol/src/EEMProtocol.o \
./Drivers/EEMProtocol/src/EEMProtocol_Config.o \
./Drivers/EEMProtocol/src/MCP2515.o 

C_DEPS += \
./Drivers/EEMProtocol/src/CAN_SPI.d \
./Drivers/EEMProtocol/src/EEMProtocol.d \
./Drivers/EEMProtocol/src/EEMProtocol_Config.d \
./Drivers/EEMProtocol/src/MCP2515.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/EEMProtocol/src/%.o Drivers/EEMProtocol/src/%.su: ../Drivers/EEMProtocol/src/%.c Drivers/EEMProtocol/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-EEMProtocol-2f-src

clean-Drivers-2f-EEMProtocol-2f-src:
	-$(RM) ./Drivers/EEMProtocol/src/CAN_SPI.d ./Drivers/EEMProtocol/src/CAN_SPI.o ./Drivers/EEMProtocol/src/CAN_SPI.su ./Drivers/EEMProtocol/src/EEMProtocol.d ./Drivers/EEMProtocol/src/EEMProtocol.o ./Drivers/EEMProtocol/src/EEMProtocol.su ./Drivers/EEMProtocol/src/EEMProtocol_Config.d ./Drivers/EEMProtocol/src/EEMProtocol_Config.o ./Drivers/EEMProtocol/src/EEMProtocol_Config.su ./Drivers/EEMProtocol/src/MCP2515.d ./Drivers/EEMProtocol/src/MCP2515.o ./Drivers/EEMProtocol/src/MCP2515.su

.PHONY: clean-Drivers-2f-EEMProtocol-2f-src

