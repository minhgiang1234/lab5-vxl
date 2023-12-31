/*
 * uart_communiation_fsm.c
 *
 *  Created on: Dec 20, 2023
 *      Author: giang
 */


#include "uart_communication_fsm.h"

void uart_communication_fsm(void){
	unsigned char str[100] = "";
	if (command_flag){
		switch (uart_communication_state){

			case IDLE1:
				// do nothing
				if (command_data == RST_FLAG){
					uart_communication_state = SEND_DATA_1;
				}

				command_data = NO_COMMAND;
				break;
			case SEND_DATA_1:

				// send data
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);

				sprintf ((char *)str , "\r\n%ld\r\n", ADC_value);
				HAL_UART_Transmit (&huart2 , str , sizeof(str), 1000);


				uart_communication_state = IDLE2;

				break;
			case IDLE2:

				// do nothing
				if (command_data == OK_FLAG) {
					uart_communication_state = IDLE1;
					command_data = NO_COMMAND;
					command_flag = 0;
				}else if (timer_flag == 1) {
					uart_communication_state = SEND_DATA_2;
					timer_flag = 0;
				}

				break;
			case SEND_DATA_2:
				sprintf ((char *)str , "\r\n%ld\r\n", ADC_value);
				HAL_UART_Transmit (&huart2 , str , sizeof(str), 1000);

				uart_communication_state = IDLE2;
				break;

		}
	}
}
