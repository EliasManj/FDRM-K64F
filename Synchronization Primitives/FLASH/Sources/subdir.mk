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
../Sources/atomic_read.s \
../Sources/atomic_write.s \

S_SRCS_QUOTED += \
"../Sources/atomic_read.s" \
"../Sources/atomic_write.s" \

S_DEPS_QUOTED += \
"./Sources/atomic_read.d" \
"./Sources/atomic_write.d" \

OBJS += \
./Sources/atomic_read.o \
./Sources/atomic_write.o \
./Sources/main.o \

C_DEPS += \
./Sources/main.d \

S_DEPS += \
./Sources/atomic_read.d \
./Sources/atomic_write.d \

OBJS_QUOTED += \
"./Sources/atomic_read.o" \
"./Sources/atomic_write.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/atomic_read.o \
./Sources/atomic_write.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/atomic_read.o: ../Sources/atomic_read.s
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/atomic_read.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/atomic_read.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/atomic_write.o: ../Sources/atomic_write.s
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/atomic_write.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/atomic_write.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


