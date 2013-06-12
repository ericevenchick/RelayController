#include <hidef.h> /* for EnableInterrupts macro */
#include "relay.h"
#include "can.h"

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void MCU_init(void); /* Device initialization function declaration */

void sleep(void) {
	SOPT1_STOPE = 1;
	SPMSC1_LVDE = 0;
	SPMSC2_PPDC = 0;
	__asm("STOP");
}

void main_loop(void) {
	CANMSG test;
	long i;
	int res;
	RELAY1_PIN = 1;
	
	test.id=5;
	test.dlc = 8;
	test.data[0] = 0x55;
	
	for(;;) {
		res = can_send_msg(&test);
		for (i=0; i<30000; i++);
	}
}
