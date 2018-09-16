################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Sources/main.s \

S_SRCS_QUOTED += \
"../Sources/main.s" \

S_DEPS_QUOTED += \
"./Sources/main.d" \

OBJS += \
./Sources/main.o \

S_DEPS += \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/main.o" \

OBJS_OS_FORMAT += \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/main.o: ../Sources/main.s
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


