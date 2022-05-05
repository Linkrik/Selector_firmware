/*******************************************
 * power.c
 *
 *  Created on: 17.11.2021
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

#include "power.h"

/*******************************************
 * initialization GPIO Power:
 * 1.SHDN
 ******************************************/
void initPower(){

    /* P6SEL = 00 mode GPIO*/
    P6SEL0 &= ~BIT1;
    P6SEL1 &= ~BIT1;

    /* P6.1 DIR = 1     pin is switched to output direction*/
    P6DIR |= BIT1;

    /* P6.1 OUT Clear output latch*/
    P6OUT &= ~BIT1;
}

/*******************************************
 * control power:
 * 1.SHDN
 ******************************************/
void controlPower(uint32_t select ,uint32_t active){

    /* control SHDN */
    if(select & 0x00000001){
        if(active & 0x00000001){
            P6OUT |= BIT1;
        }
        else{
            P6OUT &= ~BIT1;
        }
    }
}
/*******************************************
 * End of file attenuators.c
 ******************************************/
