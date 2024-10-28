################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/src/system_stm32f4xx.c 

OBJS += \
./CMSIS/src/system_stm32f4xx.o 

C_DEPS += \
./CMSIS/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/src/%.o CMSIS/src/%.su CMSIS/src/%.cyclo: ../CMSIS/src/%.c CMSIS/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"C:/Users/User/Desktop/Nucleo_F411_Cmsis/Nucleo_F411_Cmsis/CMSIS/inc" -I"C:/Users/User/Desktop/Nucleo_F411_Cmsis/Nucleo_F411_Cmsis/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CMSIS-2f-src

clean-CMSIS-2f-src:
	-$(RM) ./CMSIS/src/system_stm32f4xx.cyclo ./CMSIS/src/system_stm32f4xx.d ./CMSIS/src/system_stm32f4xx.o ./CMSIS/src/system_stm32f4xx.su

.PHONY: clean-CMSIS-2f-src

