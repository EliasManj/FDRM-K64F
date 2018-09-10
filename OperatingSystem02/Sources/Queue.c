/*
 * Queue.c
 *
 *  Created on: Aug 13, 2018
 *      Author: Elias g
 */

#include "User.h"
#include "Queue.h"

TASK empty = { 0, 0, 0, 0, 'X', 0, 0, 0, 0 };

TASK get_empty_TASK(void) {
	return empty;
}

void Queue_Add(QueueType *queue, TASK task) {
	queue->tasklist[queue->tail] = task;
	queue->tail = Queue_Pt_Inc(queue->tail, queue->size);
}

TASK Queue_Next(QueueType *queue) {
	TASK next_task = queue->tasklist[queue->head];
	queue->tasklist[queue->head] = empty;
	queue->head = Queue_Pt_Inc(queue->head, queue->size);
	return next_task;
}

uint8_t Queue_Pt_Inc(uint8_t pointer, uint8_t size) {
	uint8_t i = pointer;
	if (++i >= size) {
		i = 0;
	}
	return i;
}

uint8_t TaskList_Empty(QueueType *queue) {
	return queue->head == queue->tail;
}

uint8_t TaskList_Full(QueueType *queue) {
	return TaskList_TaskNumber(queue) == (queue->size - 1);
}

uint8_t TaskList_TaskNumber(QueueType *queue) {
	uint8_t len = queue->tail - queue->head;
	if (len < 0) {
		len += queue->size;
	}
	return len;
}

void Sort_TaskList(QueueType *queue) {		//Bubble sort, change to other sorts
	int i, j;
	TASK tmp;
	int multiplicity;
	for (i = queue->head; i < queue->tail; i++) {
		for (j = queue->head; j < queue->tail; j++) {
			multiplicity = (queue->tasklist[i].id == queue->tasklist[j].id)
					&& (queue->tasklist[i].multiplicity
							> queue->tasklist[j].multiplicity);
			;
			if (multiplicity
					|| (queue->tasklist[j].priority
							< queue->tasklist[i].priority)
					|| ((queue->tasklist[i].id != 'X')
							&& (queue->tasklist[j].id == 'X'))) {
				tmp = queue->tasklist[i]; //Using temporary variable for storing last value
				queue->tasklist[i] = queue->tasklist[j];       //replacing value
				queue->tasklist[j] = tmp;             		//storing last value
			}
		}
	}
	for (i = 0; i < queue->tail - queue->head; i++) {
		queue->tasklist[i] = queue->tasklist[i + queue->head];
		if (i != queue->head + i) {
			queue->tasklist[i + queue->head] = empty;
		}
	}
	queue->tail = queue->tail - queue->head;
	queue->head = 0;
}

void Queue_Search(QueueType *queue, uint32_t task_id) {
	int i, j;
	TASK tmp;
	for (i = queue->head; i < queue->tail; i++) {
		for (j = queue->head; j < queue->tail; j++) {
			if ((queue->tasklist[j].id != task_id && queue->tasklist[i].id == task_id)
					|| ((queue->tasklist[i].id != 'X')
							&& (queue->tasklist[j].id == 'X'))) {
				tmp = queue->tasklist[i]; //Using temporary variable for storing last value
				queue->tasklist[i] = queue->tasklist[j];       //replacing value
				queue->tasklist[j] = tmp;             		//storing last value
			}
		}
	}
}

