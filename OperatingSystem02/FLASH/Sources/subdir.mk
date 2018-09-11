################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Alarms.c" \
"../Sources/Mailbox.c" \
"../Sources/OperativeSystem.c" \
"../Sources/Queue.c" \
"../Sources/RGB.c" \
"../Sources/User.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Alarms.c \
../Sources/Mailbox.c \
../Sources/OperativeSystem.c \
../Sources/Queue.c \
../Sources/RGB.c \
../Sources/User.c \
../Sources/main.c \

S_SRCS += \
../Sources/clean_stack_from_chaintask.s \
../Sources/finish_isr.s \
../Sources/finish_isr2.s \
../Sources/get_task_return_dir.s \
../Sources/jump_to_os_loop.s \
../Sources/pop_r7_pc.s \
../Sources/pop_twice.s \
../Sources/recover_context.s \
../Sources/recover_context2.s \
../Sources/restore_context.s \
../Sources/set_pc_sp.s \
../Sources/set_pc_sp_lr.s \
../Sources/set_sp.s \
../Sources/test.s \
../Sources/test2.s \

S_SRCS_QUOTED += \
"../Sources/clean_stack_from_chaintask.s" \
"../Sources/finish_isr.s" \
"../Sources/finish_isr2.s" \
"../Sources/get_task_return_dir.s" \
"../Sources/jump_to_os_loop.s" \
"../Sources/pop_r7_pc.s" \
"../Sources/pop_twice.s" \
"../Sources/recover_context.s" \
"../Sources/recover_context2.s" \
"../Sources/restore_context.s" \
"../Sources/set_pc_sp.s" \
"../Sources/set_pc_sp_lr.s" \
"../Sources/set_sp.s" \
"../Sources/test.s" \
"../Sources/test2.s" \

S_DEPS_QUOTED += \
"./Sources/clean_stack_from_chaintask.d" \
"./Sources/finish_isr.d" \
"./Sources/finish_isr2.d" \
"./Sources/get_task_return_dir.d" \
"./Sources/jump_to_os_loop.d" \
"./Sources/pop_r7_pc.d" \
"./Sources/pop_twice.d" \
"./Sources/recover_context.d" \
"./Sources/recover_context2.d" \
"./Sources/restore_context.d" \
"./Sources/set_pc_sp.d" \
"./Sources/set_pc_sp_lr.d" \
"./Sources/set_sp.d" \
"./Sources/test.d" \
"./Sources/test2.d" \

OBJS += \
./Sources/Alarms.o \
./Sources/Mailbox.o \
./Sources/OperativeSystem.o \
./Sources/Queue.o \
./Sources/RGB.o \
./Sources/User.o \
./Sources/clean_stack_from_chaintask.o \
./Sources/finish_isr.o \
./Sources/finish_isr2.o \
./Sources/get_task_return_dir.o \
./Sources/jump_to_os_loop.o \
./Sources/main.o \
./Sources/pop_r7_pc.o \
./Sources/pop_twice.o \
./Sources/recover_context.o \
./Sources/recover_context2.o \
./Sources/restore_context.o \
./Sources/set_pc_sp.o \
./Sources/set_pc_sp_lr.o \
./Sources/set_sp.o \
./Sources/test.o \
./Sources/test2.o \

C_DEPS += \
./Sources/Alarms.d \
./Sources/Mailbox.d \
./Sources/OperativeSystem.d \
./Sources/Queue.d \
./Sources/RGB.d \
./Sources/User.d \
./Sources/main.d \

S_DEPS += \
./Sources/clean_stack_from_chaintask.d \
./Sources/finish_isr.d \
./Sources/finish_isr2.d \
./Sources/get_task_return_dir.d \
./Sources/jump_to_os_loop.d \
./Sources/pop_r7_pc.d \
./Sources/pop_twice.d \
./Sources/recover_context.d \
./Sources/recover_context2.d \
./Sources/restore_context.d \
./Sources/set_pc_sp.d \
./Sources/set_pc_sp_lr.d \
./Sources/set_sp.d \
./Sources/test.d \
./Sources/test2.d \

