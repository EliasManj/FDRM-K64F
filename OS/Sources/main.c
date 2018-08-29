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

void LPTimer_Init(void);
void Push_Btn_SW2(void);
void Push_Btn_SW3(void);

int main(void) {
	RGB_Init();
	Push_Btn_SW2();
	Push_Btn_SW3();
	LPTimer_Init();
	return 0;
}

void LPTimer_Init(void) {
	//LPTimer
	SIM_SCGC5 |= (1 << 0); //Activate the LPTMR in the system control gating register
	LPTMR0_PSR = 0b0000101; //Bypass the preescaler and select the LPO(low power oscilator of 1Khz as the source of the timer)
	LPTMR0_CMR = 500;			//compare of 500 clock cycles = .5 secs
	LPTMR0_CSR = 0b01000001; //Activate the timer and enable interrupts	
	NVIC_ICPR(1) |= (1<<(58%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(58%32));		//Activate the LPTM interrupt
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

void LPTimer_IRQHandler() {
	DecrementAlarmsTicks();
	LPTMR0_CSR |= (1 << 7); //Clear timer compare flag
}

void PORTC_IRQHandler() {
	OS_save_context();
	PORTC_PCR6 = 0x01080100;
	RGB(1, 0, 0);
	//ActivateTaskIRQ(2);
}

void NMI_Handler() {

}

void PORTA_IRQHandler() {
	PORTA_PCR4 &= ~(0<<24);
	RGB(0,1,0);
}
