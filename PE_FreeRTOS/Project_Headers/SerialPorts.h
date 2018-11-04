/*
 * SerialPorts.h
 *
 *  Created on: Oct 6, 2018
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

#ifndef SERIALPORTS_H_
#define SERIALPORTS_H_

#include "FRTOS1.h"

#define SERIAL0_MASK 	 	0x00000080
#define SERIAL1_MASK 	 	0x00000200
#define SERIAL2_MASK 	 	0x00000002
#define SERIAL3_MASK 	 	0x00000004
#define SERIAL_BTN_MASK  	0x00000040

#define SERIAL0_SHIFT    	7
#define SERIAL1_SHIFT    	9
#define SERIAL2_SHIFT    	1
#define SERIAL3_SHIFT    	2
#define SERIAL_BTN_SHIFT    6

uint32_t duty_cycle0;
uint32_t duty_cycle1;
uint32_t duty_cycle2;
uint32_t duty_cycle3;
uint32_t first_bit;
uint32_t probe;

void serial0_Init(void);
void serial1_Init(void);
void serial2_Init(void);
void serial3_Init(void);
void portC_Init(void);
void Push_Btn_SW2(void);
void serial_ports_Init(void);
void LPTimer_Init(void);

//Variables
TimerHandle_t xTimerSerial0;
TimerHandle_t xTimerSerial1;
TimerHandle_t xTimerSerial2;
TimerHandle_t xTimerSerial3;
//Timer callback
void vSerialTimerCallback0(TimerHandle_t xTimer);
void vSerialTimerCallback1(TimerHandle_t xTimer);
void vSerialTimerCallback2(TimerHandle_t xTimer);
void vSerialTimerCallback3(TimerHandle_t xTimer);

//Interrupt ISR
void ivINT_LPTimer(void);
void ivINT_PORTC(void);
#endif /* SERIALPORTS_H_ */
