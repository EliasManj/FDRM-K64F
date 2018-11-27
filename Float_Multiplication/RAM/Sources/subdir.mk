################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/char_buffer.c" \
"../Sources/main.c" \
"../Sources/uart.c" \

C_SRCS += \
../Sources/char_buffer.c \
../Sources/main.c \
../Sources/uart.c \

OBJS += \
./Sources/char_buffer.o \
./Sources/main.o \
./Sources/uart.o \

C_DEPS += \
./Sources/char_buffer.d \
./Sources/main.d \
./Sources/uart.d \

OBJS_QUOTED += \
"./Sources/char_buffer.o" \
"./Sources/main.o" \
"./Sources/uart.o" \

C_DEPS_QUOTED += \
"./Sources/char_buffer.d" \
"./Sources/main.d" \
"./Sources/uart.d" \

OBJS_OS_FORMAT += \
./Sources/char_buffer.o \
./Sources/main.o \
./Sources/uart.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/char_buffer.o: ../Sources/char_buffer.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/char_buffer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/char_buffer.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart.o: ../Sources/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/uart.o"
	@echo 'Finished building: $<'
	@echo ' '


