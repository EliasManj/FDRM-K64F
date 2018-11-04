/*
 * char_buffer.h
 *
 *  Created on: Nov 2, 2018
 *      Author: Elias g
 */

#ifndef CHAR_BUFFER_H_
#define CHAR_BUFFER_H_


#include "derivative.h"
#define BUFLEN 10000

//Define Buffer
struct Buffer {
	volatile uint32_t head;
	volatile uint32_t tail;
	volatile uint32_t size;
	volatile char data[BUFLEN];
};

typedef struct Buffer bufferType;

void buffer_push(bufferType *bf, char data);
uint8_t buffer_pop(bufferType *bf);
uint32_t buffer_inc(uint32_t pointer, uint32_t size);
uint8_t buffer_isempty(bufferType *bf);
uint32_t buffer_len(bufferType *bf);
uint32_t buffer_size(bufferType *bf);
uint8_t buffer_isfull(bufferType *bf);



#endif /* CHAR_BUFFER_H_ */
