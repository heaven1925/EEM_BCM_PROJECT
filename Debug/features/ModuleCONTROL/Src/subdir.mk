################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../features/ModuleCONTROL/Src/ModuleCONTROL.c 

OBJS += \
./features/ModuleCONTROL/Src/ModuleCONTROL.o 

C_DEPS += \
./features/ModuleCONTROL/Src/ModuleCONTROL.d 


# Each subdirectory must supply rules for building sources it contributes
features/ModuleCONTROL/Src/%.o features/ModuleCONTROL/Src/%.su: ../features/ModuleCONTROL/Src/%.c features/ModuleCONTROL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/EEMProtocol/inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/application/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/BodyControlMAIN/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleADC/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleAUDIO/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleCAN/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleCONTROL/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleFLASH/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModulePOWERSWITCH/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleRTC/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleSDCARD/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleTELEMETRY/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/RFAdaptor/inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/SX1262/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-features-2f-ModuleCONTROL-2f-Src

clean-features-2f-ModuleCONTROL-2f-Src:
	-$(RM) ./features/ModuleCONTROL/Src/ModuleCONTROL.d ./features/ModuleCONTROL/Src/ModuleCONTROL.o ./features/ModuleCONTROL/Src/ModuleCONTROL.su

.PHONY: clean-features-2f-ModuleCONTROL-2f-Src

