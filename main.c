#include <msp430.h> 
#include "uart.h"
#include "process.h"
#include "driverlib.h"


/**
 * main.c
 */
void init();


unsigned char ifg_rx;
unsigned char RXdata = 1;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	init();


	while(1)
	{
	    __bis_SR_register(LPM0_bits+GIE); // Since SMCLK is source, enter LPM0, interrupts enabled //LPM0_bits
	    RXdata = UCA1RXBUF;
        ifg_rx = 1;
	    process(RXdata);
	}
}


void init()
{
    initClockTo8MHz();
    PM5CTL0 &= ~LOCKLPM5;

    P3SEL0 = 0x00; //перевод ножек в режим gpio
    P3SEL1 = 0x00;


    P2DIR = 0xff;
    P3DIR = 0xff;

    P4OUT &= ~BIT5;
    P4DIR = BIT5;

    initUART_8MHz();
    process(10);
}

void initClockTo8MHz()
{
    // Configure one FRAM waitstate as required by the device datasheet for MCLK
    // operation beyond 8MHz _before_ configuring the clock system.
    FRCTL0 = FRCTLPW | NWAITS_1;

    __bis_SR_register(SCG0);    // disable FLL
    CSCTL3 |= SELREF__REFOCLK;  // Set REFO as FLL reference source
    CSCTL0 = 0;                 // clear DCO and MOD registers
    CSCTL1 &= ~(DCORSEL_7);     // Clear DCO frequency select bits first
    CSCTL1 = DCOFTRIMEN | DCOFTRIM0 | DCOFTRIM1 | DCORSEL_3;// DCOFTRIM=3, DCO Range = 8MHz
    CSCTL2 = FLLD_0 + 243;      // set to fDCOCLKDIV = (FLLN + 1)*(fFLLREFCLK/n)
                                //                   = (243 + 1)*(32.768 kHz/1)
                                //                   = 8 MHz
    __delay_cycles(3);
    __bic_SR_register(SCG0);                        // enable FLL
    while(CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1));      // FLL locked

    CSCTL4 = SELMS__DCOCLKDIV | SELA__REFOCLK;// set default REFO(~32768Hz) as ACLK source, ACLK = 32768Hz
    // default DCODIV as MCLK and SMCLK source
}



//********************************************************************
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A0_VECTOR))) USCI_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(UCA1IV, USCI_UART_UCTXCPTIFG))
  {
    case USCI_NONE: break;
    case USCI_UART_UCRXIFG:
        ifg_rx = 0;
        __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0 on reti
      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}







