################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.c \
../cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.c 

OBJS += \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.o \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.o 

C_DEPS += \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.d \
./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/tests/unity/test/expectdata/%.o cJSON-master/cJSON-master/tests/unity/test/expectdata/%.su cJSON-master/cJSON-master/tests/unity/test/expectdata/%.cyclo: ../cJSON-master/cJSON-master/tests/unity/test/expectdata/%.c cJSON-master/cJSON-master/tests/unity/test/expectdata/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-test-2f-expectdata

clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-test-2f-expectdata:
	-$(RM) ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_cmd.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_def.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_head1.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_cmd.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_def.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_head1.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new1.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_new2.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_param.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run1.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_run2.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_mock_yaml.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new1.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_new2.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_param.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run1.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_run2.su ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.cyclo ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.d ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.o ./cJSON-master/cJSON-master/tests/unity/test/expectdata/testsample_yaml.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests-2f-unity-2f-test-2f-expectdata

