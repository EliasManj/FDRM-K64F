/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Float_Values.h"
#include "uart.h"
#include "char_buffer.h"

#define N 1000

uint8_t INT_ON;
uint8_t uart_recive;
uint32_t line;
uint32_t results[N];

//Buffer
bufferType Buffer_tx = { 0, 0, BUFLEN, { } };
bufferType *tx_bf;

int32_t mult_f32(int32_t n0, int32_t n1);
void multiply_values(uint32_t n);
void send_f32_to_uart(uint32_t val);
void test(void);
void enable_uart();
void disable_uart();

typedef union {
	uint32_t val;
	struct {
		uint64_t mantissa :23;
		uint32_t exp :8;
		uint32_t sign :1;
	} fields;
} f32_t;

int main(void) {
	INT_ON = 0;
	line = 0;
	tx_bf = &Buffer_tx;
	uart_init();
	multiply_values(N);
	while (1) {

	}
	return 0;
}

void multiply_values(uint32_t n) {
	int i, j;
	if (n <= FLOAT_SIZE) {
		for (i = 0; i < n; i++) {
			results[i] = mult_f32(f32_arr0[i], f32_arr1[i]);
		}
		for (j = 0; j < n; j++) {
			send_f32_to_uart(results[j]);
		}
	}
}

void send_f32_to_uart(uint32_t val) {
	int i, mask;
	uint8_t uart_byte;
	//send 32 bit value in parts of 8 bits
	for (i = 0; i < 4; i++) {
		mask = (3 - i) * 8;
		uart_byte = (uint8_t) (val >> mask) & 0xFF;
		buffer_push(tx_bf, uart_byte);
	}
	enable_uart();
}

int32_t mult_f32(int32_t x0, int32_t x1) {
	//Result
	uint32_t exp;
	uint32_t sign;
	uint64_t mant0_temp;
	uint64_t mant1_temp;
	uint64_t mant_mult_result;
	int32_t bit;
	//Result temp variables
	f32_t y0;
	f32_t y1;
	f32_t result;
	uint64_t offset;

	y0.val = x0;
	y1.val = x1;

	//Calculate exponent
	exp = y0.fields.exp + y1.fields.exp - 127 - 127;
	//Calculate sign
	sign = y0.fields.sign ^ y1.fields.sign;
	//Add implicit 1 to mantissas
	mant0_temp = y0.fields.mantissa | 0x00800000;
	mant1_temp = y1.fields.mantissa | 0x00800000;
	//Multiply the mantissas
	mant_mult_result = mant0_temp * mant1_temp;
	//Shift 
	mant_mult_result = mant_mult_result >> 23;
	//Normalize the result 
	offset = mant_mult_result & 0xFFFFFFFFFF000000;
	if (offset != 0) {
		//Find how much the result must be shifted 
		for (bit = 63; bit >= 0; bit--) {
			if (((offset & (1 << bit)) >> bit) == 1) {
				bit = bit - 23;
				exp = exp + bit;
				mant_mult_result = mant_mult_result >> bit;
				break;
			}
		}
	}
	result.fields.exp = exp + 127;
	result.fields.sign = sign;
	result.fields.mantissa = mant_mult_result;
	return result.val;
}

void enable_uart() {
	if (INT_ON != 1) {
		INT_ON = 1;
		UART0_C2 |= 0x80; //Turn on TX interrupt
	}
}

void disable_uart() {
	if (INT_ON != 0) {
		INT_ON = 0;
		UART0_C2 &= ~(0x80);
	}
}

void UART0_Status_IRQHandler(void) {
	line++;
	if (line >= 51) {
		line = 51;
	}
	//WRITE
	if (((UART0_S1 & 0x80) >> 7) && (!buffer_isempty(tx_bf))) {
		UART0_D = buffer_pop(tx_bf);
		if (buffer_isempty(tx_bf)) {
			UART0_C2 &= ~(0x80);
		}
	}
}

