/*******************************************
 * fram_msp430fr2xx_4xx.c
 *
 *  Created on: 22.10.2021 9:20
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/
#include "fram_msp430fr2xx_4xx.h"

/*******************************************
 * Writing to FRAM memory at "address" 16bit data "data"
 ******************************************/
void FRAM_Write_UINT16 (uint16_t address, uint16_t data){
    uint16_t *FRAM_write_ptr;
    FRAM_write_ptr = (uint16_t*)address;

    __bic_SR_register(GIE);
    SYSCFG0 = FRWPPW | PFWP;
    *FRAM_write_ptr =  data;
    SYSCFG0 = FRWPPW | PFWP | DFWP;
    __bis_SR_register(GIE);
}


/*******************************************
 * Reading from FRAM memory at "address" 16bit data "data"
 ******************************************/
uint16_t FRAM_Read_UINT16 (uint16_t address){
    uint16_t *FRAM_read_ptr;
    uint16_t data;
    FRAM_read_ptr = (uint16_t*)address;
    data = *FRAM_read_ptr;
    return data;
}


/*******************************************
 * End of file fram_msp430fr2xx_4xx.c
 ******************************************/
