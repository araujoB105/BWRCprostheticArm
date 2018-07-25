################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\araujo\.arduinocdt\libraries\Servo\1.1.2\src\stm32f4\Servo.cpp 

LINK_OBJ += \
.\libraries\Servo\1.1.2\src\stm32f4\Servo.cpp.o 

CPP_DEPS += \
.\libraries\Servo\1.1.2\src\stm32f4\Servo.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Servo\1.1.2\src\stm32f4\Servo.cpp.o: C:\Users\araujo\.arduinocdt\libraries\Servo\1.1.2\src\stm32f4\Servo.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\.arduinocdt\libraries\Servo\1.1.2\src" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries" -I"C:\Users\araujo\.arduinocdt\libraries\Servo" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


