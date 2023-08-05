################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Led_toggle_P13.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Led_toggle_P13.list \

OBJCOPY_HEX += \
Led_toggle_P13.hex \

OBJCOPY_BIN += \
Led_toggle_P13.bin \


# All Target
all: Led_toggle_P13.elf secondary-outputs

# Tool invocations
Led_toggle_P13.elf: $(OBJS) $(USER_OBJS) D:\Embedded_System_Online_Diploma\Unit\ 3\Lesson\ 1\Led_toggle_P13\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Led_toggle_P13.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Embedded_System_Online_Diploma\Unit 3\Lesson 1\Led_toggle_P13\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Led_toggle_P13.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Led_toggle_P13.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Led_toggle_P13.list"
	@echo 'Finished building: $@'
	@echo ' '

Led_toggle_P13.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Led_toggle_P13.hex"
	@echo 'Finished building: $@'
	@echo ' '

Led_toggle_P13.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Led_toggle_P13.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
