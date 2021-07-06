/*
 * uart.h
 *
 *  Created on: 17 мая 2021 г.
 *      Author: LinKrik
 */

#ifndef UART_H_
#define UART_H_

#define IFG_RX

void initUART_8MHz();
void initUART_1MHz();
void uart_transmit_byte(unsigned char byte);
unsigned char uart_receive_byte();


#endif /* UART_H_ */
