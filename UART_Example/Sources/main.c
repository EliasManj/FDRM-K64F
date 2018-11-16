/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

#define NEW_LINE 	0x0A
#define CARR_RETURN 0x0D
#define BACKSPACE 	0x08

#define BUFLEN 20
uint8_t uart_recive;

struct Buffer {
	volatile uint8_t head;
	volatile uint8_t tail;
	volatile uint8_t size;
	volatile char data[BUFLEN];
};

typedef struct Buffer bufferType;
bufferType Buffer_rx = { 0, 0, BUFLEN, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
bufferType *rx_bf;

void uart_init_usb(void);
void buffer_push(bufferType *bf, char data);
char buffer_pop(bufferType *bf);
uint8_t buffer_inc(uint8_t pointer, uint8_t size);
uint8_t buffer_isempty(bufferType *bf);
uint8_t buffer_len(bufferType *bf);
uint8_t buffer_isfull(bufferType *bf);

int main(void) {
	rx_bf = &Buffer_rx;
	uart_init_usb();
	while (1) {
	}
	return 0;
}

void uart_init_usb(void) {
	SIM_SCGC4 |= (1 << 10);	//CLK UART0
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /*Enable the PORTB clock*/
	PORTB_PCR16 |= PORT_PCR_MUX(3);
	PORTB_PCR17 |= PORT_PCR_MUX(3);
	UART0_BDL = 137;		//clock=640*32768, baud rate 9600
	UART0_C2 |= (1 << 5);		//reciver interrupt enable for RDRF
	UART0_C2 |= (1 << 2);		//RE reciver enable
	UART0_C2 |= (1 << 3);		//TE Transmiter enable
	NVIC_ISER(0) |= (1 << (31%32));
	NVIC_ICPR(0) |= (1 << (32%32));
}

void UART0_Status_IRQHandler(void) {
	//WRITE
	if (((UART0_S1 & 0x80) >> 7) && (!buffer_isempty(rx_bf))) {
		UART0_D = buffer_pop(rx_bf);
		if (buffer_isempty(rx_bf)) {
			UART0_C2 &= ~(0x80);
		}
	}
	//READ
	if ((UART0_S1 & 0x20) >> 5 && !(buffer_isfull(rx_bf))) {
		uart_recive = UART0_D;
		buffer_push(rx_bf, uart_recive);
		if (uart_recive == CARR_RETURN) {
			buffer_push(rx_bf, NEW_LINE);
		}
		UART0_C2 |= 0x80;	//Turn on TX interrupt
	}
}

void buffer_push(bufferType *bf, char data) {
	bf->data[bf->tail] = data;
	bf->tail = buffer_inc(bf->tail, bf->size);
}

char buffer_pop(bufferType *bf) {
	uint8_t item = bf->data[bf->head];
	bf->head = buffer_inc(bf->head, bf->size);
	return item;
}

uint8_t buffer_inc(uint8_t pointer, uint8_t size) {
	uint8_t i = pointer;
	if (++i >= size) {
		i = 0;
	}
	return i;
}

uint8_t buffer_isempty(bufferType *bf) {
	return bf->head == bf->tail;
}

uint8_t buffer_isfull(bufferType *bf) {
	return buffer_len(bf) == (bf->size - 1);
}

uint8_t buffer_len(bufferType *bf) {
	uint8_t len = bf->tail - bf->head;
	if (len < 0) {
		len += bf->size;
	}
	return len;
}
