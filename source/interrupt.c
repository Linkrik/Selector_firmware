/*******************************************
 * interrupt.c
 *
 *  Created on: 15.10.2021 11:32
 *      Author: Mikhail Leksin <LinKrik>
 ******************************************/

#include "driverlib.h"
#include "uart.h"
#include "spi.h"
#include "ext_communication.h"

uint8_t rxDataSpi;

/*******************************************
 * Initialization Interrupt UART1
 ******************************************/
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    if(__even_in_range(UCA1IV, USCI_UART_UCTXCPTIFG == USCI_UART_UCRXIFG)){ //!!!
        UCA1IFG &=~ UCRXIFG;            // Clear interrupt
        uart1_write_byte_buffer(UCA1RXBUF);
        __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0 on reti
    }
}


/*******************************************
 * Initialization Interrupt SPI_B_1
 ******************************************/
#pragma vector=USCI_B1_VECTOR
__interrupt
void USCI_B1_ISR (void)
{
    switch(__even_in_range(UCB1IV, USCI_SPI_UCTXIFG))
        {
            case USCI_NONE: break;                // Vector 0 - no interrupt

            case USCI_SPI_UCRXIFG:
                  if( Spi1_channel.state != (STD_PROTOCOL_TRANSMIT_ACK_L|STD_PROTOCOL_TRANSMIT_ACK_H|STD_PROTOCOL_TRANSMIT_DATA_L|STD_PROTOCOL_TRANSMIT_DATA_H)){
                      spiB1_write_byte_buffer(EUSCI_B_SPI_receiveData(EUSCI_B1_BASE));
                  }
                  UCA1IFG &= ~UCRXIFG;
                  __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0 on reti
                  break;

            case USCI_SPI_UCTXIFG:
                  //UCA0TXBUF = TXData;             // Transmit characters
                  UCA1IE &= ~UCTXIE;
                  break;

            default: break;
        }
}

/*******************************************
 * End of file interrupt.c
 ******************************************/
