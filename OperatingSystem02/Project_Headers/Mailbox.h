/*
 * Mailbox.h
 *
 *  Created on: Aug 31, 2018
 *      Author: Elias g
 */

#ifndef MAILBOX_H_
#define MAILBOX_H_

#define MAILBOX_LIST_SIZE 10

struct Mailbox {
	volatile int32_t *data;
	volatile uint32_t consumer_id;
	volatile uint32_t producer_id;
	volatile uint8_t has_data;
	volatile uint8_t consumer_waiting;
};
typedef struct Mailbox MailboxObj;
uint16_t mailbox_n;
int32_t *FreePt;
MailboxObj mailbox_list[MAILBOX_LIST_SIZE];
MailboxObj mailbox0;
MailboxObj mailbox1;
MailboxObj mailbox2;


int32_t WriteToMailbox(uint32_t mailbox_id, uint32_t data);
int32_t ReadFromMailbox(uint32_t mailbox_id, uint32_t *placeholder);
int8_t CreateMailBox(uint32_t mailbox_id, uint32_t producer_id, uint32_t consumer_id);
int32_t *Allocate(void);

#endif /* MAILBOX_H_ */
