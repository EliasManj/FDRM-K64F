/*
 * User.c
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */

#include <stdio.h>              //including stdio.h for printf and other functions
#include "derivative.h" /* include peripheral declarations */
#include "OperativeSystem.h"
#include "User.h"
#include "shared.h"
#include "RGB.h"
#include "Mailbox.h"

int hey;

void TASK_A(void) {
	int a;
	a = 0xAAAAAAAA;
	RGB(1, 0, 1);
	RGB(1, 1, 1);
	RGB(1, 0, 1);
	WriteToMailbox(0, a);
	WriteToMailbox(1, 0xCCCCCCCC);
	ActivateTask(TASK_B_ID);
	RGB(1, 1, 0);
	TerminateTask();
}

void TASK_B(void) {
	RGB(1, 0, 0);
	//ActivateTask(TASK_D_ID);
	RGB(0, 1, 0);
	RGB(1, 1, 0);
	RGB(0, 1, 1);
	RGB(0, 0, 0);
	//uint32_t x;
	//uint32_t *pt;
	//pt = &x;
	//ReadFromMailbox(0, pt);
	//ReadFromMailbox(1, pt);
	//TerminateTask();
	ChainTask(TASK_C_ID);
}

void TASK_C(void) {
	int i;
	int counter = 0;
	uint32_t x;
	uint32_t *pt;
	pt = &x;
	ReadFromMailbox(1, pt);
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = (1 << 21);	//Put PTB21 as HIGH
	for (i = 0; i < 5; i++) {
		//for (counter; counter <= 0; counter++)
		;
		GPIOB_PDOR ^= (1 << 21);	//Put PTB21 as HIGH
		counter = 0;
	}
	TerminateTask();
}

void TASK_D(void) {
	RGB(0, 1, 0);
	RGB(0, 0, 1);
	RGB(1, 0, 0);
	RGB(1, 1, 0);
	RGB(0, 1, 1);
	RGB(1, 0, 1);
	WriteToMailbox(2, 0xDDDDDDDD);
	hey = 2;
	TerminateTask();
}

void TASK_E(void) {
	uint32_t x;
	uint32_t *pt;
	if (hey-- <= 0) {
		pt = &x;
		ReadFromMailbox(2, pt);
		RGB(1, 1, 0);
		RGB(1, 1, 1);
		RGB(0, 0, 1);
	} else {
		ActivateTask(TASK_E_ID);
	}
	TerminateTask();
}
