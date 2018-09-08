################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/main.c" \

C_SRCS += \
../Sources/main.c \

S_SRCS += \
../Sources/ldr_ex.s \

S_SRCS_QUOTED += \
"../Sources/ldr_ex.s" \

S_DEPS_QUOTED += \
"./Sources/ldr_ex.d" \

OBJS += \
./Sources/ldr_ex.o \
./Sources/main.o \

C_DEPS += \
./Sources/main.d \

S_DEPS += \
./Sources/ldr_ex.d \

OBJS_QUOTED += \
"./Sources/ldr_ex.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/ldr_ex.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/ldr_ex.o: ../Sources/ldr_ex.s
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ldr_ex.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ldr_ex.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


