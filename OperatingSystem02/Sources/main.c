/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "User.h"
#include "OperativeSystem.h"
#include "shared.h"
#include "Alarms.h"
#define BOARD_SW_IRQ_HANDLER BOARD_SW3_IRQ_HANDLER
#define BOARD_SW3_IRQ_HANDLER PORTA_IRQHandler

void TASK_A(void);
void TASK_B(void);
void TASK_C(void);
void TASK_D(void);
void Push_Btn(void);

int main(void) {
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
	//Set Alarms A
	alarm_a.alarm_id = 0;
	alarm_a.count = 3;
	alarm_a.active = 1;
	alarm_a.reference = 3;
	alarm_a.reload = 1;
	alarm_a.task_id = 1;
	alarm_list[0] = alarm_a;
	//Set Alarms B
	alarm_b.alarm_id = 1;
	alarm_b.count = 4;
	alarm_b.active = 1;
	alarm_b.reference = 4;
	alarm_b.reload = 1;
	alarm_b.task_id = 1;
	alarm_list[1] = alarm_b;
	//Interrupts
	Push_Btn();
	OS_init(task_arr, 3);
	return 0;
}

void Push_Btn(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(61%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(61%32)); 		//Activate the LPTM interrupt
}

void PORTC_IRQHandler() {
	OS_save_context();
	PORTC_PCR6 = 0x01080100;
	DecrementAlarmsTicks();
	//ActivateTaskIRQ(2);
}
