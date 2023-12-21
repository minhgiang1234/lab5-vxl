/*
 * uart_communiation_fsm.c
 *
 *  Created on: Dec 20, 2023
 *      Author: giang
 */


#include "uart_communication_fsm.h"

void uart_communication_fsm(void){
	if (command_flag){
		switch (uart_communication_state){
			case IDLE1:
				// do nothing

				if (command_flag == RST_FLAG){
					uart_communication_state = SEND_DATA;
				}
				break;
			case SEND_DATA:

				// send data
				ADC_value = HAL_ADC_GetValue (&hadc1);
				uint8_t * str;
				HAL_UART_Transmit (&huart2 , (void *) str , sprintf (str , "%d\n", ADC_value), 1000);


				uart_communication_state = IDLE2;

				break;
			case IDLE2:

				// do nothing

				if (timer_flag == 1) uart_communication_state = SEND_DATA;
				if (command_flag == OK_FLAG) uart_communication_state = IDLE1;
				break;

		}
	}
}
