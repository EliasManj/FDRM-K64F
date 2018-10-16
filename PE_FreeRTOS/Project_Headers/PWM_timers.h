/*
 * PWM_timers.h
 *
 *  Created on: Oct 9, 2018
 *      Author: Elias g
 */

/*
 * SERIAL0 OUT PTC5
 * SERIAL0 RX  PTC7
 * 
 * SERIAL1 OUT PTC0
 * SERIAL1 RX  PTC9
 * 
 * SERIAL2 OUT PTC8
 * SERIAL2 RX  PTC1
 * 
 * SERIAL3 OUT PTC3
 * SERIAL3 RX  PTC2
 */

#ifndef PWM_TIMERS_H_
#define PWM_TIMERS_H_

#include "FRTOS1.h"

void vTimerCallback0(TimerHandle_t xTimer);
void vTimerCallback1(TimerHandle_t xTimer);
void timers_Init(void);
void setGPIO_PortC(void);

#endif /* PWM_TIMERS_H_ */
