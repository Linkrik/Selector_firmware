/*******************************************
 * uart.c
 *
 *  Created on: 13.10.2021 12:59:25
 *      Author: Mikhail Leksin <LinKrik>
 *
 *
 *
 ******************************************/
#include "uart.h"

/*******************************************
 * Private variables
 ******************************************/
fifo_buf_count_s fifoUart1;
uint8_t bufferUart1[BUFSIZE];


/*******************************************
 * Global variables
 ******************************************/



/*******************************************
 * Initialization UART 1
 ******************************************/
void initUART1()
{
    /* Configure UART pins */
    P4SEL0 |= BIT2 | BIT3;

    /* Configure USCI_A1 for UART mode */
    UCA1CTLW0 |= UCSWRST | UCSSEL__SMCLK;

    UCA1BR0 = 4;
    UCA1BR1 = 0x00;
    UCA1MCTLW = 0x4900 | UCOS16 | UCBRF_5 ;

    UCA1CTLW0 &= ~UCSWRST;
    UCA1IE |= UCRXIE;

    /* Initialization buffer FIFO */
    fifoUart1.buffer    = bufferUart1;
    fifoUart1.head      = 0;
    fifoUart1.tail      = 0;
    fifoUart1.sizeBuf   = (uint16_t)SIZE_ARRAY(bufferUart1);
    fifoUart1.count     = 0;
}



/*******************************************
 * Receive data to UART 1
 ******************************************/
uint8_t uart1_receive_byte()
{
       uint8_t value = 0;
       fifo_buf_read_cnt(&fifoUart1, &value);
       return value;
}


/*******************************************
 * Transmit data to UART 1
 ******************************************/
void uart1_transmit_byte(uint8_t byte)
{
    while(!(UCA1IFG & UCTXIFG));
    UCA1TXBUF = byte;
}


/*******************************************
 * Transmit data 16bit to UART 1
 ******************************************/
void uart1_transmit_data_2byte(uint16_t all_data)
{
    uint8_t data_least_byte = 0;
    uint8_t data_high_byte = 0;

    data_least_byte = (all_data & 0xFF);
    data_high_byte = (all_data >> 8);

    uart1_transmit_byte(data_least_byte);
    uart1_transmit_byte(data_high_byte);
}


/*******************************************
 * Receive data 16bit to UART 1
 ******************************************/
uint16_t uart1_receive_data_2byte()
{
    uint8_t  data_least_byte = 0;
    uint16_t data_high_byte = 0;
    uint16_t all_data = 0;

    data_least_byte = uart1_receive_byte();
    data_high_byte  = uart1_receive_byte();

    all_data = data_least_byte + (data_high_byte << 8);
    return all_data;
}


/*******************************************
 * ready to Transmit data to UART 1
 ******************************************/
bool uart1_ready_transmit()
{
    return (UCA1IFG & UCTXIFG);
}


/*******************************************
 * ready to Receive data to UART 1
 ******************************************/
bool uart1_ready_receive_data_2bytes()
{
    return (fifoUart1.count >= 2);
}


/*******************************************
 * write to buffer FIFO
 ******************************************/
bool uart1_write_byte_buffer(uint8_t dataByte){
    return fifo_buf_write_cnt(&fifoUart1, dataByte);
}


/*******************************************
 * End of file uart.c
 ******************************************/
