################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/freertos.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/freertos.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/freertos.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/EEMProtocol/inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/application/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/BodyControlMAIN/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleADC/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleAUDIO/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleCAN/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleCONTROL/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleFLASH/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModulePOWERSWITCH/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleRTC/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleSDCARD/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleTELEMETRY/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/RFAdaptor/inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/SX1262/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

