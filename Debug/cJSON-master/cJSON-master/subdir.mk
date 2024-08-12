################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/cJSON.c \
../cJSON-master/cJSON-master/cJSON_Utils.c \
../cJSON-master/cJSON-master/test.c 

OBJS += \
./cJSON-master/cJSON-master/cJSON.o \
./cJSON-master/cJSON-master/cJSON_Utils.o \
./cJSON-master/cJSON-master/test.o 

C_DEPS += \
./cJSON-master/cJSON-master/cJSON.d \
./cJSON-master/cJSON-master/cJSON_Utils.d \
./cJSON-master/cJSON-master/test.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/%.o cJSON-master/cJSON-master/%.su cJSON-master/cJSON-master/%.cyclo: ../cJSON-master/cJSON-master/%.c cJSON-master/cJSON-master/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master

clean-cJSON-2d-master-2f-cJSON-2d-master:
	-$(RM) ./cJSON-master/cJSON-master/cJSON.cyclo ./cJSON-master/cJSON-master/cJSON.d ./cJSON-master/cJSON-master/cJSON.o ./cJSON-master/cJSON-master/cJSON.su ./cJSON-master/cJSON-master/cJSON_Utils.cyclo ./cJSON-master/cJSON-master/cJSON_Utils.d ./cJSON-master/cJSON-master/cJSON_Utils.o ./cJSON-master/cJSON-master/cJSON_Utils.su ./cJSON-master/cJSON-master/test.cyclo ./cJSON-master/cJSON-master/test.d ./cJSON-master/cJSON-master/test.o ./cJSON-master/cJSON-master/test.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master

