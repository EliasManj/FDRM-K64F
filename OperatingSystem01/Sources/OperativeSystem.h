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
void OS_init(volatile TASK *tasks, int size);
TASK checkHighestPriority(TASK *tasks, int size);




#endif /* OPERATIVESYSTEM_H_ */
