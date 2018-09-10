#include "derivative.h" /* include peripheral declarations */
#include "Alarms.h"
#include "OperativeSystem.h"

int GetAlarmBase(uint8_t alarm_id) {
	return alarm_list[alarm_id].reference;
}

void SetRelAlarm(uint8_t alarm_id, int incrementTicks) {
	alarm_list[alarm_id].count = incrementTicks;
}

void SetAbsAlarm(uint8_t alarm_id, int startTicks) {
	alarm_list[alarm_id].reference = startTicks;
}

void CancelAlarm(uint8_t alarm_id) {
	alarm_list[alarm_id].active = 0;
}

void Alarms_Enable(void) {
	int i;
	for (i = 0; i < ALARM_LIST_SIZE; i++) {
		alarm_list[i].active = 1;
	}
}

void Alarms_Disable(void) {
	int i;
	for (i = 0; i < ALARM_LIST_SIZE; i++) {
		alarm_list[i].active = 0;
	}
}

void GetAlarm(uint8_t alarm_id, AlarmObj *alarm) {
	*alarm = alarm_list[alarm_id];
}
