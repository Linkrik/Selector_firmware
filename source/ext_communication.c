/*******************************************
 * ext_communication.c
 *
 *  Created on: 15.04.2022 17:10:05
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

/*******************************************
 * Include
 *******************************************/
#include "ext_communication.h"


/*******************************************
 * Global variables
 ******************************************/
stdChannel_s Uart1_channel;
stdChannel_s Spi1_channel;


/*******************************************
 * Private function prototypes
 ******************************************/

/* Uart1_channel methods */
bool     Ch_Uart1_HaveWord   (void);
uint16_t Ch_Uart1_GetWord    (void);
bool     Ch_Uart1_CanTransmit(void);
void     Ch_Uart1_PutWord    (uint16_t data);


/* Spi1_channel methods */
bool     Ch_Spi1_HaveWord   (void);
uint16_t Ch_Spi1_GetWord    (void);
bool     Ch_Spi1_CanTransmit(void);
void     Ch_Spi1_PutWord    (uint16_t data);

/* All_channels methods */
void     Ch_RunCommand(uint16_t cmd,  uint16_t rxData[], uint16_t txData[]) ;


/*******************************************
 * running STD_Process for all channels
 ******************************************/
void starting_STD_Process(){
    STD_Process(&Uart1_channel);
//    STD_Process(&Spi1_channel);
}


/*******************************************
 * Initialization external communication
 ******************************************/
void Communication_Init(void) {
    //Uart1_channel initialization
    Uart1_channel.data_size       = STD_PROTOCOL_DATA_SIZE_16_BIT;

    Uart1_channel.STD_HaveWord    = Ch_Uart1_HaveWord;
    Uart1_channel.STD_GetWord     = Ch_Uart1_GetWord;
    Uart1_channel.STD_CanTransmit = Ch_Uart1_CanTransmit;
    Uart1_channel.STD_PutWord     = Ch_Uart1_PutWord;
    Uart1_channel.STD_Run         = Ch_RunCommand;

    Uart1_channel.timer_en        = false;

    STD_Init(&Uart1_channel);


    //Spi1_channel initialization
    Spi1_channel.data_size       = STD_PROTOCOL_DATA_SIZE_16_BIT;

    Spi1_channel.STD_HaveWord    = Ch_Spi1_HaveWord;
    Spi1_channel.STD_GetWord     = Ch_Spi1_GetWord;
    Spi1_channel.STD_CanTransmit = Ch_Spi1_CanTransmit;
    Spi1_channel.STD_PutWord     = Ch_Spi1_PutWord;
    Spi1_channel.STD_Run         = Ch_RunCommand;

    Spi1_channel.timer_en        = false;

    STD_Init(&Spi1_channel);
}


/*******************************************
 * HaveWord function
 ******************************************/
bool Ch_Uart1_HaveWord(void) {
    bool status = true;
    status = uart1_ready_receive_data_2bytes();
    return status;
}

bool Ch_Spi1_HaveWord(void) {
    bool status = true;

    /* TODO: Have 16-bit word for receive ? */

    return status;
}

/*******************************************
 * GetWord function
 ******************************************/
uint16_t Ch_Uart1_GetWord(void) {
    uint16_t data = 0;
    data = uart1_receive_data_2byte();
    return data;
}

uint16_t Ch_Spi1_GetWord(void) {
    uint16_t data = 0;

    /* TODO: Get 16-bit word from communication channel and save in data */

    return data;
}
/*******************************************
 * CanTransmit function
 ******************************************/
bool Ch_Uart1_CanTransmit(void) {
    bool status = true;
    status = uart1_ready_transmit();
    return status;
}

bool Ch_Spi1_CanTransmit(void) {
    bool status = true;

    /* TODO: Can transmit 16-bit word ? */

    return status;
}

/*******************************************
 * PutWord function
 ******************************************/
void Ch_Uart1_PutWord(uint16_t data) {
    uart1_transmit_data_2byte(data);
}

void Ch_Spi1_PutWord(uint16_t data) {
    /* TODO: Transmit 16-bit word (data) by communication channel */
}

/*******************************************
 * Run function for SpiCh communication
 ******************************************/
void Ch_RunCommand(uint16_t cmd,  uint16_t rxData[], uint16_t txData[]) {
    switch (cmd) {
        case STD_PROTOCOL_CMDID_GETID : {
            action_cmdid_getid(txData);
        } break;

        case STD_PROTOCOL_CMDID_SETID : {
            action_cmdid_setid(rxData);
        } break;

        case STD_PROTOCOL_CMDID_RDREL : {

        } break;

        case STD_PROTOCOL_CMDID_WRREL : {
        } break;

        case STD_PROTOCOL_CMDID_RDABS : {
        } break;

        case STD_PROTOCOL_CMDID_WRABS : {
        } break;

        case STD_PROTOCOL_CMDID_VER : {
        } break;

        case STD_PROTOCOL_CMDID_STAT : {
        } break;

        case STD_PROTOCOL_CMDID_PING : {
        } break;

        case STD_PROTOCOL_CMDID_TEMP : {
        } break;

        case STD_PROTOCOL_CMDID_PWRSEL : {
        } break;

        case STD_PROTOCOL_CMDID_GETATT : {
        } break;

        case STD_PROTOCOL_CMDID_SETATT : {
        } break;
    }
}


/*******************************************
 * End of file ext_communication.c
 *******************************************/
