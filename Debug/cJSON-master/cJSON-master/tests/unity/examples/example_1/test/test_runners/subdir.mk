################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.c \
../cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.c 

OBJS += \
./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.o \
./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.o 

C_DEPS += \
./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.d \
./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/%.o cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/%.su cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/%.cyclo: ../cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/%.c cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-examples-2f-example_1-2f-test-2f-test_runners

clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-examples-2f-example_1-2f-test-2f-test_runners:
	-$(RM) ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.cyclo ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.d ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.o ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode2_Runner.su ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.cyclo ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.d ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.o ./cJSON-master/cJSON-master/tests/unity/examples/example_1/test/test_runners/TestProductionCode_Runner.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-examples-2f-example_1-2f-test-2f-test_runners

