/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */

//optimizador, hace buen codigo cuando uno escribe burradas.
//
#include <stdbool.h>
#define SUBMIT 0
#define READY 1
#define RUN 2
#define WAIT 3

struct task {
	unsigned char PID;
	unsigned char priority;
	unsigned char state;
	int autoStart;
	int isSuspended;
	void (*initMemPointer)(void);
	unsigned long *susMemPointer;  //Suspended memory pointer
};

struct alarm {
	unsigned char AID;
	unsigned int ticks;
	unsigned int tickCounter;
	unsigned char activatePID;
	int repeats;
	int isEnabled;
};

#define NUM_PROCESSES 3
#define NUM_ALARMS 2

struct task processes[NUM_PROCESSES];
struct alarm alarms[NUM_ALARMS];

unsigned char a = 0;
unsigned char CurrPID;

void taskA(void);
void taskB(void);
void taskC(void);
void SO_init(void);
void SO_scheduler(void);

//Interrupts

void CY_ISR( BUTTON_INT) {
	button_ClearInterrupt();
	processes[0].state = READY;
}

//Operating System
void SO_activate_task(unsigned char pid) {

	//housekeeping 
	processes[CurrPID].isSuspended = 1;
	//save current return address
	asm volatile
	(
			"pop {r1, r2}\n\t"
			"pop {r1, r2}\n\t"
			"mov r2,%0"
			:"=r" (processes[CurrPID].susMemPointer)
	);
	//activate specified pid
	processes[pid].state = READY;

	//go back to scheduler
	asm volatile
	(
			"pop {r1, pc}\n\t"
	);

}

void SO_terminate_task(void) {

	asm volatile
	(
			"pop {r1, r2}\n\t"
	);
	//terminate current process
	processes[CurrPID].state = SUBMIT;

	//go back to scheduler
	asm volatile
	(
			"pop {r1, pc}\n\t"
	);
}

void SO_chain_task(unsigned char pid) {
	processes[pid].state = READY;

	asm volatile
	(
			"pop {r1, r2}\n\t"
			"pop {r1, r2}\n\t"
	);
	//terminate current process
	processes[CurrPID].state = SUBMIT;
	//activate chained pid

	//go back to scheduler
	asm volatile
	(
			"pop {r1, pc}\n\t"
	);
}

void SO_scheduler(void) {
	do {
		unsigned char i;
		struct task *runProc;
		int firstProc = 1;
		int procReady = 0;
		for (i = 0; i < NUM_PROCESSES; i++) {
			if (processes[i].state == READY) {
				if (firstProc) {
					runProc = &processes[i];
					firstProc = 0;
				} else if (processes[i].priority <= runProc->priority) {
					runProc = &processes[i];
				}
				CurrPID = runProc->PID;
				procReady = 1;
			}
		}

		if (procReady) //Execute highest priority
		{
			if (runProc->isSuspended) {
				runProc->isSuspended = 0;
				asm volatile(
						"mov r6, pc\n\t"
						"add r6, r6, #5\n\t"
						"push {r5, r6}\n\t"
						"blx %0"
						:: "r" (runProc->susMemPointer)
				);
			} else {
				asm volatile("blx %0" :: "r" (runProc->initMemPointer));
			}

		} else {
			//do nothing
		}
	} while (1);
}

//user
void taskA(void) {
	do {
		a += 1;
	} while (a != 0);
	SO_activate_task(1);
	//aqui deberia regresar
	do {
		a += 1;
	} while (a != 0);

	SO_terminate_task();
}

void taskB(void) {

	do {
		a += 1;
	} while (a != 0);

	SO_chain_task(2);
}

void taskC(void) {

	SO_terminate_task();
}

int main(void) {
	SO_init();
	SO_scheduler();

	for (;;) {
	}
}

void SO_init(void) {
	processes[0].PID = 0;
	processes[0].priority = 2;
	processes[0].state = SUBMIT;
	processes[0].autoStart = 1;
	processes[0].isSuspended = 0;
	processes[0].initMemPointer = &taskA;
	processes[0].susMemPointer = 0;

	processes[1].PID = 1;
	processes[1].priority = 1;
	processes[1].state = SUBMIT;
	processes[1].autoStart = 0;
	processes[1].isSuspended = 0;
	processes[1].initMemPointer = &taskB;
	processes[1].susMemPointer = 0;

	processes[2].PID = 2;
	processes[2].priority = 0;
	processes[2].state = SUBMIT;
	processes[2].autoStart = 0;
	processes[2].isSuspended = 0;
	processes[2].initMemPointer = &taskC;
	processes[2].susMemPointer = 0;

	alarms[0].AID = 0;
	alarms[0].isEnabled = 1;
	alarms[0].repeats = 0;
	alarms[0].activatePID = 2;
	alarms[0].ticks = 6;
	alarms[0].tickCounter = 6;

	alarms[1].AID = 1;
	alarms[1].isEnabled = 0;
	alarms[1].repeats = 0;
	alarms[1].activatePID = 0;
	alarms[1].ticks = 0;
	alarms[1].tickCounter = 0;

	int i;
	for (i = 0; i < NUM_PROCESSES; i++) {
		if (processes[i].autoStart) {
			processes[i].state = READY;
		}
	}
}
/* [] END OF FILE */
