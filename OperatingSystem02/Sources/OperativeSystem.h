/*
 * OperativeSystem.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */

#ifndef OPERATIVESYSTEM_H_
#define OPERATIVESYSTEM_H_

#include "derivative.h"

typedef struct {
	volatile uint8_t priority;
	volatile uint8_t autostart;
	volatile uint32_t return_direction;
	volatile uint32_t return_sp;
	volatile char label;
	volatile uint32_t id;
	void (*ap_task_init)(void);
	volatile uint8_t state; //STATE 0:IDLE 1:READY 2:RUNNING 3:WAIT
	volatile uint8_t context_required;
	volatile uint8_t multiplicity;
} TASK;

uint32_t *context_pointer;
uint32_t *alarm_task_context_pointer;
uint32_t os_loop_sp;
uint32_t os_loop_pc;
uint32_t task_incomplete_rd;
uint32_t context_lr;
uint32_t context_sp;
uint32_t alarm_task_context_sp;
uint32_t sp;
uint32_t alarm_task_context_sp_addr;
uint32_t *interrupted_task_sp_pointer;
uint32_t interrupted_task_sp_addr;
uint8_t start;

register unsigned long PC_c __asm("pc");
register unsigned long LR_c __asm("lr");

void ActivateTask(int task_id);
void ChainTask(int task_id);
void TerminateTask();
void OS_init(TASK *tasks, int size);
TASK checkHighestPriority(TASK *tasks, int size);
void checkAutoStartSetReady(TASK *tasks, int size);
void RunTask(void);
int CheckNextTask(void);
void RunNextTask(void);
TASK getTask(int id);
void OS_save_context(void);
TASK get_task_by_id(int task_id);
void RunNextTaskIRQ(void);
void ActivateTaskIRQ(int task_id);
void AddTaskFromAlarm(int task_id);
void MailboxWrite(uint32_t mailbox_id, uint32_t data);
void MailboxRead(uint32_t mailbox_id);
int32_t getRunningTaskID(void);
void LPTimer_Init(void);
void Interrupt_Enable(void);
void Interrupt_Disable(void);
void OS_loop(void);
void OS_save_context_alarm(void);
extern void jump_to_os_loop(uint32_t pc, uint32_t);
extern void pop_twice();
extern void clean_stack_from_chaintask();
extern uint32_t recover_context(uint32_t interrumped_task_sp, uint32_t memory_addr);
void RunNextTaskAlarm(void);

#define OS_save_context_alarm(void) {\
	task_incomplete_rd = LR_c;\
	alarm_task_context_sp = SP_c;\
	interrupted_task_sp_addr = alarm_task_context_sp;\
	interrupted_task_sp_pointer = (uint32_t*)interrupted_task_sp_addr;\
	sp = *interrupted_task_sp_pointer;\
	context_sp = alarm_task_context_sp;\
	alarm_task_context_pointer = (uint32_t*) alarm_task_context_sp;\
}\

#endif /* OPERATIVESYSTEM_H_ */
