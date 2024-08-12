################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/fuzzing/afl.c \
../cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.c \
../cJSON-master/cJSON-master/fuzzing/fuzz_main.c 

OBJS += \
./cJSON-master/cJSON-master/fuzzing/afl.o \
./cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.o \
./cJSON-master/cJSON-master/fuzzing/fuzz_main.o 

C_DEPS += \
./cJSON-master/cJSON-master/fuzzing/afl.d \
./cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.d \
./cJSON-master/cJSON-master/fuzzing/fuzz_main.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/fuzzing/%.o cJSON-master/cJSON-master/fuzzing/%.su cJSON-master/cJSON-master/fuzzing/%.cyclo: ../cJSON-master/cJSON-master/fuzzing/%.c cJSON-master/cJSON-master/fuzzing/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-fuzzing

clean-cJSON-2d-master-2f-cJSON-2d-master-2f-fuzzing:
	-$(RM) ./cJSON-master/cJSON-master/fuzzing/afl.cyclo ./cJSON-master/cJSON-master/fuzzing/afl.d ./cJSON-master/cJSON-master/fuzzing/afl.o ./cJSON-master/cJSON-master/fuzzing/afl.su ./cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.cyclo ./cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.d ./cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.o ./cJSON-master/cJSON-master/fuzzing/cjson_read_fuzzer.su ./cJSON-master/cJSON-master/fuzzing/fuzz_main.cyclo ./cJSON-master/cJSON-master/fuzzing/fuzz_main.d ./cJSON-master/cJSON-master/fuzzing/fuzz_main.o ./cJSON-master/cJSON-master/fuzzing/fuzz_main.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-fuzzing

