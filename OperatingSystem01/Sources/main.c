/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "User.h"
#include "OperativeSystem.h"


void TASK_A(void);
void TASK_B(void);
void TASK_C(void);
extern int myadd(int a, int b);

TASK task_arr[10];
TASK task_a;
TASK task_b;
TASK task_c;

int main(void){
	//Pointer
	//void (*task_a_pointer)(void) = &TASK_A;
	//void (*task_b_pointer)(void) = &TASK_B;
	//void (*task_c_pointer)(void) = &TASK_C;
	//TASK A
	task_a.priority = 0;
	task_a.autostart = 1;
	task_a.return_direction = 0;
	task_a.state = 0;
	task_a.ap_task_init = &TASK_A;
	task_a.id = 'A';
	//TASK B
	task_b.priority = 1;
	task_b.autostart = 0;
	task_b.return_direction = 0;
	task_b.state = 0;
	task_b.ap_task_init = &TASK_B;
	task_b.id = 'B';
	//TASK_C
	task_c.priority = 2;
	task_c.autostart = 0;
	task_c.return_direction = 0;
	task_c.state = 0;
	task_c.ap_task_init = &TASK_C;
	task_c.id = 'C';
	//Array
	task_arr[0] = task_a;
	task_arr[1] = task_b;
	task_arr[2] = task_c;
	OS_init(task_arr, 3);
	return 0;
}

void TASK_A(void){
	ActivateTask(task_b);
	SIM_SCGC5 |= (1<<10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1<<21);	//Set PTB21 as output
	GPIOB_PDOR = ~(1<<21);	//Put PTB21 as HIGH
	TerminateTask();
}

void TASK_B(void){
	SIM_SCGC5 |= (1<<10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1<<21);	//Set PTB21 as output
	GPIOB_PDOR = (1<<21);	//Put PTB21 as HIGH
	ChainTask(task_c);
}

void TASK_C(void){
	int i;
	int counter = 0;
	SIM_SCGC5 |= (1<<10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1<<21);	//Set PTB21 as output
	GPIOB_PDOR = (1<<21);	//Put PTB21 as HIGH
	for(i = 0; i<5; i++){
		for(counter; counter <= 1000000; counter++);
			GPIOB_PDOR ^= (1<<21);	//Put PTB21 as HIGH
			counter = 0;
	}
	TerminateTask();
}
