/*
 * uart_communiation_fsm.h
 *
 *  Created on: Dec 20, 2023
 *      Author: giang
 */

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_

#include "global.h"
#include <stdio.h>

#define IDLE1 21
#define SEND_DATA 22
#define IDLE2 23

uint32_t ADC_value;

void uart_communication_fsm(void);


#endif /* INC_UART_COMMUNICATION_FSM_H_ */
