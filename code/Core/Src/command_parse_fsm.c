/*
 * command_parse_fsm.c
 *
 *  Created on: Dec 20, 2023
 *      Author: giang
 */

#include "command_parse_fsm.h"


void command_parse_fsm (void) {
	switch (command_parse_state) {
		case IDLE:

			// do nothing
			if (strstr(buffer, "!RST#") != NULL) {
				HAL_UART_Transmit (&huart2 , "hello" , sizeof("hello"), 1000);
				command_parse_state = RST;
			}

			if (strstr(buffer, "!OK#") != NULL){
				command_parse_state = OK;
			}

			break;
		case RST:
			command_data = RST_FLAG;
			command_flag = 1;
			memset(buffer, 0, sizeof(buffer));

			command_parse_state = IDLE;

			break;
		case OK:
			command_data = OK_FLAG;
			command_flag = 1;
			memset(buffer, 0, sizeof(buffer));

			command_parse_state = IDLE;

			break;
	}
}
