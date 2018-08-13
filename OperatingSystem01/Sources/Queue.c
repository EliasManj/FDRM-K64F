/*
 * Queue.c
 *
 *  Created on: Aug 13, 2018
 *      Author: Elias g
 */

#include "User.h"
#include "Queue.h"

void Queue_Add(QueueType *queue, TASK task){
	queue->tasklist[queue->tail] = task;
}

TASK Queue_Next(QueueType *queue){
	TASK next_task = queue->tasklist[queue->head];
	queue->head = Queue_Pt_Inc(queue->head, queue->size);
	return next_task;
}

uint8_t Queue_Pt_Inc(uint8_t pointer, uint8_t size){
	uint8_t i = pointer;
	if (++i >= size) {
		i = 0;
	}
	return i;
}

uint8_t TaskList_Empty(QueueType *queue){
	return queue->head == queue->tail;
}

uint8_t TaskList_Full(QueueType *queue){
	return TaskList_TaskNumber(queue) == (queue->size - 1);
}

uint8_t TaskList_TaskNumber(QueueType *queue){
	uint8_t len = queue->tail - queue->head;
		if (len < 0) {
			len += queue->size;
		}
	return len;
}


