################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../features/ModuleTELEMETRY/Src/ModuleTELEMETRY.c 

OBJS += \
./features/ModuleTELEMETRY/Src/ModuleTELEMETRY.o 

C_DEPS += \
./features/ModuleTELEMETRY/Src/ModuleTELEMETRY.d 


# Each subdirectory must supply rules for building sources it contributes
features/ModuleTELEMETRY/Src/%.o features/ModuleTELEMETRY/Src/%.su: ../features/ModuleTELEMETRY/Src/%.c features/ModuleTELEMETRY/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Drivers/EEMProtocol/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/application/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/BodyControlMAIN/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleADC/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleAUDIO/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleCAN/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleCONTROL/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleFLASH/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModulePOWERSWITCH/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleRTC/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleSDCARD/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/features/ModuleTELEMETRY/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Include" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-features-2f-ModuleTELEMETRY-2f-Src

clean-features-2f-ModuleTELEMETRY-2f-Src:
	-$(RM) ./features/ModuleTELEMETRY/Src/ModuleTELEMETRY.d ./features/ModuleTELEMETRY/Src/ModuleTELEMETRY.o ./features/ModuleTELEMETRY/Src/ModuleTELEMETRY.su

.PHONY: clean-features-2f-ModuleTELEMETRY-2f-Src

