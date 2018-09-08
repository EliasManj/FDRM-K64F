/*
 * User.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"
#include "OperativeSystem.h"

#ifndef USER_H_
#define USER_H_

#define IDLE 0
#define READY 1
#define RUNNING 2
#define WAIT 3

#define TASK_A_ID 0
#define TASK_B_ID 1
#define TASK_C_ID 2
#define TASK_D_ID 3
#define TASK_E_ID 4
#define N_TASKS 5

void TASK_A(void);
void TASK_B(void);
void TASK_C(void);
void TASK_D(void);
void TASK_E(void);

TASK task_arr[10];
TASK task_a;
TASK task_b;
TASK task_c;
TASK task_d;
TASK task_e;

#endif /* USER_H_ */
