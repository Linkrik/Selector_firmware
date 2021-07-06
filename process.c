/*
 * process.c
 *
 *  Created on: 17 ìàÿ 2021 ã.
 *      Author: LinKrik
 */

#include "process.h"
#include "uart.h"

extern unsigned char ifg_rx;
unsigned char RXdataBuf = 0;

void process(uint8_t cmd)
{
    switch(cmd)
    {
        case INIT:
        {
            uart_transmit_byte(INIT);
        }
        break;

        case SHDN:
        {
            uart_transmit_byte(SHDN);
            while(ifg_rx);
            ifg_rx = 1;
            RXdataBuf = UCA1RXBUF;
            SHDN_Ñontrol(RXdataBuf);
        }
        break;

        case CHANNEL_1:
        {
            uart_transmit_byte(CHANNEL_1);
            Channel_1();                    //0.01-0.2  GGz
        }
        break;

        case CHANNEL_2:
        {
            uart_transmit_byte(CHANNEL_2);
            Channel_2();                    //0.2-0.3   GGz
        }
        break;

        case CHANNEL_3:
        {
            uart_transmit_byte(CHANNEL_3);
            Channel_3();                    //0.3-0.6   GGz
        }
        break;

        case CHANNEL_4:
        {
            uart_transmit_byte(CHANNEL_4);
            Channel_4();                    //0.6-1.0   GGz
        }
        break;

        case CHANNEL_5:
        {
            uart_transmit_byte(CHANNEL_5);
            Channel_5();                    //1.0-1.4   GGz
        }
        break;

        case CHANNEL_6:
        {
            uart_transmit_byte(CHANNEL_6);
            Channel_6();                    //1.4-1.8   GGz
        }
        break;

        case CHANNEL_7:
        {
            uart_transmit_byte(CHANNEL_7);
            Channel_7();                    //1.8-2.4   GGz
        }
        break;

        case CHANNEL_8:
        {
            uart_transmit_byte(CHANNEL_8);
            Channel_8();                    //2.4-3.0   GGz
        }
        break;

        case CHANNEL_9:
        {
            uart_transmit_byte(CHANNEL_9);
            Channel_9();                    //3.0-4.4   GGz
        }
        break;

        case CHANNEL_10:
        {
            uart_transmit_byte(CHANNEL_10);
            Channel_10();                   //4.4-6.0   GGz
        }
        break;

        case CHANNEL_11:
        {
            uart_transmit_byte(CHANNEL_11);
            Channel_11();                   //6.0-9.0   GGz
        }
        break;

        case CHANNEL_12:
        {
            uart_transmit_byte(CHANNEL_12);
            Channel_12();                   //9.0-20    GGz
        }
        break;
    }
}
