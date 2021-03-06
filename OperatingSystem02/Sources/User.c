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
	RGB(1, 0, 1);
	RGB(1, 1, 1);
	RGB(1, 0, 1);
	uint32_t x;
	uint32_t *pt;
	pt = &x;
	//go to wait
	ReadFromMailbox(1, pt);
	RGB(1, 0, 0);
	RGB(1, 1, 0);
	TerminateTask();
}

void TASK_B(void) {
	int a;
	uint32_t x;
	uint32_t *pt;
	pt = &x;
	a = 0xAAAAAAAA;
	RGB(1, 0, 0);
	WriteToMailbox(1, 0xCCCCCCCC);
	RGB(0, 1, 0);
	RGB(1, 1, 0);
	RGB(0, 1, 1);
	RGB(0, 0, 0);
	WriteToMailbox(2, 0x22222222);
	WriteToMailbox(2, 0x44444444);
	//b goes tow ait
	TerminateTask();
	//ChainTask(TASK_C_ID);
}

void TASK_C(void) {
	int i;
	uint32_t x;
	uint32_t *pt;
	pt = &x;
	ReadFromMailbox(2, pt);
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = (1 << 21);	//Put PTB21 as HIGH
	for (i = 0; i < 5; i++) {
		GPIOB_PDOR ^= (1 << 21);	//Put PTB21 as HIGH
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
	WriteToMailbox(0, 0xDDDDDDDD);
	hey = 2;
	TerminateTask();
	//ChainTask(TASK_E_ID);
}

void TASK_E(void) {
	uint32_t x;
	uint32_t *pt;
	pt = &x;
	ReadFromMailbox(0, pt);
	/*if (hey-- <= 0) {
		pt = &x;
		ReadFromMailbox(2, pt);
		RGB(1, 1, 0);
		RGB(1, 1, 1);
		RGB(0, 0, 1);
	} else {
		ActivateTask(TASK_E_ID);
	}*/
	TerminateTask();
}
