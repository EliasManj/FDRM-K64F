/*
 * User.c
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */

#include <stdio.h>              //including stdio.h for printf and other functions
#include "derivative.h" /* include peripheral declarations */
#include "OperativeSystem.h"
#include "shared.h"

void TASK_A(void) {
	int a;
	int b;
	int c;
	a = 0xAAAAAAAA;
	b = 0xBBBBBBBB;
	Push_Btn();
	c = 0xCCCCCCCC;
	ActivateTask(1);
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = (1 << 21);	//Put PTB21 as HIGH
	TerminateTask();
}

void TASK_B(void) {
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	//ActivateTask(0);
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = ~(1 << 21);	//Put PTB21 as HIGH
	TerminateTask();
	//ChainTask(2);
}

void TASK_C(void) {
	int i;
	//int counter = 0;
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = (1 << 21);	//Put PTB21 as HIGH
	for (i = 0; i < 5; i++) {
		//for(counter; counter <= 0; counter++);
		GPIOB_PDOR ^= (1 << 21);	//Put PTB21 as HIGH
		//counter = 0;
	}
	TerminateTask();
}
