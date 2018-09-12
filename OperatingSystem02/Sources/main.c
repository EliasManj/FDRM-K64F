/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "User.h"
#include "OperativeSystem.h"
#include "shared.h"
#include "Alarms.h"
#include "RGB.h"
#include "Mailbox.h"

void Push_Btn_SW2(void);
void Push_Btn_SW3(void);
void LPTimer_Init(void);
extern void set_lr(uint32_t lr);

int main(void) {
	//TASK A
	task_a.priority = 2;
	task_a.autostart = 1;
	task_a.return_direction = 0;
	task_a.state = 0;
	task_a.ap_task_init = &TASK_A;
	task_a.label = 'A';
	task_a.id = 0;
	task_a.multiplicity = 0;
	//TASK B
	task_b.priority = 3;
	task_b.autostart = 0;
	task_b.return_direction = 0;
	task_b.state = 0;
	task_b.ap_task_init = &TASK_B;
	task_b.label = 'B';
	task_b.id = 1;
	task_b.multiplicity = 0;
	//TASK_C
	task_c.priority = 4;
	task_c.autostart = 0;
	task_c.return_direction = 0;
	task_c.state = 0;
	task_c.ap_task_init = &TASK_C;
	task_c.label = 'C';
	task_c.id = 2;
	task_c.multiplicity = 0;
	//TASK_D
	task_d.priority = 1;
	task_d.autostart = 0;
	task_d.return_direction = 0;
	task_d.state = 0;
	task_d.ap_task_init = &TASK_D;
	task_d.label = 'D';
	task_d.id = 3;
	task_d.multiplicity = 0;
	//TASK_E
	task_e.priority = 0;
	task_e.autostart = 0;
	task_e.return_direction = 0;
	task_e.state = 0;
	task_e.ap_task_init = &TASK_E;
	task_e.label = 'E';
	task_e.id = 4;
	task_e.multiplicity = 0;
	//Array
	task_arr[0] = task_a;
	task_arr[1] = task_b;
	task_arr[2] = task_c;
	task_arr[3] = task_d;
	task_arr[4] = task_e;
	//Set Alarms A
	alarm_list[0].alarm_id = 0;
	alarm_list[0].count = 2;
	alarm_list[0].active = 1;
	alarm_list[0].reference = 3;
	alarm_list[0].reload = 1;
	alarm_list[0].task_id = TASK_B_ID;
	//Set Alarms B
	alarm_list[1].alarm_id = 1;
	alarm_list[1].count = 3;
	alarm_list[1].active = 1;
	alarm_list[1].reference = 4;
	alarm_list[1].reload = 0;
	alarm_list[1].task_id = TASK_D_ID;
	//Mailboxes
	CreateMailBox(0, TASK_B_ID, TASK_A_ID);
	CreateMailBox(1, TASK_A_ID, TASK_B_ID);
	CreateMailBox(2, TASK_C_ID, TASK_A_ID);
	//Interrupts
	RGB_Init();
	Push_Btn_SW2();
	Push_Btn_SW3();
	OS_init(task_arr, N_TASKS);
	return 0;
}

void Push_Btn_SW2(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(61%32));
	NVIC_ISER(1) |= (1<<(61%32));
}

void Push_Btn_SW3(void) {
	SIM_SCGC5 |= (1 << 9);
	PORTA_PCR4 |= (1<<8);
	PORTA_PCR4 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(59%32));
	NVIC_ISER(1) |= (1<<(59%32));
}

void PORTA_IRQHandler() {
	OS_save_context();
	PORTA_PCR4 &= ~(0<<24);
	RGB(0, 1, 0);
	ActivateTaskIRQ(2);
}

void PORTC_IRQHandler() {
	OS_save_context_alarm();
	PORTC_PCR6 = 0x01080100;
	//ActivateTaskIRQ(2);
	DecrementAlarmsTicks();
}

void LPTimer_IRQHandler() {
	//OS_save_context_alarm();
	LPTMR0_CSR |= (1 << 7); //Clear timer compare flag
	//DecrementAlarmsTicks();
}

void NMI_Handler() {

}

