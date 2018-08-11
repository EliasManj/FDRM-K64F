/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */



int main(void)
{
	//LED
	SIM_SCGC5 |= (1<<10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1<<21);	//Set PTB21 as output
	GPIOB_PDOR = ~(1<<21);	//Put PTB21 as HIGH
	//LPTimer
	SIM_SCGC5 |= (1<<0);
	LPTMR0_PSR |= (1<<2);
	LPTMR0_PSR |= (1<<0);
	LPTMR0_CMR = 500;
	LPTMR0_CSR |=  0b01000001;;
	NVICICPR1 |= 1023;		//Clean flag of LPTM in the interrupt vector
	NVICISER1 |= 1023; 		//Activate the LPTM interrupt
	return 0;
}

void LPTimer_IRQHandler(){
	LPTMR0_CSR |= (1 << 7); //Clear timer compare flag
	GPIOB_PDOR ^= (1<<21);	//Put PTB21 as HIGH
}
