/*
 * OperativeSystem.c
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"
#include "User.h"
#include "OperativeSystem.h"

TASK first;
TASK ready_arr[3];

void ActivateTask(TASK task){
	
}

void ChainTask(TASK task){
	
}

void TerminateTask(){
	
}

void OS_init(volatile TASK *tasks, int size){
	//first = CheckHighestPriority(tasks);
	TASK firstTask;
	int count = 0;
	int i;
	for(i=0;i<size;i++){
		if(tasks[i].autostart == 1){
			tasks[i].state = 1; //si tiene autostart la tarea se va a ready
		}	
		if(tasks[i].state == 1){
			ready_arr[count] = tasks[i];
			count++;
		} 
	}
	firstTask = checkHighestPriority(ready_arr, size);
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

