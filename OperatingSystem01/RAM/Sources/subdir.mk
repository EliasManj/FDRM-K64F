################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/OperativeSystem.c" \
"../Sources/User.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/OperativeSystem.c \
../Sources/User.c \
../Sources/main.c \

OBJS += \
./Sources/OperativeSystem.o \
./Sources/User.o \
./Sources/main.o \

C_DEPS += \
./Sources/OperativeSystem.d \
./Sources/User.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/OperativeSystem.o" \
"./Sources/User.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/OperativeSystem.d" \
"./Sources/User.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/OperativeSystem.o \
./Sources/User.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/OperativeSystem.o: ../Sources/OperativeSystem.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OperativeSystem.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OperativeSystem.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/User.o: ../Sources/User.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/User.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/User.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


