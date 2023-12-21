/*
 * global.h
 *
 *  Created on: Dec 20, 2023
 *      Author: giang
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include <string.h>

ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

int command_flag ;
char* command_data ;
int buffer_flag ;
int timer_flag;

int command_parse_state;
int uart_communication_state;

#define RST_FLAG 11
#define OK_FLAG 12

void system_init(void);

#endif /* INC_GLOBAL_H_ */
