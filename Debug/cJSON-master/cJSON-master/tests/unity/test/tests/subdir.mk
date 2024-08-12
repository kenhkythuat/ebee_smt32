################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.c \
../cJSON-master/cJSON-master/tests/unity/test/tests/testunity.c 

OBJS += \
./cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.o \
./cJSON-master/cJSON-master/tests/unity/test/tests/testunity.o 

C_DEPS += \
./cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.d \
./cJSON-master/cJSON-master/tests/unity/test/tests/testunity.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/tests/unity/test/tests/%.o cJSON-master/cJSON-master/tests/unity/test/tests/%.su cJSON-master/cJSON-master/tests/unity/test/tests/%.cyclo: ../cJSON-master/cJSON-master/tests/unity/test/tests/%.c cJSON-master/cJSON-master/tests/unity/test/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-test-2f-tests

clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-test-2f-tests:
	-$(RM) ./cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.cyclo ./cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.d ./cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.o ./cJSON-master/cJSON-master/tests/unity/test/tests/testparameterized.su ./cJSON-master/cJSON-master/tests/unity/test/tests/testunity.cyclo ./cJSON-master/cJSON-master/tests/unity/test/tests/testunity.d ./cJSON-master/cJSON-master/tests/unity/test/tests/testunity.o ./cJSON-master/cJSON-master/tests/unity/test/tests/testunity.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-test-2f-tests

