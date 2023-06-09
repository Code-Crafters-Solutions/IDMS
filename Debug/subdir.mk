################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../INTERNAL_EEPROM.c \
../PhoneList.c \
../SIM_prog.c \
../TopWayLCD_Program.c \
../UART_Prog.c \
../main.c 

OBJS += \
./DIO.o \
./INTERNAL_EEPROM.o \
./PhoneList.o \
./SIM_prog.o \
./TopWayLCD_Program.o \
./UART_Prog.o \
./main.o 

C_DEPS += \
./DIO.d \
./INTERNAL_EEPROM.d \
./PhoneList.d \
./SIM_prog.d \
./TopWayLCD_Program.d \
./UART_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


