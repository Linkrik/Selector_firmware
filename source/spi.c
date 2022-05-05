/*******************************************
 * spi.c
 *
 *  Created on: 26.11.2021 12:59:25
 *      Author: Mikhail Leksin <LinKrik>
 *
 ******************************************/

#include "spi.h"

/*******************************************
 * Private variables
 ******************************************/
fifo_buf_count_s fifoSpiB1;
uint8_t bufferSpiB1[BUFSIZE];

/*******************************************
 * Global variables
 ******************************************/


/*******************************************
 * Initialization SPI eUSCI_B1 [Master]
 *
 * clock            8 MHz
 * bit rate         500 000 Hz
 *
 ******************************************/
void initSpi_B1_Master(){

   /*
    * Configure SPI pins
    * Select Port 4
    * Set Pin 4, Pin 5, Pin 6 and Pin 7 to input with function.
    */
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P4,
        GPIO_PIN4 + GPIO_PIN5 + GPIO_PIN6 + GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION
    );

    /* Initialize Master */
    EUSCI_B_SPI_initMasterParam param = {0};
    param.selectClockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK;
    param.clockSourceFrequency = CS_getSMCLK();
    param.desiredSpiClock = 500000;
    param.msbFirst = EUSCI_B_SPI_MSB_FIRST;
    param.clockPhase = EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT;
    param.clockPolarity = EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH;
    param.spiMode = EUSCI_B_SPI_4PIN_UCxSTE_ACTIVE_LOW;
    EUSCI_B_SPI_initMaster(EUSCI_B1_BASE, &param);

    /* Enable SPI module */
    EUSCI_B_SPI_enable(EUSCI_B1_BASE);

    EUSCI_B_SPI_clearInterrupt(EUSCI_B1_BASE,
                               EUSCI_B_SPI_RECEIVE_INTERRUPT);

    /* Enable USCI_B1 RX interrupt */
    EUSCI_B_SPI_enableInterrupt(EUSCI_B1_BASE,
                                EUSCI_B_SPI_RECEIVE_INTERRUPT);

    /* Wait for slave to initialize */
    __delay_cycles(100);


    /* Initialization buffer FIFO */
    fifoSpiB1.buffer    = bufferSpiB1;
    fifoSpiB1.head      = 0;
    fifoSpiB1.tail      = 0;
    fifoSpiB1.sizeBuf   = (uint16_t)SIZE_ARRAY(bufferSpiB1);
    fifoSpiB1.count     = 0;
}



/*******************************************
 * Initialization SPI eUSCI_B1 [Slave]
 *
 * clock            8 MHz
 * bit rate         500 000 Hz
 *
 ******************************************/
void initSpi_B1_Slave(){

   /*
    * Configure SPI pins
    * Select Port 4
    * Set Pin 4, Pin 5, Pin 6 and Pin 7 to input with function.
    */
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P4,
        GPIO_PIN4 + GPIO_PIN5 + GPIO_PIN6 + GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION
    );

    /* Initialize Master */
    EUSCI_B_SPI_initSlaveParam param = {0};
    param.msbFirst = EUSCI_B_SPI_MSB_FIRST;
    param.clockPhase = EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT;
    param.clockPolarity = EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH;
    param.spiMode = EUSCI_B_SPI_4PIN_UCxSTE_ACTIVE_LOW;
    EUSCI_B_SPI_initSlave(EUSCI_B1_BASE, &param);

    /* Enable SPI module */
    EUSCI_B_SPI_enable(EUSCI_B1_BASE);

    EUSCI_B_SPI_clearInterrupt(EUSCI_B1_BASE,
                               EUSCI_B_SPI_RECEIVE_INTERRUPT);

    /* Enable USCI_B1 RX interrupt */
    EUSCI_B_SPI_enableInterrupt(EUSCI_B1_BASE,
                                EUSCI_B_SPI_RECEIVE_INTERRUPT);

    /* Wait for slave to initialize */
    __delay_cycles(100);


    /* Initialization buffer FIFO */
    fifoSpiB1.buffer    = bufferSpiB1;
    fifoSpiB1.head      = 0;
    fifoSpiB1.tail      = 0;
    fifoSpiB1.sizeBuf   = (uint16_t)SIZE_ARRAY(bufferSpiB1);
    fifoSpiB1.count     = 0;
}



/*******************************************
 * Transmit byte SPI eUSCI_B1
 ******************************************/
void transmitByte_Spi_B1(uint8_t data){
    /* USCI_B1 TX buffer ready? */
    while (!EUSCI_B_SPI_getInterruptStatus(EUSCI_B1_BASE,EUSCI_B_SPI_TRANSMIT_INTERRUPT)) ;
    EUSCI_B_SPI_transmitData(EUSCI_B1_BASE, data);
}

/*******************************************
 * Receive byte SPI eUSCI_B1
 ******************************************/
uint8_t receiveByte_Spi_B1(){
    uint8_t value = 0;
    fifo_buf_read_cnt(&fifoSpiB1, &value);
    return value;
}


/*******************************************
 * write to buffer FIFO SPI_B_1
 ******************************************/
bool spiB1_write_byte_buffer(uint8_t dataByte){
    return fifo_buf_write_cnt(&fifoSpiB1, dataByte);
}


/*******************************************
 * Transmit data 16bit to SPI B 1
 ******************************************/
void spiB1_transmit_data_2byte(uint16_t all_data)
{
    uint8_t data_least_byte = 0;
    uint8_t data_high_byte = 0;

    data_least_byte = (all_data & 0xFF);
    data_high_byte = (all_data >> 8);

    transmitByte_Spi_B1(data_least_byte);
    transmitByte_Spi_B1(data_high_byte);

}


/*******************************************
 * Receive data 16bit to SPI B 1
 ******************************************/
uint16_t spiB1_receive_data_2byte()
{
    uint8_t  data_least_byte = 0;
    uint16_t data_high_byte = 0;
    uint16_t all_data = 0;

    data_least_byte = receiveByte_Spi_B1();
    data_high_byte  = receiveByte_Spi_B1();

    all_data = data_least_byte + (data_high_byte << 8);
    return all_data;
}


/*******************************************
 * ready to Transmit data to SPI B1
 ******************************************/
bool spiB1_ready_transmit()
{
    return (EUSCI_B_SPI_getInterruptStatus(EUSCI_B1_BASE,EUSCI_B_SPI_TRANSMIT_INTERRUPT)); //(UCB1IFG & UCTXIFG);
}


/*******************************************
 * ready to Receive data to SPI B1
 ******************************************/
bool spiB1_ready_receive_data_2bytes()
{
    return (fifoSpiB1.count >= 2);
}


/*******************************************
 * End of file uart.c
 ******************************************/
