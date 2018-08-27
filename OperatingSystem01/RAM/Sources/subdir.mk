################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/OperativeSystem.c" \
"../Sources/Queue.c" \
"../Sources/User.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/OperativeSystem.c \
../Sources/Queue.c \
../Sources/User.c \
../Sources/main.c \

S_SRCS += \
../Sources/save_context.s \
../Sources/set_lr.s \
../Sources/set_lr_sp.s \
../Sources/set_sp.s \
../Sources/set_sp2.s \
../Sources/test.s \
../Sources/test2.s \

S_SRCS_QUOTED += \
"../Sources/save_context.s" \
"../Sources/set_lr.s" \
"../Sources/set_lr_sp.s" \
"../Sources/set_sp.s" \
"../Sources/set_sp2.s" \
"../Sources/test.s" \
"../Sources/test2.s" \

S_DEPS_QUOTED += \
"./Sources/save_context.d" \
"./Sources/set_lr.d" \
"./Sources/set_lr_sp.d" \
"./Sources/set_sp.d" \
"./Sources/set_sp2.d" \
"./Sources/test.d" \
"./Sources/test2.d" \

OBJS += \
./Sources/OperativeSystem.o \
./Sources/Queue.o \
./Sources/User.o \
./Sources/main.o \
./Sources/save_context.o \
./Sources/set_lr.o \
./Sources/set_lr_sp.o \
./Sources/set_sp.o \
./Sources/set_sp2.o \
./Sources/test.o \
./Sources/test2.o \

C_DEPS += \
./Sources/OperativeSystem.d \
./Sources/Queue.d \
./Sources/User.d \
./Sources/main.d \

S_DEPS += \
./Sources/save_context.d \
./Sources/set_lr.d \
./Sources/set_lr_sp.d \
./Sources/set_sp.d \
./Sources/set_sp2.d \
./Sources/test.d \
./Sources/test2.d \

OBJS_QUOTED += \
"./Sources/OperativeSystem.o" \
"./Sources/Queue.o" \
"./Sources/User.o" \
"./Sources/main.o" \
"./Sources/save_context.o" \
"./Sources/set_lr.o" \
"./Sources/set_lr_sp.o" \
"./Sources/set_sp.o" \
"./Sources/set_sp2.o" \
"./Sources/test.o" \
"./Sources/test2.o" \

C_DEPS_QUOTED += \
"./Sources/OperativeSystem.d" \
"./Sources/Queue.d" \
"./Sources/User.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/OperativeSystem.o \
./Sources/Queue.o \
./Sources/User.o \
./Sources/main.o \
./Sources/save_context.o \
./Sources/set_lr.o \
./Sources/set_lr_sp.o \
./Sources/set_sp.o \
./Sources/set_sp2.o \
./Sources/test.o \
./Sources/test2.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/OperativeSystem.o: ../Sources/OperativeSystem.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OperativeSystem.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OperativeSystem.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Queue.o: ../Sources/Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Queue.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Queue.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/User.o: ../Sources/User.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/User.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/User.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/save_context.o: ../Sources/save_context.s
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/save_context.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/save_context.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_lr.o: ../Sources/set_lr.s
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_lr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_lr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_lr_sp.o: ../Sources/set_lr_sp.s
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_lr_sp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_lr_sp.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_sp.o: ../Sources/set_sp.s
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_sp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_sp.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_sp2.o: ../Sources/set_sp2.s
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_sp2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_sp2.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/test.o: ../Sources/test.s
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/test.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/test.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/test2.o: ../Sources/test2.s
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/test2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/test2.o"
	@echo 'Finished building: $<'
	@echo ' '


