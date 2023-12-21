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
			if (strcmp(command_data, "!RST#") == 0) {
				command_parse_state = RST;

			}

			if (strcmp(command_data, "!OK#") == 0){
				command_parse_state = OK;

			}
			break;
		case RST:
			command_data = "";
			command_flag = RST_FLAG;
			command_parse_state = IDLE;
			break;
		case OK:
			command_data = "";
			command_flag = OK_FLAG;
			command_parse_state = IDLE;
			break;
	}
}
