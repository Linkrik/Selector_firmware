/*******************************************
 * std_protocol.h
 *
 *  Created on: 29.07.2021 18:02:58
 *      Author: Anton Moiseev <atom>
 ******************************************/

#ifndef INCLUDE_STD_PROTOCOL_H_
#define INCLUDE_STD_PROTOCOL_H_

/*******************************************
 * Includes
 ******************************************/
#include <stdbool.h>
#include <stdint.h>

/*******************************************
 * Defines
 ******************************************/
#ifndef NULL
#define NULL                           ((void*)0)
#endif

#define STD_PROTOCOL_DATA_SIZE_8_BIT   (8)
#define STD_PROTOCOL_DATA_SIZE_16_BIT  (16)

#define STD_PROTOCOL_RECEIVE_CMDID_L   (0)
#define STD_PROTOCOL_RECEIVE_CMDID_H   (1)
#define STD_PROTOCOL_RECEIVE_FLAGS_L   (2)
#define STD_PROTOCOL_RECEIVE_FLAGS_H   (3)
#define STD_PROTOCOL_RECEIVE_PARAMS_L  (4)
#define STD_PROTOCOL_RECEIVE_PARAMS_H  (6)
#define STD_PROTOCOL_RUN_COMMAND       (7)
#define STD_PROTOCOL_TRANSMIT_ACK_L    (8)
#define STD_PROTOCOL_TRANSMIT_ACK_H    (9)
#define STD_PROTOCOL_TRANSMIT_DATA_L   (10)
#define STD_PROTOCOL_TRANSMIT_DATA_H   (11)

#define STD_PROTOCOL_BUFFER_SIZE       (100)

#define STD_PROTOCOL_ADD_POSITION      (2)

#define STD_PROTOCOL_CMDID_GETID       (0x0001)
#define STD_PROTOCOL_CMDID_SETID       (0x0002)
#define STD_PROTOCOL_CMDID_UID         (0x0003)
#define STD_PROTOCOL_CMDID_RDREL       (0x0004)
#define STD_PROTOCOL_CMDID_WRREL       (0x0005)
#define STD_PROTOCOL_CMDID_RDABS       (0x0006)
#define STD_PROTOCOL_CMDID_WRABS       (0x0007)
#define STD_PROTOCOL_CMDID_VER         (0x0008)
#define STD_PROTOCOL_CMDID_RESERVE1    (0x0009)
#define STD_PROTOCOL_CMDID_RESERVE2    (0x000a)
#define STD_PROTOCOL_CMDID_RESERVE3    (0x000b)
#define STD_PROTOCOL_CMDID_STAT        (0x000c)
#define STD_PROTOCOL_CMDID_PING        (0x000d)
#define STD_PROTOCOL_CMDID_RESERVE4    (0x000e)
#define STD_PROTOCOL_CMDID_RESERVE5    (0x000f)
#define STD_PROTOCOL_CMDID_TEMP        (0x0010)
#define STD_PROTOCOL_CMDID_PWRSEL      (0x0011)
#define STD_PROTOCOL_CMDID_GETATT      (0x0012)
#define STD_PROTOCOL_CMDID_SETATT      (0x0013)
#define STD_PROTOCOL_CMDID_GETCH       (0x0014)
#define STD_PROTOCOL_CMDID_SETCH       (0x0015)
#define STD_PROTOCOL_CMDID_UPDDELAY    (0x0016)
#define STD_PROTOCOL_CMDID_ACTCTRL     (0x0017)
#define STD_PROTOCOL_CMDID_GETPOS      (0x0018)
#define STD_PROTOCOL_CMDID_SENRAW      (0x0019)
#define STD_PROTOCOL_CMDID_QUERAW      (0x001a)
#define STD_PROTOCOL_CMDID_GETDACRSL   (0x001b)
#define STD_PROTOCOL_CMDID_SETDACVAL   (0x001c)
#define STD_PROTOCOL_CMDID_DACOES      (0x001d)

/*******************************************
 * Typedefs
 ******************************************/
typedef bool     (*STD_HaveWord_fn)    ();
typedef uint16_t (*STD_GetWord_fn)     ();
typedef bool     (*STD_CanTransmit_fn) ();
typedef void     (*STD_PutWord_fn)     (uint16_t data);
typedef void     (*STD_Run_fn)         (uint16_t cmd, uint16_t rxDataArray[], uint16_t txDataArray[]);
typedef void     (*STD_TimerInit_fn)   (uint32_t timeout_value);
typedef void     (*STD_TimerStart_fn)  ();
typedef void     (*STD_TimerStop_fn)   ();

struct __std_params {
    uint16_t rxNumberWords;
    bool     rxAddWords;
    uint16_t txNumberWords;
    bool     txAddWords;
    bool     flagsEnable;
};

typedef union {
    uint16_t all;
    struct {
        uint16_t ack     : 1;
        uint16_t update  : 1;
        uint16_t reserve : 14;
    };
} std_flags_u;

typedef struct {
    uint16_t           data_size;
    STD_HaveWord_fn    STD_HaveWord;
    STD_GetWord_fn     STD_GetWord;
    STD_CanTransmit_fn STD_CanTransmit;
    STD_PutWord_fn     STD_PutWord;
    STD_Run_fn         STD_Run;
    STD_TimerInit_fn   STD_TimerInit;
    STD_TimerStart_fn  STD_TimerStart;
    STD_TimerStop_fn   STD_TimerStop;
    uint16_t           cmdid;
    std_flags_u        flags;
    uint16_t           state;
    uint16_t           rxData[STD_PROTOCOL_BUFFER_SIZE];
    uint16_t           txData[STD_PROTOCOL_BUFFER_SIZE];
    bool               timer_en;
    bool               time_breached;
    uint32_t           timeout_value;
} stdChannel_s;

typedef stdChannel_s* stdChannel_p;

/*******************************************
 * Global variables
 ******************************************/
extern const struct __std_params std_params[];

/*******************************************
 * Public function prototypes
 ******************************************/
void STD_Init   (stdChannel_p channel);
void STD_Process(stdChannel_p channel);

#endif /* INCLUDE_STD_PROTOCOL_H_ */


/*******************************************
 * End of file std_protocol.h
 ******************************************/
