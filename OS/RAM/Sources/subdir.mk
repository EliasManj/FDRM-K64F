################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Alarms.c" \
"../Sources/OperativeSystem.c" \
"../Sources/Queue.c" \
"../Sources/RGB.c" \
"../Sources/User.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Alarms.c \
../Sources/OperativeSystem.c \
../Sources/Queue.c \
../Sources/RGB.c \
../Sources/User.c \
../Sources/main.c \

S_SRCS += \
../Sources/restore_context.s \
../Sources/set_lr_sp.s \

S_SRCS_QUOTED += \
"../Sources/restore_context.s" \
"../Sources/set_lr_sp.s" \

S_DEPS_QUOTED += \
"./Sources/restore_context.d" \
"./Sources/set_lr_sp.d" \

OBJS += \
./Sources/Alarms.o \
./Sources/OperativeSystem.o \
./Sources/Queue.o \
./Sources/RGB.o \
./Sources/User.o \
./Sources/main.o \
./Sources/restore_context.o \
./Sources/set_lr_sp.o \

C_DEPS += \
./Sources/Alarms.d \
./Sources/OperativeSystem.d \
./Sources/Queue.d \
./Sources/RGB.d \
./Sources/User.d \
./Sources/main.d \

S_DEPS += \
./Sources/restore_context.d \
./Sources/set_lr_sp.d \

OBJS_QUOTED += \
"./Sources/Alarms.o" \
"./Sources/OperativeSystem.o" \
"./Sources/Queue.o" \
"./Sources/RGB.o" \
"./Sources/User.o" \
"./Sources/main.o" \
"./Sources/restore_context.o" \
"./Sources/set_lr_sp.o" \

C_DEPS_QUOTED += \
"./Sources/Alarms.d" \
"./Sources/OperativeSystem.d" \
"./Sources/Queue.d" \
"./Sources/RGB.d" \
"./Sources/User.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/Alarms.o \
./Sources/OperativeSystem.o \
./Sources/Queue.o \
./Sources/RGB.o \
./Sources/User.o \
./Sources/main.o \
./Sources/restore_context.o \
./Sources/set_lr_sp.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Alarms.o: ../Sources/Alarms.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Alarms.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Alarms.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/OperativeSystem.o: ../Sources/OperativeSystem.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OperativeSystem.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OperativeSystem.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Queue.o: ../Sources/Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Queue.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Queue.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/RGB.o: ../Sources/RGB.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/RGB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/RGB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/User.o: ../Sources/User.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/User.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/User.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/restore_context.o: ../Sources/restore_context.s
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/restore_context.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/restore_context.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_lr_sp.o: ../Sources/set_lr_sp.s
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_lr_sp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_lr_sp.o"
	@echo 'Finished building: $<'
	@echo ' '


