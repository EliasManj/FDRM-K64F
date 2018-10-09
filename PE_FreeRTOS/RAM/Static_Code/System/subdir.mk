################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/CPU_Init.c" \
"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/Peripherals_Init.c" \
"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/Vectors.c" \

C_SRCS += \
$(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/CPU_Init.c \
$(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/Peripherals_Init.c \
$(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/Vectors.c \

OBJS += \
./Static_Code/System/CPU_Init.o \
./Static_Code/System/Peripherals_Init.o \
./Static_Code/System/Vectors.o \

C_DEPS += \
./Static_Code/System/CPU_Init.d \
./Static_Code/System/Peripherals_Init.d \
./Static_Code/System/Vectors.d \

OBJS_QUOTED += \
"./Static_Code/System/CPU_Init.o" \
"./Static_Code/System/Peripherals_Init.o" \
"./Static_Code/System/Vectors.o" \

C_DEPS_QUOTED += \
"./Static_Code/System/CPU_Init.d" \
"./Static_Code/System/Peripherals_Init.d" \
"./Static_Code/System/Vectors.d" \

OBJS_OS_FORMAT += \
./Static_Code/System/CPU_Init.o \
./Static_Code/System/Peripherals_Init.o \
./Static_Code/System/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Static_Code/System/CPU_Init.o: $(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/CPU_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Static_Code/System/CPU_Init.args" -MMD -MP -MF"Static_Code/System/CPU_Init.d" -o"Static_Code/System/CPU_Init.o"
	@echo 'Finished building: $<'
	@echo ' '

Static_Code/System/Peripherals_Init.o: $(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/Peripherals_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Static_Code/System/Peripherals_Init.args" -MMD -MP -MF"Static_Code/System/Peripherals_Init.d" -o"Static_Code/System/Peripherals_Init.o"
	@echo 'Finished building: $<'
	@echo ' '

Static_Code/System/Vectors.o: $(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LQ12/system/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Static_Code/System/Vectors.args" -MMD -MP -MF"Static_Code/System/Vectors.d" -o"Static_Code/System/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


