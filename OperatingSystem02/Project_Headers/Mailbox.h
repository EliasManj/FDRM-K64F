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
	volatile uint8_t semaphore_flag;
	volatile uint32_t *data;
	volatile uint32_t consumer_id;
	volatile uint32_t producer_id;
};

typedef struct Mailbox MailboxObj;
uint16_t mailbox_n;
uint32_t *FreePt;
MailboxObj mailbox_list[MAILBOX_LIST_SIZE];
uint8_t WriteToMailbox(uint32_t mailbox_id, uint32_t data);
uint8_t ReadFromMailbox(uint32_t mailbox_id);
uint8_t CreateMailBox(uint32_t mailbox_id, uint32_t consumer_id, uint32_t producer_id);
uint32_t *Allocate(void);

#endif /* MAILBOX_H_ */
