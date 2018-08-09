/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */



int main(void)
{
	SIM_SCGC5 |= (1<<10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1<<21);	//Set PTB21 as output
	GPIOB_PDOR = ~(1<<21);	//Put PTB21 as HIGH
	
	return 0;
}
