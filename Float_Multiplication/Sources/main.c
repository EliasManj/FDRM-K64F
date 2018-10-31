/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Float_Values.h"

int32_t mult_f32(int32_t n0, int32_t n1);

typedef union {
	uint32_t val;
	struct {
		uint64_t mantissa :23;
		uint32_t exp :8;
		uint32_t sign :1;
	} fields;
} f32_t;

int main(void) {

	int32_t x0 = f32_arr0[2];
	int32_t x1 = f32_arr1[2];
	int32_t result;
	result = mult_f32(x0,x1);

	return 0;
}


