/*
 * OperativeSystem.c
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"
#include "User.h"
#include "OperativeSystem.h"
#include "Queue.h"
#include "shared.h"
#define __ASM __asm /*!< asm keyword for GNU Compiler */ 
#define __INLINE inline /*!< inline keyword for GNU Compiler */ 
#define __STATIC_INLINE static inline 
extern int get_r0();
extern int get_r1();
extern int get_r2();
extern int get_r3();
extern int get_r4();
extern int get_r5();
extern int get_r6();
extern int get_r7();
extern int get_r8();
extern int get_r9();
extern int get_r10();
extern int get_r11();
extern int get_r12();
extern void set_lr_sp(uint32_t lr, uint32_t sp);
extern void test();
extern void test2();

/** 
 \brief Get Link Register 
 \details Returns the current value of the Link Register (LR). 
 \return LR Register value 
 */
__attribute__( ( always_inline ))        __STATIC_INLINE uint32_t __get_LR(void) {
	register uint32_t result;

	__ASM volatile ("MOV %0, LR\n" : "=r" (result) );
	return (result);
}

register unsigned long LR_c __asm("lr");
register unsigned long r2_c __asm("r2");
register unsigned long r3_c __asm("r3");

TASK fetchTask;
TASK runningTask;
TASK nextTask;
TASK ready_arr[20];
uint32_t a;
uint32_t sp;
uint32_t context[13];

QueueType readyQueue = { 0, 0, STATIC_ALLOC, { } };
QueueType *ready_queue;

void ActivateTask(TASK task) {
	a = __get_LR();
	task.state = READY;
	//set_lr_sp(a, sp);
	//test();
	Queue_Add(ready_queue, task);
	CheckNextTask();
	RunNextTask();
}

void ActivateTaskIRQ(TASK task) {
	a = __get_LR();
}

void RunNextTask() {
	if (runningTask.id == 'X') {
		runningTask = nextTask;
	} else if (nextTask.priority > runningTask.priority) {
		runningTask.return_direction = a;
		Queue_Add(ready_queue, runningTask);
		runningTask = nextTask;
	} else {
		//Case when a task activated another task that has lower priority so the current task continues
		Queue_Add(ready_queue, nextTask);
		runningTask.return_direction = a;
		set_lr_sp(runningTask.return_direction,sp);
	}
	RunTask();
}

void ChainTask(TASK task) {
	Queue_Add(ready_queue, task);
	task.state = READY;
	TerminateTask();
}

void TerminateTask(void) {
	runningTask.state = IDLE;
	runningTask = get_empty_TASK();
	if (CheckNextTask()) {
		RunNextTask();
	}
}

int CheckNextTask(void) {
	if (TaskList_Empty(ready_queue)) {
		return 0;
	}
	Sort_TaskList(ready_queue);
	nextTask = Queue_Next(ready_queue);
	return 1;
}

void RunTask(void) {
	runningTask.state = RUNNING;
	if (runningTask.return_direction != 0) {
		set_lr_sp(runningTask.return_direction,sp);
		//set_lr(runningTask.return_direction);
	} else {
		runningTask.ap_task_init();
	}
}

void OS_init(TASK *tasks, int size) {
	ready_queue = &readyQueue;
	checkAutoStartSetReady(tasks, size);
	runningTask = get_empty_TASK();
	do {
		if (CheckNextTask()) {
			RunNextTask();
		}
	} while (1);
}

void checkAutoStartSetReady(TASK *tasks, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (tasks[i].autostart == 1) {
			tasks[i].state = READY; //si tiene autostart la tarea se va a ready
			tasks[i].autostart = 0;
			Queue_Add(ready_queue, tasks[i]);
		}
	}
}

void OS_save_context(void){
	context[2] = r2_c;
	context[3] = r3_c;
	context[0] = get_r0();
	context[1] = get_r1();
	context[4] = get_r4();
	context[5] = get_r5();
	context[6] = get_r6();
	context[7] = get_r7();
	context[8] = get_r8();
	context[9] = get_r9();
	context[10] = get_r10();
	context[11] = get_r11();
	context[12] = get_r12();
}
