#include "derivative.h" /* include peripheral declarations */
#include "Mailbox.h"
#include "OperativeSystem.h"
#include "RGB.h"
#include "shared.h"

int8_t WriteToMailbox(uint32_t mailbox_id, uint32_t data) {
	if (mailbox_id >= mailbox_n) {
		return 1;
	}
	int32_t id;
	id = getRunningTaskID();
	if (id == mailbox_list[mailbox_id].producer_id) {
		*mailbox_list[mailbox_id].data = data;
		mailbox_list[mailbox_id].has_data = 1;
		if (mailbox_list[mailbox_id].consumer_waiting) {
			move_waiting_task_to_ready(mailbox_list[mailbox_id].consumer_id);
		}
	} else {
		return 1;
	}
	return 0;
}

int32_t ReadFromMailbox(uint32_t mailbox_id, uint32_t *placeholder) {
	task_incomplete_rd = LR_c;
	Interrupt_Disable();
	sp = SP_c-0x38;
	if (mailbox_list[mailbox_id].has_data == 0) {
		mailbox_list[mailbox_id].consumer_waiting = 1;
		move_current_task_to_wait();
	} else {
		if (mailbox_id >= mailbox_n) {
			return 1;
		}
		int32_t id;
		id = getRunningTaskID();
		if (id == mailbox_list[mailbox_id].consumer_id) {
			*placeholder = *mailbox_list[mailbox_id].data;
			mailbox_list[mailbox_id].has_data = 0;
		} else {
			return 1;
		}
	}
	return 0;
}

int8_t CreateMailBox(uint32_t mailbox_id, uint32_t producer_id,
		uint32_t consumer_id) {
	if (mailbox_n >= MAILBOX_LIST_SIZE) {
		return 1;
	}
	int32_t *pt;
	pt = malloc(8);
	mailbox_list[mailbox_id].data = pt;
	mailbox_list[mailbox_id].consumer_id = consumer_id;
	mailbox_list[mailbox_id].producer_id = producer_id;
	mailbox_n++;
	return 0;
}
