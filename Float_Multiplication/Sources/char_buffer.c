/*
 * buffer.c
 *
 *  Created on: Apr 8, 2018
 *      Author: Elias g
 */
#include "char_buffer.h"

void buffer_push(bufferType *bf, char data) {
	bf->data[bf->tail] = data;
	bf->tail = buffer_inc(bf->tail, bf->size);
}

uint8_t buffer_pop(bufferType *bf) {
	uint8_t item = bf->data[bf->head];
	bf->head = buffer_inc(bf->head, bf->size);
	return item;
}

uint32_t buffer_size(bufferType *bf) {
	return bf->size;
}

uint32_t buffer_inc(uint32_t pointer, uint32_t size) {
	uint32_t i = pointer;
	if (++i >= size) {
		i = 0;
	}
	return i;
}

uint8_t buffer_isempty(bufferType *bf) {
	return bf->head == bf->tail;
}

uint8_t buffer_almost_empty(bufferType *bf) {
	return bf->head == bf->tail-1;
}

uint8_t buffer_isfull(bufferType *bf) {
	return buffer_len(bf) == (bf->size - 1);
}

uint32_t buffer_len(bufferType *bf) {
	uint32_t len = bf->tail - bf->head;
	if (len < 0) {
		len += bf->size;
	}
	return len;
}
