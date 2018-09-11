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
extern void set_pc_sp(uint32_t lr, uint32_t sp);
extern void restore_context(uint32_t sp, uint32_t lr);
extern void test();
extern void test2();

__attribute__( ( always_inline ))             __STATIC_INLINE uint32_t __get_LR(void) {
	register uint32_t result;

	__ASM volatile ("MOV %0, LR\n" : "=r" (result) );
	return (result);
}

TASK task;
TASK runningTask;
TASK nextTask;
uint8_t interrupts_enabled;

QueueType readyQueue = { 0, 0, STATIC_ALLOC, { } };
QueueType *ready_queue;
QueueType waitQueue = { 0, 0, STATIC_ALLOC, { } };
QueueType *wait_queue;

void ActivateTask(int task_id) {
	task_incomplete_rd = __get_LR();
	Interrupt_Disable();
	sp = SP_c;
	task = get_task_by_id(task_id);
	task.state = READY;
	if (runningTask.id == task.id) {
		task.multiplicity = runningTask.multiplicity + 1;
	}
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

void RunNextTask() {
	if (runningTask.label == 'X') {
		runningTask = nextTask;
		RunTask();
	} else if (nextTask.priority >= runningTask.priority) {
		runningTask.return_direction = task_incomplete_rd;
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
	Interrupt_Disable();
	task = get_task_by_id(task_id);
	Queue_Add(ready_queue, task);
	task.state = READY;
	TerminateTask();
}

void TerminateTask(void) {
	Interrupt_Disable();
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
		Interrupt_Enable();
		restore_context((uint32_t) context_pointer, context_lr);
	} else if (runningTask.return_direction != 0) {
		Interrupt_Enable();
		set_pc_sp(runningTask.return_direction, runningTask.return_sp);
	} else {
		Interrupt_Enable();
		runningTask.ap_task_init();
	}
}

void OS_init(TASK *tasks, int size) {
	ready_queue = &readyQueue;
	wait_queue = &waitQueue;
	interrupts_enabled = 0;
	checkAutoStartSetReady(tasks, size);
	runningTask = get_empty_TASK();
	//Alarms_Disable();
	LPTimer_Init();
	RunNextTaskAlarm();
	start = 1;
	OS_loop();
}

void OS_loop(void) {
	os_loop_sp = SP_c;
	os_loop_pc = PC_c;
	do {
		if (CheckNextTask()) {
			RunNextTask();
		} else {
			Interrupt_Enable();
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

void Interrupt_Disable(void) {
	if (interrupts_enabled == 1) {
		NVIC_ICER(1) |= 0xFFFFFFFF;
		interrupts_enabled = 0;
	}
}

void Interrupt_Enable(void) {
	if (interrupts_enabled == 0) {
		NVIC_ISER(1) |= (1<<(61%32));
		NVIC_ISER(1) |= (1<<(59%32));
		NVIC_ISER(1) |= (1<<(58%32));		//Activate the LPTM interrupt
		interrupts_enabled = 1;
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

int32_t getRunningTaskID() {
	return runningTask.id;
}

void LPTimer_Init(void) {
//LPTimer
	SIM_SCGC5 |= (1 << 0); //Activate the LPTMR in the system control gating register
	LPTMR0_PSR = 0b0000101; //Bypass the preescaler and select the LPO(low power oscilator of 1Khz as the source of the timer)
	LPTMR0_CMR = 500;			//compare of 1000 clock cycles = 1 secs
	LPTMR0_CSR = 0b01000001; //Activate the timer and enable interrupts	
	NVIC_ICPR(1) |= (1<<(58%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(58%32));		//Activate the LPTM interrupt
}

void RunNextTaskAlarm(void) {
	if (!start) {
		alarm_return_lr = PC_c - 0x18;
	} else {
		task_incomplete_rd = recover_context2(alarm_task_context_sp,
				interrumped_task_lr_addr, interrupted_task_sp_addr);
		if (CheckNextTask()) {
			if (runningTask.label == 'X') {
				runningTask = nextTask;
				RunTask();
			} else if (nextTask.priority >= runningTask.priority) {
				runningTask.return_direction = task_incomplete_rd + 1;
				runningTask.return_sp = interrupted_task_sp_addr - 0x50;
				runningTask.state = READY;
				Queue_Add(ready_queue, runningTask);
				runningTask = nextTask;
				RunTask();
			} else {
				Queue_Add(ready_queue, nextTask);
				runningTask.return_direction = task_incomplete_rd + 1;
				runningTask.return_sp = interrupted_task_sp_addr - 0x50;
				RunTask();
			}
		}
	}
}

void RunNextTaskIRQ(void) {
	if (runningTask.label == 'X') {
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

void move_current_task_to_wait(void) {
	runningTask.return_direction = task_incomplete_rd-2;
	runningTask.return_sp = sp;
	runningTask.state = WAIT;
	Queue_Add(wait_queue, runningTask);
	runningTask = get_empty_TASK();
	while (!CheckNextTask()) {
		if (interrupts_enabled == 0) {
			NVIC_ISER(1) |= (1<<(61%32));
			NVIC_ISER(1) |= (1<<(59%32));
			NVIC_ISER(1) |= (1<<(58%32));		//Activate the LPTM interrupt
			interrupts_enabled = 1;
		}
	}
	RunNextTask();
}

void move_waiting_task_to_ready(uint32_t consumer_id) {
	if (!TaskList_Empty(wait_queue)) {
		Sort_TaskList(wait_queue);
		Queue_Search(wait_queue, consumer_id);
		nextTask = Queue_Next(wait_queue);
		RunNextTask();
	}
}
