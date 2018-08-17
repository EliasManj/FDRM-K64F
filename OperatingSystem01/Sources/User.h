/*
 * User.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"

#ifndef USER_H_
#define USER_H_

#define IDLE 0
#define READY 1
#define RUNNING 2
#define WAIT 3

typedef struct {
    volatile uint8_t priority;
    volatile uint8_t autostart;
    volatile uint32_t return_direction;
    void (*ap_task_init)(void);
    volatile uint8_t state; //STATE 0:IDLE 1:READY 2:RUNNING 3:WAIT
} TASK;

#endif /* USER_H_ */