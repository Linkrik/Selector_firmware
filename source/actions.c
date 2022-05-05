/*******************************************
 * actions.c
 *
 *  Created on: 28.04.2022 16:43:05
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

/*******************************************
 * Include
 *******************************************/
#include "actions.h"

/*******************************************
 * Global variables
 ******************************************/

/*******************************************
 * Private variables
 ******************************************/

/*******************************************
 * Action CMD GETID [recording in TX 2 words 16bit ]
 ******************************************/
void action_cmdid_getid(uint16_t txData[]){
    txData[0] = FRAM_Read_UINT16(FRAM_START_IINFORMATION);
    txData[1] = FRAM_Read_UINT16(FRAM_START_IINFORMATION+SIZE_UINT16);
}


/*******************************************
 * Action CMD SETID [reading in RX 2 words 16bit ]
 ******************************************/
void action_cmdid_setid(uint16_t rxData[]){
    FRAM_Write_UINT16(FRAM_START_IINFORMATION,rxData[0]);
    FRAM_Write_UINT16(FRAM_START_IINFORMATION+SIZE_UINT16,rxData[1]);
}


/*******************************************
 * Action CMD UID [recording in TX 8 words 16bit ]
 ******************************************/
void action_cmdid_uid(uint16_t txData[]){

}


/*******************************************
 * Action CMD RDREL [reading in RX 2 word 16bit | recording in TX N word 16bit ]
 ******************************************/
void action_cmdid_rdrel(uint16_t rxData[], uint16_t txData[]){

}


/*******************************************
 * Action CMD WRREL [reading in RX 2+N word 16bit ]
 ******************************************/
void action_cmdid_wrrel(uint16_t rxData[]){

}


/*******************************************
 * Action CMD RDABS [reading in RX 2 word 16bit | recording in TX 2 word 16bit ]
 ******************************************/
void action_cmdid_rdabs(uint16_t rxData[], uint16_t txData[]){

}


/*******************************************
 * Action CMD WRABS [reading in RX 4 word 16bit ]
 ******************************************/
void action_cmdid_wrabs(uint16_t rxData[]){

}


/*******************************************
 * Action CMD VER [recording in TX 4 word 16bit ]
 ******************************************/
void action_cmdid_ver(uint16_t txData[]){

}


/*******************************************
 * Action CMD PING [reading in RX 1 word 16bit | recording in TX N word 16bit ]
 ******************************************/
void action_cmdid_ping(uint16_t rxData[], uint16_t txData[]){

}


/*******************************************
 * Action CMD PWRSEL [reading in RX 4 word 16bit ]
 ******************************************/
void action_cmdid_pwrsel(uint16_t rxData[]){

}


/*******************************************
 * Action CMD SETRFCHF [reading in RX 2 word 16bit | recording in TX N word 16bit ]
 ******************************************/
void action_cmdid_setrfchf(uint16_t rxData[], uint16_t txData[]){

}


/*******************************************
 * Action CMD GETRFCHF [recording in TX 1 word 16bit ]
 ******************************************/
void action_cmdid_getrfchf(uint16_t txData[]){

}

/*******************************************
 * End of file actions.c
 *******************************************/
