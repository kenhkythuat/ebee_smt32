################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON-master/cJSON-master/tests/cjson_add.c \
../cJSON-master/cJSON-master/tests/compare_tests.c \
../cJSON-master/cJSON-master/tests/json_patch_tests.c \
../cJSON-master/cJSON-master/tests/minify_tests.c \
../cJSON-master/cJSON-master/tests/misc_tests.c \
../cJSON-master/cJSON-master/tests/misc_utils_tests.c \
../cJSON-master/cJSON-master/tests/old_utils_tests.c \
../cJSON-master/cJSON-master/tests/parse_array.c \
../cJSON-master/cJSON-master/tests/parse_examples.c \
../cJSON-master/cJSON-master/tests/parse_hex4.c \
../cJSON-master/cJSON-master/tests/parse_number.c \
../cJSON-master/cJSON-master/tests/parse_object.c \
../cJSON-master/cJSON-master/tests/parse_string.c \
../cJSON-master/cJSON-master/tests/parse_value.c \
../cJSON-master/cJSON-master/tests/parse_with_opts.c \
../cJSON-master/cJSON-master/tests/print_array.c \
../cJSON-master/cJSON-master/tests/print_number.c \
../cJSON-master/cJSON-master/tests/print_object.c \
../cJSON-master/cJSON-master/tests/print_string.c \
../cJSON-master/cJSON-master/tests/print_value.c \
../cJSON-master/cJSON-master/tests/readme_examples.c \
../cJSON-master/cJSON-master/tests/unity_setup.c 

OBJS += \
./cJSON-master/cJSON-master/tests/cjson_add.o \
./cJSON-master/cJSON-master/tests/compare_tests.o \
./cJSON-master/cJSON-master/tests/json_patch_tests.o \
./cJSON-master/cJSON-master/tests/minify_tests.o \
./cJSON-master/cJSON-master/tests/misc_tests.o \
./cJSON-master/cJSON-master/tests/misc_utils_tests.o \
./cJSON-master/cJSON-master/tests/old_utils_tests.o \
./cJSON-master/cJSON-master/tests/parse_array.o \
./cJSON-master/cJSON-master/tests/parse_examples.o \
./cJSON-master/cJSON-master/tests/parse_hex4.o \
./cJSON-master/cJSON-master/tests/parse_number.o \
./cJSON-master/cJSON-master/tests/parse_object.o \
./cJSON-master/cJSON-master/tests/parse_string.o \
./cJSON-master/cJSON-master/tests/parse_value.o \
./cJSON-master/cJSON-master/tests/parse_with_opts.o \
./cJSON-master/cJSON-master/tests/print_array.o \
./cJSON-master/cJSON-master/tests/print_number.o \
./cJSON-master/cJSON-master/tests/print_object.o \
./cJSON-master/cJSON-master/tests/print_string.o \
./cJSON-master/cJSON-master/tests/print_value.o \
./cJSON-master/cJSON-master/tests/readme_examples.o \
./cJSON-master/cJSON-master/tests/unity_setup.o 

C_DEPS += \
./cJSON-master/cJSON-master/tests/cjson_add.d \
./cJSON-master/cJSON-master/tests/compare_tests.d \
./cJSON-master/cJSON-master/tests/json_patch_tests.d \
./cJSON-master/cJSON-master/tests/minify_tests.d \
./cJSON-master/cJSON-master/tests/misc_tests.d \
./cJSON-master/cJSON-master/tests/misc_utils_tests.d \
./cJSON-master/cJSON-master/tests/old_utils_tests.d \
./cJSON-master/cJSON-master/tests/parse_array.d \
./cJSON-master/cJSON-master/tests/parse_examples.d \
./cJSON-master/cJSON-master/tests/parse_hex4.d \
./cJSON-master/cJSON-master/tests/parse_number.d \
./cJSON-master/cJSON-master/tests/parse_object.d \
./cJSON-master/cJSON-master/tests/parse_string.d \
./cJSON-master/cJSON-master/tests/parse_value.d \
./cJSON-master/cJSON-master/tests/parse_with_opts.d \
./cJSON-master/cJSON-master/tests/print_array.d \
./cJSON-master/cJSON-master/tests/print_number.d \
./cJSON-master/cJSON-master/tests/print_object.d \
./cJSON-master/cJSON-master/tests/print_string.d \
./cJSON-master/cJSON-master/tests/print_value.d \
./cJSON-master/cJSON-master/tests/readme_examples.d \
./cJSON-master/cJSON-master/tests/unity_setup.d 


# Each subdirectory must supply rules for building sources it contributes
cJSON-master/cJSON-master/tests/%.o cJSON-master/cJSON-master/tests/%.su cJSON-master/cJSON-master/tests/%.cyclo: ../cJSON-master/cJSON-master/tests/%.c cJSON-master/cJSON-master/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/Agriconnect/cJSON-master/cJSON-master" -I"C:/Users/ADMIN/Documents/Zalo Received Files/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/ebee-stm32-feature-first-draft/cJSON-master/cJSON-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests

clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests:
	-$(RM) ./cJSON-master/cJSON-master/tests/cjson_add.cyclo ./cJSON-master/cJSON-master/tests/cjson_add.d ./cJSON-master/cJSON-master/tests/cjson_add.o ./cJSON-master/cJSON-master/tests/cjson_add.su ./cJSON-master/cJSON-master/tests/compare_tests.cyclo ./cJSON-master/cJSON-master/tests/compare_tests.d ./cJSON-master/cJSON-master/tests/compare_tests.o ./cJSON-master/cJSON-master/tests/compare_tests.su ./cJSON-master/cJSON-master/tests/json_patch_tests.cyclo ./cJSON-master/cJSON-master/tests/json_patch_tests.d ./cJSON-master/cJSON-master/tests/json_patch_tests.o ./cJSON-master/cJSON-master/tests/json_patch_tests.su ./cJSON-master/cJSON-master/tests/minify_tests.cyclo ./cJSON-master/cJSON-master/tests/minify_tests.d ./cJSON-master/cJSON-master/tests/minify_tests.o ./cJSON-master/cJSON-master/tests/minify_tests.su ./cJSON-master/cJSON-master/tests/misc_tests.cyclo ./cJSON-master/cJSON-master/tests/misc_tests.d ./cJSON-master/cJSON-master/tests/misc_tests.o ./cJSON-master/cJSON-master/tests/misc_tests.su ./cJSON-master/cJSON-master/tests/misc_utils_tests.cyclo ./cJSON-master/cJSON-master/tests/misc_utils_tests.d ./cJSON-master/cJSON-master/tests/misc_utils_tests.o ./cJSON-master/cJSON-master/tests/misc_utils_tests.su ./cJSON-master/cJSON-master/tests/old_utils_tests.cyclo ./cJSON-master/cJSON-master/tests/old_utils_tests.d ./cJSON-master/cJSON-master/tests/old_utils_tests.o ./cJSON-master/cJSON-master/tests/old_utils_tests.su ./cJSON-master/cJSON-master/tests/parse_array.cyclo ./cJSON-master/cJSON-master/tests/parse_array.d ./cJSON-master/cJSON-master/tests/parse_array.o ./cJSON-master/cJSON-master/tests/parse_array.su ./cJSON-master/cJSON-master/tests/parse_examples.cyclo ./cJSON-master/cJSON-master/tests/parse_examples.d ./cJSON-master/cJSON-master/tests/parse_examples.o ./cJSON-master/cJSON-master/tests/parse_examples.su ./cJSON-master/cJSON-master/tests/parse_hex4.cyclo ./cJSON-master/cJSON-master/tests/parse_hex4.d ./cJSON-master/cJSON-master/tests/parse_hex4.o ./cJSON-master/cJSON-master/tests/parse_hex4.su ./cJSON-master/cJSON-master/tests/parse_number.cyclo ./cJSON-master/cJSON-master/tests/parse_number.d ./cJSON-master/cJSON-master/tests/parse_number.o ./cJSON-master/cJSON-master/tests/parse_number.su ./cJSON-master/cJSON-master/tests/parse_object.cyclo ./cJSON-master/cJSON-master/tests/parse_object.d ./cJSON-master/cJSON-master/tests/parse_object.o ./cJSON-master/cJSON-master/tests/parse_object.su ./cJSON-master/cJSON-master/tests/parse_string.cyclo ./cJSON-master/cJSON-master/tests/parse_string.d ./cJSON-master/cJSON-master/tests/parse_string.o ./cJSON-master/cJSON-master/tests/parse_string.su ./cJSON-master/cJSON-master/tests/parse_value.cyclo ./cJSON-master/cJSON-master/tests/parse_value.d ./cJSON-master/cJSON-master/tests/parse_value.o ./cJSON-master/cJSON-master/tests/parse_value.su ./cJSON-master/cJSON-master/tests/parse_with_opts.cyclo ./cJSON-master/cJSON-master/tests/parse_with_opts.d ./cJSON-master/cJSON-master/tests/parse_with_opts.o ./cJSON-master/cJSON-master/tests/parse_with_opts.su ./cJSON-master/cJSON-master/tests/print_array.cyclo ./cJSON-master/cJSON-master/tests/print_array.d ./cJSON-master/cJSON-master/tests/print_array.o ./cJSON-master/cJSON-master/tests/print_array.su ./cJSON-master/cJSON-master/tests/print_number.cyclo ./cJSON-master/cJSON-master/tests/print_number.d ./cJSON-master/cJSON-master/tests/print_number.o ./cJSON-master/cJSON-master/tests/print_number.su ./cJSON-master/cJSON-master/tests/print_object.cyclo ./cJSON-master/cJSON-master/tests/print_object.d ./cJSON-master/cJSON-master/tests/print_object.o ./cJSON-master/cJSON-master/tests/print_object.su ./cJSON-master/cJSON-master/tests/print_string.cyclo ./cJSON-master/cJSON-master/tests/print_string.d ./cJSON-master/cJSON-master/tests/print_string.o ./cJSON-master/cJSON-master/tests/print_string.su ./cJSON-master/cJSON-master/tests/print_value.cyclo ./cJSON-master/cJSON-master/tests/print_value.d ./cJSON-master/cJSON-master/tests/print_value.o ./cJSON-master/cJSON-master/tests/print_value.su ./cJSON-master/cJSON-master/tests/readme_examples.cyclo ./cJSON-master/cJSON-master/tests/readme_examples.d ./cJSON-master/cJSON-master/tests/readme_examples.o ./cJSON-master/cJSON-master/tests/readme_examples.su ./cJSON-master/cJSON-master/tests/unity_setup.cyclo ./cJSON-master/cJSON-master/tests/unity_setup.d ./cJSON-master/cJSON-master/tests/unity_setup.o ./cJSON-master/cJSON-master/tests/unity_setup.su

.PHONY: clean-cJSON-2d-master-2f-cJSON-2d-master-2f-tests

