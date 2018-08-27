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

void ActivateTask(TASK task);
void ChainTask(TASK task);
void TerminateTask();
void OS_init(TASK *tasks, int size);
TASK checkHighestPriority(TASK *tasks, int size);
void checkAutoStartSetReady(TASK *tasks, int size);
void RunTask(void);
int CheckNextTask(void);
void RunNextTask(void);
TASK getTask(int id);
void OS_save_context(void);




#endif /* OPERATIVESYSTEM_H_ */
