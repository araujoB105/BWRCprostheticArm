################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := del 

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include motor\subdir.mk
-include libraries\generic\subdir.mk
-include libraries\Wire\subdir.mk
-include libraries\SPI\subdir.mk
-include libraries\Adafruit_PWM_Servo_Driver_Library\subdir.mk
-include libraries\Adafruit_BluefruitLE_nRF51\utility\subdir.mk
-include libraries\Adafruit_BluefruitLE_nRF51\subdir.mk
-include core\variant\subdir.mk
-include core\core\avr\subdir.mk
-include core\core\USB\subdir.mk
-include core\core\subdir.mk
-include arm\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:\Users\araujo\eclipse-workspace\BWRCprostheticArm\Release\arduino.ar \

ELF += \
BWRCprostheticArm.elf \

HEX += \
BWRCprostheticArm.hex \


# All Target
all: BWRCprostheticArm

# Tool invocations
BWRCprostheticArm: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-size" -A "C:/Users/araujo/eclipse-workspace/BWRCprostheticArm/Release/BWRCprostheticArm.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:\Users\araujo\eclipse-workspace\BWRCprostheticArm\Release\arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-ar" rcs    C:/Users/araujo/eclipse-workspace/BWRCprostheticArm/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

BWRCprostheticArm.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" "-LC:\Users\araujo\eclipse-workspace\BWRCprostheticArm/Release" -Os -Wl,--gc-sections -save-temps "-TC:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0/linker_scripts/gcc/flash_with_bootloader.ld" "-Wl,-Map,C:\Users\araujo\eclipse-workspace\BWRCprostheticArm/Release/BWRCprostheticArm.map" --specs=nano.specs --specs=nosys.specs -mcpu=cortex-m0plus -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -o "C:\Users\araujo\eclipse-workspace\BWRCprostheticArm/Release/BWRCprostheticArm.elf"   $(LINK_OBJ)  -Wl,--start-group "-LC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Lib/GCC/" -larm_cortexM0l_math "-LC:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -lm  C:/Users/araujo/eclipse-workspace/BWRCprostheticArm/Release/arduino.ar  -Wl,--end-group
	@echo 'Finished building: $@'
	@echo ' '

BWRCprostheticArm.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.BIN.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ..\makefile.targets
