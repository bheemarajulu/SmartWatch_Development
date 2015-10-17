################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/inc" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/CMSIS/core" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/CMSIS/device" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/HAL_Driver/Inc/Legacy" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/HAL_Driver/Inc" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/ampire480272" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/ampire640480" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/Common" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/cs43l22" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/exc7200" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/ili9325" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/ili9341" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/l3gd20" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/lis302dl" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/lis3dsh" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/lsm303dlhc" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/mfxstm32l152" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/n25q256a" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/ov2640" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/s5k5cag" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/st7735" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/stmpe1600" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/stmpe811" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/ts3510" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Components/wm8994" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Fonts" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/Log" -I"C:/Users/BHEEMA RAJULU/Documents/ST_Workbench/watch/Utilities/STM32F429I-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


