################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32f407_gpiox.c 

OBJS += \
./drivers/Src/stm32f407_gpiox.o 

C_DEPS += \
./drivers/Src/stm32f407_gpiox.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su drivers/Src/%.cyclo: ../drivers/Src/%.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"D:/Work Space STM32/stm32f4xxDrivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/stm32f407_gpiox.cyclo ./drivers/Src/stm32f407_gpiox.d ./drivers/Src/stm32f407_gpiox.o ./drivers/Src/stm32f407_gpiox.su

.PHONY: clean-drivers-2f-Src

