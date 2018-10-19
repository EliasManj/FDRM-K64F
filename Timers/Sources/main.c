/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "RGB.h"

void pll_Init(void);
void fll_config(void);
void flex(void);
void FTM_Init(void);
void fll_Init(void);
void setGPIO_PortC(void);

int a;

void FTM0_IRQHandler(void) {
	(void) FTM0_SC;
	FTM0_SC |= 0x0080;
	if (a) {
		GPIOC_PDOR ^= (-(1) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as HIGH
		a = 0;
	} else {
		GPIOC_PDOR ^= (-(0) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as LOW
		a = 1;
	}
}

void FTM2_IRQHandler(void) {
	(void) FTM2_SC;
	FTM2_SC |= 0x0080;
	if (a) {
		RGB(1, 0, 0);
		a = 0;
	} else {
		RGB(0, 1, 0);
		a = 1;
	}
}

int main(void) {
	a = 0;
	RGB_Init();
	//port_Init();
	setGPIO_PortC();
	//fll_Init();
	pll_Init();
	return 0;
}


void fll_Init(void) {
	//SIM_SCGC6|=(1<<27)+(1<<24);
	SIM_SCGC6 |= (1 << 24);
	SIM_SCGC5 |= (1 << 13) + (1 << 12);	//Port E
	//SIM_SCGC4|=(1<<10);
	//SIM_SOPT2|=(1<<26)+(3<<24);
	//SIM_SOPT2 |= (3 << 24);
	PORTD_PCR1 =1<<8;
	GPIOD_PDDR = 0x00000002;
	MCG_S |= (1 << 4)+1;
	MCG_C6 &= ~(1 << 6);	//PLLS
	//MCG_C4 |= (1 << 7);	//DMX32
	//MCG_C4 |= (3 << 5);	//DRS
	//MCG_C1 |= (1<<6);		//CLKS
	MCG_C1 |= 1 << 1;		
	MCG_C1 |= (1 << 2);		//IREFS
	MCG_C2 |= 1;
	//MCG_SC |= (5<<1);
	FTM0_SC |= 1 << 3; //iniciar conteo
	//TPM0_C2SC|=(1<<6)+(1<<4)+(1<<2); //hab interrupciones
	FTM0_C2SC |= (1 << 6) + (5 << 2); //hab interrupciones

	NVIC_ICPR(1) = (1 << (42%32));  //Banderas TPM0
	NVIC_ISER(1) = (1 << (42%32));

	PORTE_PCR29 =3<<8; //TPM0_CH2

}
