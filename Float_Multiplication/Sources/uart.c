#include "uart.h"

void uart_init(void) {
	SIM_SCGC4 |= (1 << 10);	//CLK UART0
	SIM_SCGC5 |= (1 << 9);	//CLOCK for PORTA
	SIM_SOPT2 |= (1 << 26);	//Enable UART0 clock with MCGFLLCLK clock or MCGPLLCLK/2 clock
	PORTA_PCR1 = (1<<9);	//Port control for UART_0
	PORTA_PCR2 = (1<<9);	//Port control for UART_0
	UART0_BDL = 137;		//clock=640*32768, baud rate 9600
	UART0_C2 |= (1 << 5);		//reciver interrupt enable for RDRF
	UART0_C2 |= (1 << 2);		//RE reciver enable
	UART0_C2 |= (1 << 3);		//TE Transmiter enable
	NVIC_ICPR(1) |= (1<<(12%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(12%32));		//Clean flag of LPTM in the interrupt vector
}
