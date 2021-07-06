/*
 * process.h
 *
 *  Created on: 17 мая 2021 г.
 *      Author: LinKrik
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include "channelManagement.h"
#include "driverlib.h"

typedef enum
{
  INIT          = 0xC8,
  SHDN          = 0x05,
  CHANNEL_1     = 0x0A,
  CHANNEL_2     = 0x14,
  CHANNEL_3     = 0x1E,
  CHANNEL_4     = 0x28,
  CHANNEL_5     = 0x32,
  CHANNEL_6     = 0x3C,
  CHANNEL_7     = 0x46,
  CHANNEL_8     = 0x50,
  CHANNEL_9     = 0x5A,
  CHANNEL_10    = 0x64,
  CHANNEL_11    = 0x6E,
  CHANNEL_12    = 0x78
};
extern uint8_t is_cmd;

void process(uint8_t cmd);

#endif /* PROCESS_H_ */
