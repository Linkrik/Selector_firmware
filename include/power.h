/*******************************************
 * power.h
 *
 *  Created on: 17.11.2021 ã.
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

#ifndef INCLUDE_POWER_H_
#define INCLUDE_POWER_H_

/*******************************************
 * Includes
 ******************************************/
#include"driverlib.h"


/*******************************************
 * Public function prototypes
 ******************************************/
void initPower();
void controlPower(uint32_t select,uint32_t active);


#endif /* INCLUDE_POWER_H_ */
/*******************************************
 * End of file power.h
 ******************************************/
