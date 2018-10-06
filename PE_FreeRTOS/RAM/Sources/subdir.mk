################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/RGB.c" \
"../Sources/main.c" \
"../Sources/user_tasks.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/RGB.c \
../Sources/main.c \
../Sources/user_tasks.c \

OBJS += \
./Sources/Events.o \
./Sources/RGB.o \
./Sources/main.o \
./Sources/user_tasks.o \

C_DEPS += \
./Sources/Events.d \
./Sources/RGB.d \
./Sources/main.d \
./Sources/user_tasks.d \

OBJS_QUOTED += \
"./Sources/Events.o" \
"./Sources/RGB.o" \
"./Sources/main.o" \
"./Sources/user_tasks.o" \

C_DEPS_QUOTED += \
"./Sources/Events.d" \
"./Sources/RGB.d" \
"./Sources/main.d" \
"./Sources/user_tasks.d" \

OBJS_OS_FORMAT += \
./Sources/Events.o \
./Sources/RGB.o \
./Sources/main.o \
./Sources/user_tasks.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/RGB.o: ../Sources/RGB.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/RGB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/RGB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/user_tasks.o: ../Sources/user_tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/user_tasks.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/user_tasks.o"
	@echo 'Finished building: $<'
	@echo ' '


