/*******************************************
 * ext_communication.h
 *
 *  Created on: 15.04.2022 17:10:24
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/
#ifndef INCLUDE_EXT_COMMUNICATION_H_
#define INCLUDE_EXT_COMMUNICATION_H_

/*******************************************
 * Include
 *******************************************/
#include "std_protocol.h"
#include "actions.h"
#include "uart.h"

/*******************************************
 * Defines
 ******************************************/
#define DEBUG

/*******************************************
 * Global variables
 ******************************************/
extern stdChannel_s Uart1_channel;
extern stdChannel_s Spi1_channel;

/*******************************************
 * Public function prototypes
 ******************************************/
void Communication_Init(void);
void starting_STD_Process(void);

#endif /* INCLUDE_EXT_COMMUNICATION_H_ */
/*******************************************
 * End of file ext_communication.h
 *******************************************/
