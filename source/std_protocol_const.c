/*******************************************
 * std_protocol_const.c
 *
 *  Created on: 25.11.2021 18:15:18
 *      Author: Anton Moiseev <atom>
 ******************************************/

#include "std_protocol.h"

/*******************************************
 * Constants:
 *   rxNumberWords - количество принимаемых слов;
 *   rxAddWords    - будет ли изменяться количество принимаемых слов;
 *   txNumberWords - количество передаваемых слов;
 *   txAddWords    - будет ли изменяться количество передаваемых слов;
 *   flagsEnable   - нужно принимать флаги;
 ******************************************/
const struct __std_params std_params [] = {
    {0, false, 0, false, false},    /* reserve,   addr: 0x0000; Receive:      0  words; Transmit:    2  words */
    {0, false, 2, false, false},    /* GETID,     addr: 0x0001; Receive:      2  words; Transmit:    0  words */
    {2, false, 0, false, false},    /* SETID,     addr: 0x0002; Receive:      0  words; Transmit:    8  words */
    {0, false, 8, false, false},    /* UID,       addr: 0x0003; Receive:      2  words; Transmit:    N  words */
    {2, false, 0, true,  false},    /* RDREL,     addr: 0x0004; Receive: (2 + N) words; Transmit:    0  words */
    {2, true,  0, false, false},    /* WRREL,     addr: 0x0005; Receive:      2  words; Transmit:    2  words */
    {2, false, 2, false, false},    /* RDABS,     addr: 0x0006; Receive:      4  words; Transmit:    0  words */
    {4, false, 0, false, false},    /* WRABS,     addr: 0x0007; Receive:      0  words; Transmit:    4  words */
    {0, false, 4, false, false},    /* VER,       addr: 0x0008;                                               */
    {0, false, 0, false, false},    /* reserve,   addr: 0x0009;                                               */
    {0, false, 0, false, false},    /* reserve,   addr: 0x000a;                                               */
    {0, false, 0, false, false},    /* reserve,   addr: 0x000b; Receive:      0  words; Transmit:    2  words */
    {0, false, 2, false, false},    /* STAT,      addr: 0x000c; Receive:      1  words; Transmit: (0/1) words */
    {1, false, 0, false, true },    /* PING,      addr: 0x000d;                                               */
    {0, false, 0, false, false},    /* reserve,   addr: 0x000e;                                               */
    {0, false, 0, false, false},    /* reserve,   addr: 0x000f; Receive:      1  words; Transmit:    1  words */
    {1, false, 1, false, false},    /* TEMP,      addr: 0x0010; Receive:      4  words; Transmit:    0  words */
    {4, false, 0, false, false},    /* PWRSEL,    addr: 0x0011; Receive:      1  words; Transmit:    1  words */
    {1, false, 1, false, false},    /* GETATT,    addr: 0x0012; Receive:      3  words; Transmit: (0/1) words */
    {3, false, 0, false, true },    /* SETATT,    addr: 0x0013; Receive:      0  words; Transmit:    1  words */
    {0, false, 1, false, false},    /* GETCH,     addr: 0x0014; Receive:      2  words; Transmit: (0/1) words */
    {2, false, 0, false, true },    /* SETCH,     addr: 0x0015; Receive:      2  words; Transmit:    0  words */
    {2, false, 0, false, false},    /* UPDDELAY,  addr: 0x0016;                                               */
    {0, false, 0, false, false},    /* ACTCTRL,   addr: 0x0017;                                               */
    {0, false, 0, false, false},    /* GETPOS,    addr: 0x0018;                                               */
    {0, false, 0, false, false},    /* SENRAW,    addr: 0x0019;                                               */
    {0, false, 0, false, false},    /* QUERAW,    addr: 0x001a;                                               */
    {1, false, 1, false, false},    /* GETDACRSL, addr: 0x0013; Receive:      1  words; Transmit:    1  words */
    {2, false, 0, false, false},    /* SETDACVAL, addr: 0x0014; Receive:      2  words; Transmit:    0  words */
    {2, false, 0, false, false},    /* DACOES,    addr: 0x0015; Receive:      2  words; Transmit:    0  words */
};

/*******************************************
 * End of file std_protocol_const.c
 ******************************************/
