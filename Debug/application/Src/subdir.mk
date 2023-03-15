################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/Src/app.c 

OBJS += \
./application/Src/app.o 

C_DEPS += \
./application/Src/app.d 


# Each subdirectory must supply rules for building sources it contributes
application/Src/%.o application/Src/%.su: ../application/Src/%.c application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Drivers/EEMProtocol/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/application/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/BodyControlMAIN/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleADC/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleAUDIO/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleCAN/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleCONTROL/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleFLASH/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModulePOWERSWITCH/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleRTC/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleSDCARD/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/features/ModuleTELEMETRY/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Drivers/CMSIS/Include" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.10.1/EGE_AKSV2_2023/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-application-2f-Src

clean-application-2f-Src:
	-$(RM) ./application/Src/app.d ./application/Src/app.o ./application/Src/app.su

.PHONY: clean-application-2f-Src

