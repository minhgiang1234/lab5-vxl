/*
 * global.c
 *
 *  Created on: Dec 20, 2023
 *      Author: giang
 */


#include "global.h"
#include "command_parse_fsm.h"
#include "uart_communication_fsm.h"

void system_init(void){
	uart_communication_state = IDLE1;
	command_parse_state = IDLE;
	timer_flag = 0;
	buffer_flag = 0;
	command_flag = 1;

}
