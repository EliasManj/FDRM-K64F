/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
extern void ldr_ex(uint32_t *pt);
extern void atomic_write(uint32_t data, uint32_t *pt);
extern uint32_t atomic_read(uint32_t *pt);
inline uint32_t atomic_increment(uint32_t * memory);
inline uint32_t atomic_set(uint32_t data, uint32_t * memory);
void Push_Btn_SW2(void);
void Push_Btn_SW3(void);

uint32_t var = 10;
uint32_t *pt;

int main(void) {

	Push_Btn_SW2();
	Push_Btn_SW3();
	pt = &var;
	uint32_t var2;
	var2 = atomic_read(pt);
	while (1) {

	}
}

inline uint32_t atomic_increment(uint32_t * memory) {
	uint32_t temp1, temp2;
	__asm__ __volatile__ (
			"1:\n"
			"ldrex %[t1],[%[m]]\n"
			"add %[t1],%[t1],#1\n"
			"strex %[t2],%[t1],[%[m]]\n"
			"cmp %[t2],#0\n"
			: [t1] "=&r" (temp1), [t2] "=&r" (temp2)
			: [m] "r" (memory)
	);
	return temp1;
}

inline uint32_t atomic_set(uint32_t data, uint32_t * memory) {
	uint32_t temp1, temp2;
	__asm__ __volatile__ (
			"1:\n"
			"ldrex %[t1],[%[m]]\n"
			"mov %[t1],%[d]\n"
			"strex %[t2],%[t1],[%[m]]\n"
			: [t1] "=&r" (temp1), [t2] "=&r" (temp2)
			: [m] "r" (memory), [d] "r" (data)
	);
	return temp2;
}

void Push_Btn_SW2(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(61%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(61%32)); 		//Activate the LPTM interrupt
}

void Push_Btn_SW3(void) {
	SIM_SCGC5 |= (1 << 9);
	PORTA_PCR4 |= (1<<8);
	PORTA_PCR4 |= (8<<16);
	NVIC_ICPR(1) |= (1<<(59%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(59%32)); 		//Activate the LPTM interrupt
}

void PORTC_IRQHandler() {
	PORTC_PCR6 &= ~(0<<24);
	uint32_t temp;
	temp = atomic_read(pt);
}

void PORTA_IRQHandler() {
	//PORTA_PCR4 &= ~(0<<24);
	//atomic_write(0xCC, pt);
}

void NMI_Handler() {
	PORTA_PCR4 &= ~(0<<24);
	//var = atomic_read(pt);
	atomic_write(0xAA, pt);
}
