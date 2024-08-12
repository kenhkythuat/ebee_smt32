################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.c \
../cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.c \
../cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.c \
../cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.c 

OBJS += \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.o \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.o \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.o \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.o 

C_DEPS += \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.d \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.d \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.d \
./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/tests/unity/extras/fixture/test/%.o cJSON-master/cJSON-master/tests/unity/extras/fixture/test/%.su cJSON-master/cJSON-master/tests/unity/extras/fixture/test/%.cyclo: ../cJSON-master/cJSON-master/tests/unity/extras/fixture/test/%.c cJSON-master/cJSON-master/tests/unity/extras/fixture/test/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-extras-2f-fixture-2f-test

clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-extras-2f-fixture-2f-test:
	-$(RM) ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.cyclo ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.d ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.o ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/template_fixture_tests.su ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.cyclo ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.d ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.o ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_Test.su ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.cyclo ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.d ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.o ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_fixture_TestRunner.su ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.cyclo ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.d ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.o ./cJSON-master/cJSON-master/tests/unity/extras/fixture/test/unity_output_Spy.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-extras-2f-fixture-2f-test

