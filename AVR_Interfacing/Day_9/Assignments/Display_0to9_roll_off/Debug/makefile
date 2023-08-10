################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
Display_0to9_roll_off.lss \

FLASH_IMAGE += \
Display_0to9_roll_off.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Display_0to9_roll_off.elf secondary-outputs

# Tool invocations
Display_0to9_roll_off.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Display_0to9_roll_off.map -mmcu=atmega32 -o "Display_0to9_roll_off.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Display_0to9_roll_off.lss: Display_0to9_roll_off.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Display_0to9_roll_off.elf  >"Display_0to9_roll_off.lss"
	@echo 'Finished building: $@'
	@echo ' '

Display_0to9_roll_off.hex: Display_0to9_roll_off.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Display_0to9_roll_off.elf  "Display_0to9_roll_off.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Display_0to9_roll_off.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Display_0to9_roll_off.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Display_0to9_roll_off.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
