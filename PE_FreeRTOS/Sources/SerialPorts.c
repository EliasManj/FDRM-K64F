#include "SerialPorts.h"
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

void serial0_Init(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1 << 8);
	PORTC_PCR6 |= (8 << 16);
	NVIC_ICPR(1) |= (1 << (61 % 32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1 << (61 % 32)); 		//Activate the LPTM interrupt
}

void serial1_Init(void) {

}

void serial2_Init(void) {

}

void serial3_Init(void) {

}
