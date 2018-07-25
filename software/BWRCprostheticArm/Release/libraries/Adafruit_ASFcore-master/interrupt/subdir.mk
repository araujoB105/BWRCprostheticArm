################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:\Users\araujo\Downloads\Adafruit_ASFcore-master\Adafruit_ASFcore-master\interrupt\interrupt_sam_nvic.c 

C_DEPS += \
.\libraries\Adafruit_ASFcore-master\interrupt\interrupt_sam_nvic.c.d 

LINK_OBJ += \
.\libraries\Adafruit_ASFcore-master\interrupt\interrupt_sam_nvic.c.o 


# Each subdirectory must supply rules for building sources it contributes
libraries\Adafruit_ASFcore-master\interrupt\interrupt_sam_nvic.c.o: C:\Users\araujo\Downloads\Adafruit_ASFcore-master\Adafruit_ASFcore-master\interrupt\interrupt_sam_nvic.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-gcc" -mcpu=cortex-m0plus -mthumb -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -DF_CPU=48000000L -DARDUINO=10802 -DARDUINO_SAMD_FEATHER_M0 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -D__SAMD21G18A__ -DUSB_VID=0x239A -DUSB_PID=0x800B -DUSBCON "-DUSB_MANUFACTURER=\"Adafruit\"" "-DUSB_PRODUCT=\"Feather M0\"" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS/4.5.0/CMSIS/Include/" "-IC:\cp\eclipse\/arduinoPlugin/packages/arduino/tools/CMSIS-Atmel/1.1.0/CMSIS/Device/ATMEL/"  -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\cores\arduino" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\variants\feather_m0" -I"C:\Users\araujo\eclipse-workspace\testFeather\libraries\generic" -I"C:\cp\eclipse\arduinoPlugin\libraries\Adafruit_PWM_Servo_Driver_Library\1.0.2" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\Wire" -I"C:\Users\araujo\Downloads\Adafruit_BluefruitLE_nRF51-master\Adafruit_BluefruitLE_nRF51-master" -I"C:\cp\eclipse\arduinoPlugin\packages\adafruit\hardware\samd\1.0.21\libraries\SPI" -I"C:\Users\araujo\.arduinocdt\packages\arduino\tools\CMSIS\4.0.0-atmel\Device\ATMEL" -I"C:\Users\araujo\Downloads\Adafruit_SleepyDog-master\Adafruit_SleepyDog-master" -I"C:\Users\araujo\Downloads\Adafruit_ASFcore-master\Adafruit_ASFcore-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


