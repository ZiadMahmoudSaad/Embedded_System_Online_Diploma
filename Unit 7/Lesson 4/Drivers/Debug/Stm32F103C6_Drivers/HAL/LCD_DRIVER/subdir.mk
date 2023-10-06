################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32F103C6_Drivers/HAL/LCD_DRIVER/LCD.c 

OBJS += \
./Stm32F103C6_Drivers/HAL/LCD_DRIVER/LCD.o 

C_DEPS += \
./Stm32F103C6_Drivers/HAL/LCD_DRIVER/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32F103C6_Drivers/HAL/LCD_DRIVER/LCD.o: ../Stm32F103C6_Drivers/HAL/LCD_DRIVER/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Embedded_System_Online_Diploma/Unit 7/Lesson 4/Drivers/Stm32F103C6_Drivers/HAL/Inc" -I../Inc -I"D:/Embedded_System_Online_Diploma/Unit 7/Lesson 4/Drivers/Stm32F103C6_Drivers/Inc" -I"D:/Embedded_System_Online_Diploma/Unit 7/Lesson 4/Drivers/Stm32F103C6_Drivers/MCAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32F103C6_Drivers/HAL/LCD_DRIVER/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

