#ifndef BUFFER_H_
#define BUFFER_H_

#include "derivative.h"

#define BUFLEN 100

//Define Buffer
struct Buffer {
	volatile uint8_t head;
	volatile uint8_t tail;
	volatile uint8_t size;
	volatile char data[BUFLEN];
};

typedef struct Buffer bufferType;

void uart_init(void);

#endif /* BUFFER_H_ */
