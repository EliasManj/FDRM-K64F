#include "SerialPorts.h"
#include "IO_Map.h"
/*
 * SERIAL0 OUT PTC5
 * SERIAL0 RX  PTC7
 * 
 * SERIAL1 OUT PTC0
 * SERIAL1 RX  PTC9
 * 
 * SERIAL2 OUT PTC8
 * SERIAL2 RX  PTC1
 * 
 * SERIAL3 OUT PTC3
 * SERIAL3 RX  PTC2
 */
void setGPIO_PortC(void){
	SIM_SCGC5 |= (1 << 11);	//Activate clock of port C
	PORTC_PCR5 = (1<<8);	//Set PTC5 as GPIO
	PORTC_PCR0 = (1<<8);	//Set PTC0 as GPIO
	PORTC_PCR8 = (1<<8);	//Set PTC8 as GPIO
	PORTC_PCR3 = (1<<8);	//Set PTC3 as GPIO
	GPIOC_PDDR |= (1 << 5);	//Set PTC5 as output
	GPIOC_PDDR |= (1 << 0);	//Set PTC0 as output
	GPIOC_PDDR |= (1 << 8);	//Set PTC8 as output
	GPIOC_PDDR |= (1 << 3);	//Set PTC3 as output
}

void serial0_Init(void) {
	PORTC_PCR7 |= (1 << 8);
	PORTC_PCR7 |= (8 << 16);
}

void serial1_Init(void) {
	PORTC_PCR9 |= (1 << 8);
	PORTC_PCR9 |= (8 << 16);
}

void serial2_Init(void) {
	PORTC_PCR1 |= (1 << 8);
	PORTC_PCR1 |= (8 << 16);
}

void serial3_Init(void) {
	PORTC_PCR2 |= (1 << 8);
	PORTC_PCR2 |= (8 << 16);
}

void portC_Init(void) {
	NVIC_ICPR(1) |= (1 << (61 % 32)); //Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1 << (61 % 32)); 		//Activate the LPTM interrupt
	SIM_SCGC5 |= (1 << 11);
}

void Push_Btn_SW2(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(61%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(61%32)); 		//Activate the LPTM interrupt
}