OBJS_QUOTED += \
"./Sources/Alarms.o" \
"./Sources/Mailbox.o" \
"./Sources/OperativeSystem.o" \
"./Sources/Queue.o" \
"./Sources/RGB.o" \
"./Sources/User.o" \
"./Sources/clean_stack_from_chaintask.o" \
"./Sources/finish_isr.o" \
"./Sources/finish_isr2.o" \
"./Sources/get_task_return_dir.o" \
"./Sources/jump_to_os_loop.o" \
"./Sources/main.o" \
"./Sources/pop_r7_pc.o" \
"./Sources/pop_twice.o" \
"./Sources/recover_context.o" \
"./Sources/recover_context2.o" \
"./Sources/restore_context.o" \
"./Sources/set_pc_sp.o" \
"./Sources/set_pc_sp_lr.o" \
"./Sources/set_sp.o" \
"./Sources/test.o" \
"./Sources/test2.o" \

C_DEPS_QUOTED += \
"./Sources/Alarms.d" \
"./Sources/Mailbox.d" \
"./Sources/OperativeSystem.d" \
"./Sources/Queue.d" \
"./Sources/RGB.d" \
"./Sources/User.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/Alarms.o \
./Sources/Mailbox.o \
./Sources/OperativeSystem.o \
./Sources/Queue.o \
./Sources/RGB.o \
./Sources/User.o \
./Sources/clean_stack_from_chaintask.o \
./Sources/finish_isr.o \
./Sources/finish_isr2.o \
./Sources/get_task_return_dir.o \
./Sources/jump_to_os_loop.o \
./Sources/main.o \
./Sources/pop_r7_pc.o \
./Sources/pop_twice.o \
./Sources/recover_context.o \
./Sources/recover_context2.o \
./Sources/restore_context.o \
./Sources/set_pc_sp.o \
./Sources/set_pc_sp_lr.o \
./Sources/set_sp.o \
./Sources/test.o \
./Sources/test2.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Alarms.o: ../Sources/Alarms.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Alarms.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Alarms.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mailbox.o: ../Sources/Mailbox.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Mailbox.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Mailbox.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/OperativeSystem.o: ../Sources/OperativeSystem.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OperativeSystem.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OperativeSystem.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Queue.o: ../Sources/Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Queue.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Queue.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/RGB.o: ../Sources/RGB.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/RGB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/RGB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/User.o: ../Sources/User.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/User.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/User.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/clean_stack_from_chaintask.o: ../Sources/clean_stack_from_chaintask.s
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/clean_stack_from_chaintask.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/clean_stack_from_chaintask.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/finish_isr.o: ../Sources/finish_isr.s
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/finish_isr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/finish_isr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/finish_isr2.o: ../Sources/finish_isr2.s
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/finish_isr2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/finish_isr2.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/get_task_return_dir.o: ../Sources/get_task_return_dir.s
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/get_task_return_dir.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/get_task_return_dir.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/jump_to_os_loop.o: ../Sources/jump_to_os_loop.s
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/jump_to_os_loop.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/jump_to_os_loop.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pop_r7_pc.o: ../Sources/pop_r7_pc.s
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pop_r7_pc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pop_r7_pc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pop_twice.o: ../Sources/pop_twice.s
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pop_twice.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pop_twice.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/recover_context.o: ../Sources/recover_context.s
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/recover_context.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/recover_context.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/recover_context2.o: ../Sources/recover_context2.s
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/recover_context2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/recover_context2.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/restore_context.o: ../Sources/restore_context.s
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/restore_context.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/restore_context.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_pc_sp.o: ../Sources/set_pc_sp.s
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_pc_sp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_pc_sp.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_pc_sp_lr.o: ../Sources/set_pc_sp_lr.s
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_pc_sp_lr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_pc_sp_lr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/set_sp.o: ../Sources/set_sp.s
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/set_sp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/set_sp.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/test.o: ../Sources/test.s
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/test.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/test.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/test2.o: ../Sources/test2.s
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/test2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/test2.o"
	@echo 'Finished building: $<'
	@echo ' '


