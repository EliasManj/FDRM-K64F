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
../Sources/sin_iq.s \

S_SRCS_QUOTED += \
"../Sources/sin_iq.s" \

S_DEPS_QUOTED += \
"./Sources/sin_iq.d" \

OBJS += \
./Sources/main.o \
./Sources/sin_iq.o \

C_DEPS += \
./Sources/main.d \

S_DEPS += \
./Sources/sin_iq.d \

OBJS_QUOTED += \
"./Sources/main.o" \
"./Sources/sin_iq.o" \

C_DEPS_QUOTED += \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/main.o \
./Sources/sin_iq.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sin_iq.o: ../Sources/sin_iq.s
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sin_iq.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sin_iq.o"
	@echo 'Finished building: $<'
	@echo ' '


