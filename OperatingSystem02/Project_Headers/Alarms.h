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

int GetAlarmBase(uint8_t alarm_id);
void SetRelAlarm(uint8_t alarm_id, int incrementTicks);
void SetAbsAlarm(uint8_t alarm_id, int startTicks);
void CancelAlarm(uint8_t alarm_id);
void GetAlarm(uint8_t alarm_id, AlarmObj *alarm);
void DecrementAlarmsTicks(void);
void Alarms_Enable(void);
void Alarms_Disable(void);
extern void set_pc_sp_lr(uint32_t pc, uint32_t sp, uint32_t lr);
extern void pop_r7_pc(void);
extern void set_sp(uint32_t sp);
extern uint32_t finish_isr2(uint32_t isr_return, uint32_t isr_sp, uint32_t scheduler_rd);

#define DecrementAlarmsTicks(void) {\
	uint32_t lr = LR_c;\
	int i;\
	uint8_t AlarmActivated;\
	AlarmActivated = 0;\
	for (i = 0; i < ALARM_LIST_SIZE; i++) {\
		if (alarm_list[i].active == 1) {\
			if (--alarm_list[i].count == 0) {\
				AddTaskFromAlarm(alarm_list[i].task_id);\
				AlarmActivated = 1;\
				if (alarm_list[i].reload == 1) {\
					alarm_list[i].count = alarm_list[i].reference;\
				} else {\
					alarm_list[i].active = 0;\
				}\
			}\
		}\
	}\
	if(AlarmActivated){\
		interrumped_task_lr_addr = get_task_return_dir(alarm_task_context_sp);\
		interrupted_task_sp_addr = finish_isr2(PC_c, alarm_task_context_sp, alarm_return_lr);\
	}\
}\

#endif /* ALARMS_H_ */
