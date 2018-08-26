/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#define BOARD_SW_IRQ_HANDLER BOARD_SW3_IRQ_HANDLER
#define BOARD_SW3_IRQ_HANDLER PORTA_IRQHandler

void Push_Btn(void);
void Blue_Led_Init(void);
void Red_Led_Init(void);

int main(void) {
	Push_Btn();
	Blue_Led_Init();
	Red_Led_Init();
	//LPTimer
	SIM_SCGC5 |= (1 << 0); //Activate the LPTMR in the system control gating register
	LPTMR0_PSR = 0b0000101; //Bypass the preescaler and select the LPO(low power oscilator of 1Khz as the source of the timer)
	LPTMR0_CMR = 500;			//compare of 500 clock cycles = .5 secs
	LPTMR0_CSR = 0b01000001; //Activate the timer and enable interrupts	
	NVIC_ICPR(1) |= (1<<(58%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(58%32)); 		//Activate the LPTM interrupt
	while (1) {
		GPIOB_PDOR |= (0 << 21);	//Put PTB21 as HIGH
	}
	return 0;
}

void Blue_Led_Init(void) {
	//Blue LED
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = ~(1 << 21);	//Put PTB21 as HIGH
	GPIOB_PDOR = (1 << 21);	//Put PTB21 as LOW
}

void Red_Led_Init(void){
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR22 = (1<<8);	//Set PTB22 as GPIO
	GPIOB_PDDR |= (1 << 22);	//Set PTB21 as output
	GPIOB_PDOR = ~(1 << 22);	//Put PTB21 as HIGH
	GPIOB_PDOR = (1 << 22);	//Put PTB21 as LOW
}

void Push_Btn(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(61%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(61%32)); 		//Activate the LPTM interrupt
}

void LPTimer_IRQHandler() {
	LPTMR0_CSR |= (1 << 7); //Clear timer compare flag
}

void PORTC_IRQHandler() {
	PORTC_PCR6 &= ~(0<<24);
	GPIOB_PDOR |= (1 << 21);	//Put PTB21 as HIGH
}
