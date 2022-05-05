/*******************************************
 * actions.h
 *
 *  Created on: 28.04.2022 16:45:51
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/
#ifndef INCLUDE_ACTIONS_H_
#define INCLUDE_ACTIONS_H_

/*******************************************
 * supported commands:
 *
 * [common commands]
 * GETID        +
 * SETID        +
 * UID          -
 * RDREL        -
 * WRREL        -
 * RDABS        -
 * WRABS        -
 * VER          -
 * PING         -
 *
 * [individual commands]
 * PWRSEL       +
 * SETRFCHF     +
 * GETRFCHF     +
 *******************************************/

/*******************************************
 * Include
 *******************************************/
#include "fram_msp430fr2xx_4xx.h"
#include "driverlib.h"

/*******************************************
 * Defines
 ******************************************/

/*******************************************
 * Global variables
 ******************************************/

/*******************************************
 * Public function prototypes
 ******************************************/
void action_cmdid_getid(uint16_t txData[]);
void action_cmdid_setid(uint16_t rxData[]);
void action_cmdid_uid(uint16_t txData[]);
void action_cmdid_rdrel(uint16_t rxData[], uint16_t txData[]);
void action_cmdid_wrrel(uint16_t rxData[]);
void action_cmdid_rdabs(uint16_t rxData[], uint16_t txData[]);
void action_cmdid_wrabs(uint16_t rxData[]);
void action_cmdid_ver(uint16_t txData[]);
void action_cmdid_ping(uint16_t rxData[], uint16_t txData[]);
void action_cmdid_pwrsel(uint16_t rxData[]);
void action_cmdid_setrfchf(uint16_t rxData[], uint16_t txData[]);
void action_cmdid_getrfchf(uint16_t txData[]);


#endif /* INCLUDE_ACTIONS_H_ */
/*******************************************
 * End of file actions.h
 *******************************************/
