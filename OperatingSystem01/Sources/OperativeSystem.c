/*
 * OperativeSystem.c
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"
#include "User.h"
#include "OperativeSystem.h"
#include "Queue.h"

TASK first;
TASK ready_arr[20];

QueueType readyQueue = { 0, 0, STATIC_ALLOC, { } };

void ActivateTask(TASK task){
	
}

void ChainTask(TASK task){
	
}

void TerminateTask(){
	
}

void OS_init(volatile TASK *tasks, int size){
	checkAutoStartSetReady(tasks, size);
	TASK firstTask;
	firstTask = checkHighestPriority(ready_arr, size);
	firstTask.ap_task_init();
}

void checkAutoStartSetReady(TASK *tasks, int size){
	int count = 0;
		int i;
		for(i=0;i<size;i++){
			if(tasks[i].autostart == 1){
				tasks[i].state = READY; //si tiene autostart la tarea se va a ready
				tasks[i].autostart = 0;
			}	
			if(tasks[i].state == READY){
				ready_arr[count] = tasks[i];
				count++;
			} 
		}
}

TASK checkHighestPriority(TASK *tasks, int size){
	int i;
	TASK highest = tasks[0];
	for(i = 1; i<=3; i++){
		if(tasks[i].priority > highest.priority){
			highest = tasks[i];
		}
	}
	return highest;
}



