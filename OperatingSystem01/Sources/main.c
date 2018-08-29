/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "User.h"
#include "OperativeSystem.h"
#include "shared.h"
#define BOARD_SW_IRQ_HANDLER BOARD_SW3_IRQ_HANDLER
#define BOARD_SW3_IRQ_HANDLER PORTA_IRQHandler

void TASK_A(void);
void TASK_B(void);
void TASK_C(void);
void TASK_D(void);
void Push_Btn_SW2(void);

int main(void) {
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
	Push_Btn_SW2();
	OS_init(task_arr, 3);
	return 0;
}

void Push_Btn_SW2(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(61%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(61%32)); 		//Activate the LPTM interrupt
}

void PORTC_IRQHandler() {
	//OS_save_context();
	asm volatile
	(
			"pop {r1, r2}\n\t"
	);
	PORTC_PCR6 &= (0<<24);
	GPIOB_PDOR |= (1 << 21);	//Put PTB21 as HIGH
	ActivateTaskIRQ(task_b);
}
