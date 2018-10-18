################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/RGB.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/RGB.c \
../Sources/main.c \

OBJS += \
./Sources/RGB.o \
./Sources/main.o \

C_DEPS += \
./Sources/RGB.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/RGB.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/RGB.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/RGB.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/RGB.o: ../Sources/RGB.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/RGB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/RGB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


