################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include features/ModuleTELEMETRY/Src/subdir.mk
-include features/ModuleSDCARD/Src/subdir.mk
-include features/ModuleRTC/Src/subdir.mk
-include features/ModulePOWERSWITCH/Src/subdir.mk
-include features/ModuleFLASH/Src/subdir.mk
-include features/ModuleCONTROL/Src/subdir.mk
-include features/ModuleCAN/Src/subdir.mk
-include features/ModuleAUDIO/Src/subdir.mk
-include features/ModuleADC/Src/subdir.mk
-include features/BodyControlMAIN/Src/subdir.mk
-include application/Src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/SX1262/src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/RFAdaptor/src/subdir.mk
-include Drivers/EEMProtocol/src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := EGE_AKSV2_2023
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
EGE_AKSV2_2023.elf \

MAP_FILES += \
EGE_AKSV2_2023.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
EGE_AKSV2_2023.list \

OBJCOPY_HEX += \
EGE_AKSV2_2023.hex \


# All Target
all: main-build

# Main-build Target
main-build: EGE_AKSV2_2023.elf secondary-outputs

# Tool invocations
EGE_AKSV2_2023.elf EGE_AKSV2_2023.map: $(OBJS) $(USER_OBJS) C:\Users\atakan.ertekin\Desktop\WorkSpace\ElectricDriver_CodeSpace\EEM_BCM_PROJECT\STM32F446ZETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "EGE_AKSV2_2023.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\atakan.ertekin\Desktop\WorkSpace\ElectricDriver_CodeSpace\EEM_BCM_PROJECT\STM32F446ZETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="EGE_AKSV2_2023.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

EGE_AKSV2_2023.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "EGE_AKSV2_2023.list"
	@echo 'Finished building: $@'
	@echo ' '

EGE_AKSV2_2023.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "EGE_AKSV2_2023.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) EGE_AKSV2_2023.elf EGE_AKSV2_2023.hex EGE_AKSV2_2023.list EGE_AKSV2_2023.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
