/*******************************************
 * fram_msp430fr2xx_4xx.h
 *
 *  Created on: 22.10.2021 9:10
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

#ifndef INCLUDE_FRAM_MSP430FR2XX_4XX_H_
#define INCLUDE_FRAM_MSP430FR2XX_4XX_H_

/*******************************************
 * Includes
 ******************************************/
#include "driverlib.h"


/*******************************************
 * Defines
 ******************************************/
#define FRAM_START_IINFORMATION     (0x1800)
#define SIZE_UINT32                 (sizeof(uint32_t))
#define SIZE_UINT16                 (sizeof(uint16_t))

/*******************************************
 * Public function prototypes
 ******************************************/
void FRAM_Write_UINT16 (uint16_t address, uint16_t data);
uint16_t FRAM_Read_UINT16 (uint16_t address);

#endif /* INCLUDE_FRAM_MSP430FR2XX_4XX_H_ */
/*******************************************
 * End of file fram_msp430fr2xx_4xx.h
 ******************************************/
