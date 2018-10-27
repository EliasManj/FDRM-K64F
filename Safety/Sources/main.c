/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
/*  ClockOutput options */
#define CLOCKOUT_FLASH_CLOCK    2
#define CLOCKOUT_LPO			3 //Low Power Clock 1KHz
#define CLOCKOUT_MCGIRC         4 //Internal reference clock
#define CLOCKOUT_RTC32KHZ       5 //RTC32KHz	
#define CLOCKOUT_OSCERCLK0      6 //External reference clock
void MCGIRC(void);
void RTC32KHZ(void);
void OSCERCLK(void);
void CLK_Monitor_Enable(void);

int main(void) {
	/* Configure PTC3 as clock output) */
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR3 |= (5<<8);
	OSCERCLK();
	/* Configure clock output option according to  */SIM_SOPT2 =
			SIM_SOPT2_CLKOUTSEL(CLOCKOUT_OSCERCLK0);
	return 0;
}

void OSCERCLK(void) {
	OSC_CR = (1 << 7);
}

void MCGIRC(void) {
	MCG_C1 |= (1 << 2);
	MCG_C2 |= (1 << 0);
}

void RTC32KHZ(void) {
	SIM_SOPT1 |= (2 << 18);
	RTC_CR |= (1 << 8);
}

void CLK_Monitor_Enable(void) {
	MCG_C6 |= (1 << 5);
}
