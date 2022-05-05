/*******************************************
 * main.c
 *
 *  Created on: 1.04.2021
 *      Author: Mikhail Leksin <LinKrik>
 ******************************************/

/*******************************************
 * Includes
 ******************************************/
#include <stdio.h>
#include <msp430.h> 
#include "uart.h"
#include "clock.h"
#include "driverlib.h"
#include "ext_communication.h"

/*******************************************
 * Main function
 ******************************************/
int main(void)
{
    WDT_A_hold(WDT_A_BASE);
    PMM_unlockLPM5();

    /* Initialization */
    initClockTo8MHz();
    initUART1();
    //initSpi_B1_Slave();
    Communication_Init();


    while(1){

        if((Uart1_channel.state == STD_PROTOCOL_RECEIVE_CMDID_H)&&(Spi1_channel.state == STD_PROTOCOL_RECEIVE_CMDID_H)){
            // Since SMCLK is source, enter LPM0, interrupts enabled //LPM0_bits
            __bis_SR_register(LPM0_bits+GIE);
        }

        starting_STD_Process();
    }
}
/*******************************************
 * End of file main.c
 ******************************************/






