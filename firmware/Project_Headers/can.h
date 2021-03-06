#ifndef CAN_H_
#define CAN_H_

#define CAN_ID_SET 0x100
#define CAN_ID_GET 0x101

typedef struct {
	long id;
	char dlc;
	char data[8];
} CANMSG;

void isr_can_rx(void);
int can_send_msg(CANMSG *msg);

#endif /* CAN_H_ */
