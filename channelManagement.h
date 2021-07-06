/*
 * channelManagement.h
 *
 *  Created on: 17 мая 2021 г.
 *      Author: LinKrik
 */

#ifndef CHANNELMANAGEMENT_H_
#define CHANNELMANAGEMENT_H_

#include "driverlib.h"



typedef enum
{
    KEY_VALUE_0         = 0x00, //000
    KEY_VALUE_1         = 0x01, //001
    KEY_VALUE_2         = 0x02, //010
    KEY_VALUE_3         = 0x03, //011
    KEY_VALUE_4         = 0x04, //100
    KEY_VALUE_5         = 0x05,  //101
    KEY_VALUE_6         = 0x06  //110
};
extern uint8_t is_key;



//Методы активации нужного канала
void Channel_1();    //0.01-0.2  GGz
void Channel_2();    //0.2-0.3   GGz
void Channel_3();    //0.3-0.6   GGz
void Channel_4();    //0.6-1.0   GGz
void Channel_5();    //1.0-1.4   GGz
void Channel_6();    //1.4-1.8   GGz
void Channel_7();    //1.8-2.4   GGz
void Channel_8();    //2.4-3.0   GGz
void Channel_9();    //3.0-4.4   GGz
void Channel_10();   //4.4-6.0   GGz
void Channel_11();   //6.0-9.0   GGz
void Channel_12();   //9.0-20    GGz

void SHDN_Сontrol(unsigned char activate);

//Методы для побитового сдвига
uint8_t DA_2(uint8_t key_value);
uint8_t DA_3(uint8_t key_value);
uint8_t DA_4(uint8_t key_value);
uint8_t DA_6(uint8_t key_value);
uint8_t DA_7(uint8_t key_value);
uint8_t DA_8(uint8_t key_value);
uint8_t DA_9(uint8_t key_value);

#endif /* CHANNELMANAGEMENT_H_ */
