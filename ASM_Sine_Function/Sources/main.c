/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

extern int32_t sin_iq(int32_t x);

int main(void) {
	
	int32_t x = 0x00006000;
	sin_iq(x);

	return 0;
}
