#include "PWM_timers.h"
#include "RGB.h"
#include "SerialPorts.h"

void setGPIO_PortC(void) {
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

void timers_Init(void) {

	TimerHandle_t xTimer0;
	duty_cycle0 = 50;
	duty_cycle1 = 75;
	duty_cycle2 = 25;
	duty_cycle3 = 40;

	xTimer0 = xTimerCreate("PWMs", 10, 1, (void *) 0, vTimerCallback0);
	if (xTimer0 != NULL) {
		xTimerStart( xTimer0, 0);
	}

}

void vTimerCallback0(TimerHandle_t xTimer) {
	uint32_t ulCount;
	ulCount = (uint32_t) pvTimerGetTimerID(xTimer);
	ulCount++;
	if (ulCount >= 100) {
		ulCount = 0;
	}
	//PWM0 -> PTC5
	if (ulCount <= duty_cycle0) {
		RGB(1,0,0);
		GPIOC_PDOR ^= (-(1) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as HIGH
	} else {
		RGB(0,0,0);
		GPIOC_PDOR ^= (-(0) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as LOW
	}
	//PWM1 -> PTC0
	if (ulCount <= duty_cycle1) {
		GPIOC_PDOR ^= (-(1) ^ GPIOC_PDOR ) & (1 << 0); //Put PTC0 as HIGH
	} else {
		GPIOC_PDOR ^= (-(0) ^ GPIOC_PDOR ) & (1 << 0); //Put PTC0 as LOW
	}
	//PWM2 -> PTC8
	if (ulCount <= duty_cycle2) {
		GPIOC_PDOR ^= (-(1) ^ GPIOC_PDOR ) & (1 << 8); //Put PTC8 as HIGH
	} else {
		GPIOC_PDOR ^= (-(0) ^ GPIOC_PDOR ) & (1 << 8); //Put PTC8 as LOW
	}
	//PWM3 -> PTC3
	if (ulCount <= duty_cycle3) {
		GPIOC_PDOR ^= (-(1) ^ GPIOC_PDOR ) & (1 << 3); //Put PTC3 as HIGH
	} else {
		GPIOC_PDOR ^= (-(0) ^ GPIOC_PDOR ) & (1 << 3); //Put PTC3 as LOW
	}
	vTimerSetTimerID(xTimer, (void *) ulCount);
}
