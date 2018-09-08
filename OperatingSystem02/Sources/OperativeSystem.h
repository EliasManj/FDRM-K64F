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

#endif /* OPERATIVESYSTEM_H_ */
