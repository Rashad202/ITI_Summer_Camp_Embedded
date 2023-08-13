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
02-LCD_SIN_MOVE_STRING.lss \

FLASH_IMAGE += \
02-LCD_SIN_MOVE_STRING.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 02-LCD_SIN_MOVE_STRING.elf secondary-outputs

# Tool invocations
02-LCD_SIN_MOVE_STRING.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,02-LCD_SIN_MOVE_STRING.map -mmcu=atmega32 -o "02-LCD_SIN_MOVE_STRING.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

02-LCD_SIN_MOVE_STRING.lss: 02-LCD_SIN_MOVE_STRING.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 02-LCD_SIN_MOVE_STRING.elf  >"02-LCD_SIN_MOVE_STRING.lss"
	@echo 'Finished building: $@'
	@echo ' '

02-LCD_SIN_MOVE_STRING.hex: 02-LCD_SIN_MOVE_STRING.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 02-LCD_SIN_MOVE_STRING.elf  "02-LCD_SIN_MOVE_STRING.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 02-LCD_SIN_MOVE_STRING.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 02-LCD_SIN_MOVE_STRING.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 02-LCD_SIN_MOVE_STRING.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
