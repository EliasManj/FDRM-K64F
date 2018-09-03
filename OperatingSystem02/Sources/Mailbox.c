#include "derivative.h" /* include peripheral declarations */
#include "Mailbox.h"
#include "OperativeSystem.h"
#include "RGB.h"

uint8_t WriteToMailbox(uint32_t mailbox_id, uint32_t data) {
	if (mailbox_id >= mailbox_n) {
		return 1;
	}
	TASK running;
	getRunningTask(running);
	if (running.id == mailbox_list[mailbox_id].producer_id) {
		RGB(1, 0, 0);
	} else {
		return 1;
	}
	return 0;
}

uint8_t ReadFromMailbox(uint32_t mailbox_id) {
	if (mailbox_id >= mailbox_n) {
		return 1;
	}
	TASK running;
	getRunningTask(running);
	if (running.id == mailbox_list[mailbox_id].consumer_id) {
		RGB(1, 0, 0);
	} else {
		return 1;
	}
	return 0;
}

uint8_t CreateMailBox(uint32_t mailbox_id, uint32_t consumer_id, uint32_t producer_id){
	if(mailbox_n>=MAILBOX_LIST_SIZE){
		return 1;
	}
	uint32_t *pt;
	if(!pt){
		return 1;
	}
	mailbox_list[mailbox_id].data = pt;
	mailbox_list[mailbox_id].consumer_id = consumer_id;
	mailbox_list[mailbox_id].producer_id = producer_id;
	mailbox_n++;
	return 0;
}

uint32_t *Allocate(void){
	uint32_t *pt;
	pt = FreePt;
	if(pt!=0){
		FreePt = (uint32_t*)*pt;
	}
	return(pt);
}
