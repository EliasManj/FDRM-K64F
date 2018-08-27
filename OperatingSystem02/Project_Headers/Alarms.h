/*
 * Alarms.h
 *
 *  Created on: Aug 25, 2018
 *      Author: Elias g
 */

#ifndef ALARMS_H_
#define ALARMS_H_

#define ALARM_LIST_SIZE 2

struct Alarm {
	volatile uint8_t alarm_id;
	volatile uint8_t count;
	volatile uint8_t active;
	volatile uint8_t reference;
	volatile uint8_t reload;
	volatile uint8_t task_id;
};

typedef struct Alarm AlarmObj;
AlarmObj alarm_list[ALARM_LIST_SIZE];
AlarmObj alarm_a;
AlarmObj alarm_b;
AlarmObj alarm_c;
AlarmObj alarm_d;
AlarmObj alarm_e;

void DecrementAlarmsTicks(void);
int GetAlarmBase(uint8_t alarm_id);
void SetRelAlarm(uint8_t alarm_id, int incrementTicks);
void SetAbsAlarm(uint8_t alarm_id, int startTicks);
void CancelAlarm(uint8_t alarm_id);
void GetAlarm(uint8_t alarm_id, AlarmObj *alarm);
void DecrementAlarmsTicks(void);

#endif /* ALARMS_H_ */
