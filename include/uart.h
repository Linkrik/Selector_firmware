/*******************************************
 * uart.h
 *
 *  Created on: 13.10.2021 12:59:51
 *      Author: Mikhail Leksin <LinKrik>
 ******************************************/
#ifndef INCLUDE_UART_H_
#define INCLUDE_UART_H_

/*******************************************
 * Includes
 ******************************************/
#include "driverlib.h"
#include "fifo_buffer.h"

/*******************************************
 * Defines
 ******************************************/
#define BUFSIZE         (256)

/*******************************************
 * Global variables
 ******************************************/



/*******************************************
 * Public function prototypes
 ******************************************/

void        deinitUART1();
void        initUART1();

uint8_t     uart1_receive_byte();
void        uart1_transmit_byte(uint8_t byte);
bool        uart1_write_byte_buffer(uint8_t dataByte);

bool        uart1_ready_transmit();
bool        uart1_ready_receive_data_2bytes();

void        uart1_transmit_data_2byte(uint16_t all_data);
uint16_t    uart1_receive_data_2byte();



#endif /* INCLUDE_UART_H_ */

/*******************************************
 * End of file uart.h
 ******************************************/
