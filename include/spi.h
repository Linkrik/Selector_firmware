/*******************************************
 * spi.h
 *
 *  Created on: 26.11.2021 10:07
 *      Author: Mikhail Leksin <LinKrik>
 ******************************************/

#ifndef INCLUDE_SPI_H_
#define INCLUDE_SPI_H_

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
void initSpi_B1_Master();
void initSpi_B1_Slave();
void transmitByte_Spi_B1(uint8_t data);
uint8_t receiveByte_Spi_B1();
bool spiB1_write_byte_buffer(uint8_t dataByte);
void spiB1_transmit_data_2byte(uint16_t all_data);
uint16_t spiB1_receive_data_2byte();
bool spiB1_ready_transmit();
bool spiB1_ready_receive_data_2bytes();

#endif /* INCLUDE_SPI_H_ */
/*******************************************
 * End of file spi.h
 ******************************************/
