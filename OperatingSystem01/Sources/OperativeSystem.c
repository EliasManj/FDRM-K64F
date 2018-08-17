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
#define __ASM __asm /*!< asm keyword for GNU Compiler */ 
#define __INLINE inline /*!< inline keyword for GNU Compiler */ 
#define __STATIC_INLINE static inline 
extern int set_lr(uint32_t a);

/** 
 \brief Get Link Register 
 \details Returns the current value of the Link Register (LR). 
 \return LR Register value 
 */
__attribute__( ( always_inline ))  __STATIC_INLINE uint32_t __get_LR(void) {
	register uint32_t result;

	__ASM volatile ("MOV %0, LR\n" : "=r" (result) );
	return (result);
}

__attribute__( ( always_inline ))  __STATIC_INLINE void __set_LR(int value) {
	__ASM volatile ("MOV LR, [LR]");
}

TASK runningTask;
TASK nextTask;
TASK ready_arr[20];
uint32_t a;

QueueType readyQueue = { 0, 0, STATIC_ALLOC, { } };
QueueType *ready_queue;

void ActivateTask(TASK task) {
	task.state = READY;
	Queue_Add(ready_queue, task);
	CheckNextTask();
	RunNextTask();
}

void RunNextTask(){
	if (nextTask.priority > runningTask.priority) {
			runningTask.return_direction = a;
			runningTask = nextTask;
			RunTask();
		}
}

void ChainTask(TASK task) {
	Queue_Add(ready_queue, task);
	TerminateTask();
	ActivateTask(task);
}

void TerminateTask(void) {
	runningTask.state = IDLE;
	runningTask = get_empty_TASK();
	if(CheckNextTask()){
		RunTask();
	}	
}

int CheckNextTask(void){
	if(TaskList_Empty(ready_queue)){
		return 0;
	}
	Sort_TaskList(ready_queue);
	nextTask = Queue_Next(ready_queue);
	return 1;
}

void RunTask(void) {
	runningTask.state = RUNNING;
	if (runningTask.return_direction != 0) {
		set_lr(runningTask.return_direction);
	} else {
 		runningTask.ap_task_init();
	}
}

void OS_init(TASK *tasks, int size) {
	ready_queue = &readyQueue;
	checkAutoStartSetReady(tasks, size);
	Sort_TaskList(ready_queue);
	runningTask = Queue_Next(ready_queue);
	RunTask();
}

void checkAutoStartSetReady(TASK *tasks, int size) {
	int count = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (tasks[i].autostart == 1) {
			tasks[i].state = READY; //si tiene autostart la tarea se va a ready
			tasks[i].autostart = 0;
		}
		if (tasks[i].state == READY) {
			Queue_Add(ready_queue, tasks[i]);
			count++;
		}
	}
}
