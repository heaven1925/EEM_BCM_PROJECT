################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../Middlewares/Third_Party/FreeRTOS/Source/list.c \
../Middlewares/Third_Party/FreeRTOS/Source/queue.c \
../Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../Middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./Middlewares/Third_Party/FreeRTOS/Source/list.o \
./Middlewares/Third_Party/FreeRTOS/Source/queue.o \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./Middlewares/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./Middlewares/Third_Party/FreeRTOS/Source/list.d \
./Middlewares/Third_Party/FreeRTOS/Source/queue.d \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./Middlewares/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/%.o Middlewares/Third_Party/FreeRTOS/Source/%.su: ../Middlewares/Third_Party/FreeRTOS/Source/%.c Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/EEMProtocol/inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/application/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/BodyControlMAIN/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleADC/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleAUDIO/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleCAN/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleCONTROL/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleFLASH/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModulePOWERSWITCH/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleRTC/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleSDCARD/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/features/ModuleTELEMETRY/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/CMSIS/Include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/RFAdaptor/inc" -I"C:/Users/atakan.ertekin/Desktop/WorkSpace/ElectricDriver_CodeSpace/EEM_BCM_PROJECT/Drivers/SX1262/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/croutine.d ./Middlewares/Third_Party/FreeRTOS/Source/croutine.o ./Middlewares/Third_Party/FreeRTOS/Source/croutine.su ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.d ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.o ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.su ./Middlewares/Third_Party/FreeRTOS/Source/list.d ./Middlewares/Third_Party/FreeRTOS/Source/list.o ./Middlewares/Third_Party/FreeRTOS/Source/list.su ./Middlewares/Third_Party/FreeRTOS/Source/queue.d ./Middlewares/Third_Party/FreeRTOS/Source/queue.o ./Middlewares/Third_Party/FreeRTOS/Source/queue.su ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.su ./Middlewares/Third_Party/FreeRTOS/Source/tasks.d ./Middlewares/Third_Party/FreeRTOS/Source/tasks.o ./Middlewares/Third_Party/FreeRTOS/Source/tasks.su ./Middlewares/Third_Party/FreeRTOS/Source/timers.d ./Middlewares/Third_Party/FreeRTOS/Source/timers.o ./Middlewares/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

