################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_ATParser.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLE.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEBattery.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEEddystone.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEGatt.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEMIDI.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_SPI.cpp \
C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_UART.cpp 

LINK_OBJ += \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_ATParser.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLE.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEBattery.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEEddystone.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEGatt.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEMIDI.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_SPI.cpp.o \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_UART.cpp.o 

CPP_DEPS += \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_ATParser.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLE.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEBattery.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEEddystone.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEGatt.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEMIDI.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_SPI.cpp.d \
.\libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_UART.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_ATParser.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_ATParser.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLE.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLE.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEBattery.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEBattery.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEEddystone.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEEddystone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEGatt.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEGatt.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEMIDI.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BLEMIDI.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_SPI.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_SPI.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_UART.cpp.o: C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_UART.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


