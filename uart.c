/*
 * uart.c
 *
 *  Created on: 17 мая 2021 г.
 *      Author: LinKrik
 */
#include <msp430.h>
#include "uart.h"


void initUART_8MHz()
{
    // Configure UART pins
    P4SEL0 |= BIT2 | BIT3;                    // set 2-UART pin as second function

    // Configure USCI_A0 for UART mode
    UCA1CTLW0 |= UCSWRST | UCSSEL__SMCLK;     //Четность(отключена);
                                              //Направление сдвига(сначала младший бит)
                                              //Колличество битов в посылке(8 бит)
                                              //Кол-во стоп битов (1)
                                              //UART
                                              //Синхронный режим
                                              //Источник часов (SMCLK)
                                              // Put eUSCI in reset

        // Baud Rate calculation
        // 8000000/(16*115200) = 4.34
        // Fractional portion = 0.34
        // User's Guide Table 22-4: UCBRSx = 0x49
        // UCBRFx = int ( (4.34-4)*16) = 5
    UCA1BR0 = 4;                             // 8000000/16/115200
    UCA1BR1 = 0x00;
    UCA1MCTLW = 0x4900 | UCOS16 | UCBRF_5 ;

    UCA1CTLW0 &= ~UCSWRST;                    // Initialize eUSCI
    UCA1IE |= UCRXIE;                  // Enable USCI_A1 RX interrupt
}

void initUART_1MHz()
{
    // Configure UART pins
    P4SEL0 |= BIT2 | BIT3;                    // set 2-UART pin as second function
    //P1SEL0 |= BIT6 | BIT7;

    // Configure USCI_A0 for UART mode
    UCA1CTLW0 |= UCSWRST | UCSSEL__SMCLK;     //Четность(отключена);
                                              //Направление сдвига(сначала младший бит)
                                              //Колличество битов в посылке(8 бит)
                                              //Кол-во стоп битов (1)
                                              //UART
                                              //Синхронный режим
                                              //Источник часов (SMCLK)
                                              // Put eUSCI in reset

        // Baud Rate calculation
        // 8000000/(16*115200) = 4.34
        // Fractional portion = 0.34
        // User's Guide Table 22-4: UCBRSx = 0x49
        // UCBRFx = int ( (4.34-4)*16) = 5
    UCA1BR0 = 8;                             // 1000000/16/115200
    UCA1BR1 = 0x00;
    UCA1MCTLW = 0xD600 ;

    UCA1CTLW0 &= ~UCSWRST;                    // Initialize eUSCI
    UCA1IE |= UCRXIE;                  // Enable USCI_A1 RX interrupt
}


void uart_transmit_byte(unsigned char byte)
{
    while(!(UCA1IFG & UCTXIFG));
    UCA1TXBUF = byte;                         /** transmit the same character on terminal*/
}



