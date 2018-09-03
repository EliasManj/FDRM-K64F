/*
 * OperativeSystem.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */

#ifndef OPERATIVESYSTEM_H_
#define OPERATIVESYSTEM_H_

#include "derivative.h"
#include "User.h"

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
void getRunningTask(TASK task);


#endif /* OPERATIVESYSTEM_H_ */
