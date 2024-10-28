################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/src/RCC_F411.c \
../Core/src/SD_F411.c \
../Core/src/SPI_master_F411.c \
../Core/src/fonts.c \
../Core/src/ili9341.c \
../Core/src/ili9341_touch.c \
../Core/src/main.c 

OBJS += \
./Core/src/RCC_F411.o \
./Core/src/SD_F411.o \
./Core/src/SPI_master_F411.o \
./Core/src/fonts.o \
./Core/src/ili9341.o \
./Core/src/ili9341_touch.o \
./Core/src/main.o 

C_DEPS += \
./Core/src/RCC_F411.d \
./Core/src/SD_F411.d \
./Core/src/SPI_master_F411.d \
./Core/src/fonts.d \
./Core/src/ili9341.d \
./Core/src/ili9341_touch.d \
./Core/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/src/%.o Core/src/%.su Core/src/%.cyclo: ../Core/src/%.c Core/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"C:/Users/User/Desktop/Nucleo_F411_Cmsis/Nucleo_F411_Cmsis/CMSIS/inc" -I"C:/Users/User/Desktop/Nucleo_F411_Cmsis/Nucleo_F411_Cmsis/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-src

clean-Core-2f-src:
	-$(RM) ./Core/src/RCC_F411.cyclo ./Core/src/RCC_F411.d ./Core/src/RCC_F411.o ./Core/src/RCC_F411.su ./Core/src/SD_F411.cyclo ./Core/src/SD_F411.d ./Core/src/SD_F411.o ./Core/src/SD_F411.su ./Core/src/SPI_master_F411.cyclo ./Core/src/SPI_master_F411.d ./Core/src/SPI_master_F411.o ./Core/src/SPI_master_F411.su ./Core/src/fonts.cyclo ./Core/src/fonts.d ./Core/src/fonts.o ./Core/src/fonts.su ./Core/src/ili9341.cyclo ./Core/src/ili9341.d ./Core/src/ili9341.o ./Core/src/ili9341.su ./Core/src/ili9341_touch.cyclo ./Core/src/ili9341_touch.d ./Core/src/ili9341_touch.o ./Core/src/ili9341_touch.su ./Core/src/main.cyclo ./Core/src/main.d ./Core/src/main.o ./Core/src/main.su

.PHONY: clean-Core-2f-src

