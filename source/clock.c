/*******************************************
 * clock.c
 *
 *  Created on: 13.10.2021 14:43:11
 *      Author: Mikhail Leksin <LinKrik>
 ******************************************/

#include "clock.h"

/*******************************************
 * Initialization CLOCK 8MHz
 ******************************************/
void initClockTo8MHz()
{
    /*******************************************
     * Configure one FRAM waitstate as required by the device datasheet for MCLK
     * operation beyond 8MHz _before_ configuring the clock system.
     */

    FRCTL0 = FRCTLPW | NWAITS_1;

    __bis_SR_register(SCG0);                                    /* disable FLL */
    CSCTL3 |= SELREF__REFOCLK;                                  /* Set REFO as FLL reference source */
    CSCTL0 = 0;                                                 /* clear DCO and MOD registers */
    CSCTL1 &= ~(DCORSEL_7);                                     /* Clear DCO frequency select bits first */
    CSCTL1 = DCOFTRIMEN | DCOFTRIM0 | DCOFTRIM1 | DCORSEL_3;    /* DCOFTRIM=3, DCO Range = 8MHz */
    CSCTL2 = FLLD_0 + 243;                                      /* set to fDCOCLKDIV = (FLLN + 1)*(fFLLREFCLK/n) = (243 + 1)*(32.768 kHz/1) = 8 MHz*/

    __delay_cycles(3);
    __bic_SR_register(SCG0);                                    /* enable FLL */
    while(CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1));                  /* FLL locked */

    CSCTL4 = SELMS__DCOCLKDIV | SELA__REFOCLK;                  /* set default REFO(~32768Hz) as ACLK source, ACLK = 32768Hz */
                                                                /* default DCODIV as MCLK and SMCLK source*/
}


/*******************************************
 * End of file clock.c
 ******************************************/
