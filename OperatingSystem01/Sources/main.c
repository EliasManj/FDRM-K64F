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

int main(void){
	//Pointer
	void (*task_a_pointer)(void) = &TASK_A;
	//void (*task_b_pointer)(void) = &TASK_B;
	//void (*task_c_pointer)(void) = &TASK_C;
	//TASK A
	TASK task_a;
	task_a.priority = 0;
	task_a.autostart = 1;
	task_a.return_direction = 255;
	task_a.state = 0;
	task_a.ap_task_init = 12;
	//TASK B
	TASK task_b;
	task_b.priority = 1;
	task_b.autostart = 0;
	task_b.return_direction = 255;
	task_b.state = 0;
	task_b.ap_task_init = 0;
	//TASK_C
	TASK task_c;
	task_c.priority = 2;
	task_c.autostart = 0;
	task_c.return_direction = 255;
	task_c.state = 0;
	task_c.ap_task_init = 0;
	//Array
	TASK task_arr[10];
	task_arr[0] = task_a;
	task_arr[1] = task_b;
	task_arr[2] = task_c;
	OS_init(task_arr, 3);
	return 0;
}

void TASK_A(void){
	
}

void TASK_B(void){
	
}

void TASK_C(void){
	
}
