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
#include "Alarms.h"
#define __ASM __asm /*!< asm keyword for GNU Compiler */ 
#define __INLINE inline /*!< inline keyword for GNU Compiler */ 
#define __STATIC_INLINE static inline 
extern void set_lr_sp(uint32_t lr, uint32_t sp);
extern void restore_context(uint32_t sp, uint32_t lr);
extern void test();
extern void test2();

__attribute__( ( always_inline ))              __STATIC_INLINE uint32_t __get_LR(void) {
	register uint32_t result;

	__ASM volatile ("MOV %0, LR\n" : "=r" (result) );
	return (result);
}

register unsigned long LR_c __asm("lr");

TASK task;
TASK runningTask;
TASK nextTask;
uint32_t a;
uint32_t context_lr;
uint32_t context_sp;
uint32_t sp;
uint32_t *context_pointer;

QueueType readyQueue = { 0, 0, STATIC_ALLOC, { } };
QueueType *ready_queue;

void ActivateTask(int task_id) {
	a = __get_LR();
	sp = SP_c;
	task = get_task_by_id(task_id);
	task.state = READY;
	//set_lr_sp(a, sp);
	//test();
	Queue_Add(ready_queue, task);
	CheckNextTask();
	RunNextTask();
}

void AddTaskFromAlarm(int task_id) {
	task = get_task_by_id(task_id);
	task.state = READY;
	Queue_Add(ready_queue, task);
}

void ActivateTaskIRQ(int task_id) {
	context_lr = __get_LR();
	task = get_task_by_id(task_id);
	task.state = READY;
	Queue_Add(ready_queue, task);
	if (CheckNextTask()) {
		RunNextTaskIRQ();
	}
}

void RunNextTaskIRQ(void) {
	if (runningTask.id == 'X') {
		runningTask = nextTask;
		RunTask();
	} else if (nextTask.priority > runningTask.priority) {
		runningTask.state = READY;
		runningTask.context_required = 1;
		Queue_Add(ready_queue, runningTask);
		runningTask = nextTask;
		RunTask();
	} else {
		//Case when a task activated another task that has lower priority so the current task continues
		Queue_Add(ready_queue, nextTask);
		//runningTask.return_direction = a;
	}
}

void RunNextTask() {
	if (runningTask.id == 'X') {
		runningTask = nextTask;
		RunTask();
	} else if (nextTask.priority >= runningTask.priority) {
		runningTask.return_direction = a;
		runningTask.return_sp = sp;
		runningTask.state = READY;
		Queue_Add(ready_queue, runningTask);
		runningTask = nextTask;
		RunTask();
	} else {
		//Case when a task activated another task that has lower priority so the current task continues
		Queue_Add(ready_queue, nextTask);
		//runningTask.return_direction = a;
		//set_lr_sp(runningTask.return_direction, sp);
	}

}

void ChainTask(int task_id) {
	task = get_task_by_id(task_id);
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
	if (runningTask.context_required == 1) {
		runningTask.context_required = 0;
		restore_context((uint32_t) context_pointer, context_lr);
	} else if (runningTask.return_direction != 0) {
		set_lr_sp(runningTask.return_direction, runningTask.return_sp);
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

TASK get_task_by_id(int task_id) {
	return task_arr[task_id];
}

void OS_save_context(void) {
	context_sp = SP_c;
	context_sp += 0x04;
	context_pointer = (uint32_t*) context_sp;
}

void getRunningTask(TASK task){
	task = runningTask;
}
