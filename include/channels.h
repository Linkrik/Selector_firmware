/*******************************************
 * channels.h
 *
 *  Created on: 25.04.2022 11:39:14
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/
#ifndef INCLUDE_CHANNELS_H_
#define INCLUDE_CHANNELS_H_

/*******************************************
 * Include
 *******************************************/
#include "driverlib.h"

/*******************************************
 * Defines
 ******************************************/
#define KEY_VALUE_0    (0x00) //000
#define KEY_VALUE_1    (0x01) //001
#define KEY_VALUE_2    (0x02) //010
#define KEY_VALUE_3    (0x03) //011
#define KEY_VALUE_4    (0x04) //100
#define KEY_VALUE_5    (0x05) //101
#define KEY_VALUE_6    (0x06) //110


/*******************************************
 * Global variables
 ******************************************/

/*******************************************
 * Public function prototypes
 ******************************************/
void switch_channels_mhz(uint16_t MHz);


#endif /* INCLUDE_CHANNELS_H_ */
/*******************************************
 * End of file channels.h
 *******************************************/
