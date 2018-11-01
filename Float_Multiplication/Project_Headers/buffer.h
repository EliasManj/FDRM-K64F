
#include "derivative.h"
#ifndef BUFFER_H_
#define BUFFER_H_

#define BUFLEN 100

//Define Buffer
struct Buffer {
	volatile uint8_t head;
	volatile uint8_t tail;
	volatile uint8_t size;
	volatile char data[BUFLEN];
};

typedef struct Buffer bufferType;

void buffer_push(bufferType *bf, char data);
char buffer_pop(bufferType *bf);
uint8_t buffer_inc(uint8_t pointer, uint8_t size);
uint8_t buffer_isempty(bufferType *bf);
uint8_t buffer_len(bufferType *bf);
uint8_t buffer_size(bufferType *bf);
uint8_t buffer_isfull(bufferType *bf);

#endif /* BUFFER_H_ */
