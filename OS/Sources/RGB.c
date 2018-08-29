#include "derivative.h" /* include peripheral declarations */
#include "RGB.h"

void RGB_Init(void){
	Blue_Led_Init();
	Red_Led_Init();
	Green_Led_Init();
}

void Blue_Led_Init(void) {
	//Blue LED
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR21 = (1<<8);	//Set PTB21 as GPIO
	GPIOB_PDDR |= (1 << 21);	//Set PTB21 as output
	GPIOB_PDOR = ~(1 << 21);	//Put PTB21 as HIGH
	GPIOB_PDOR |= (1 << 21);	//Put PTB21 as LOW
}

void Red_Led_Init(void){
	SIM_SCGC5 |= (1 << 10);	//Activate system clock for PORTB
	PORTB_PCR22 = (1<<8);	//Set PTB22 as GPIO
	GPIOB_PDDR |= (1 << 22);	//Set PTB22 as output
	GPIOB_PDOR = ~(1 << 22);	//Put PTB22 as HIGH
	GPIOB_PDOR |= (1 << 22);	//Put PTB22 as LOW
}

void Green_Led_Init(void){
	SIM_SCGC5 |= (1 << 13);	//Activate system clock for PORTB
	PORTE_PCR26 = (1<<8);	//Set PTE26 as GPIO
	GPIOE_PDDR |= (1 << 26);	//Set PTE26 as output
	GPIOE_PDOR = ~(1 << 26);	//Put PTE26 as HIGH
	GPIOE_PDOR |= (1 << 26);	//Put PTE26 as LOW
}

void RGB(int r, int g, int b){
	r ^= 1;
	g ^= 1;
	b ^= 1;
	GPIOB_PDOR ^= (-(r) ^ GPIOB_PDOR) & (1 << 22);
	GPIOE_PDOR ^= (-(g) ^ GPIOE_PDOR) & (1 << 26);
	GPIOB_PDOR ^= (-(b) ^ GPIOB_PDOR) & (1 << 21);
}
