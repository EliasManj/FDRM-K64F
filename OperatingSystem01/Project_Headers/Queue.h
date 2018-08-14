/*
 * Queue.h
 *
 *  Created on: Aug 13, 2018
 *      Author: Elias g
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define STATIC_ALLOC 20

struct Queue {
	volatile uint8_t head;
	volatile uint8_t tail;
	volatile uint8_t size;
	volatile TASK tasklist[STATIC_ALLOC];
};

typedef struct Queue QueueType;

void Queue_Add(QueueType *queue, TASK task);
TASK Queue_Next(QueueType *queue);
uint8_t Queue_Pt_Inc(uint8_t pointer, uint8_t size);
uint8_t TaskList_Empty(QueueType *queue);
uint8_t TaskList_Full(QueueType *queue);
uint8_t TaskList_TaskNumber(QueueType *queue);

#endif /* QUEUE_H_ */
