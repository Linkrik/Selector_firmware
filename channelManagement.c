/*
 * channelManagement.cpp
 *
 *  Created on: 17 мая 2021 г.
 *      Author: LinKrik
 */

#include "channelManagement.h"

//Методы активации нужного канала
void Channel_1()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_3)|
            DA_6(KEY_VALUE_0)|
            DA_7(KEY_VALUE_3);
}

void Channel_2()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_0)|
            DA_7(KEY_VALUE_3);
}

void Channel_3()
{
    P2OUT = DA_2(KEY_VALUE_5)|
            DA_3(KEY_VALUE_4)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_0)|
            DA_7(KEY_VALUE_3);
}

void Channel_4()
{
    P2OUT = DA_2(KEY_VALUE_1)|
            DA_3(KEY_VALUE_2)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_0)|
            DA_7(KEY_VALUE_3);
}

void Channel_5()
{
    P2OUT = DA_2(KEY_VALUE_2)|
            DA_3(KEY_VALUE_1)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_0)|
            DA_7(KEY_VALUE_3);
}

void Channel_6()
{
    P2OUT = DA_2(KEY_VALUE_6)|
            DA_3(KEY_VALUE_6)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_0)|
            DA_7(KEY_VALUE_3);
}

void Channel_7()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_2)|
            DA_7(KEY_VALUE_2);
}

void Channel_8()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_1);
    P3OUT = DA_9(KEY_VALUE_2)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_2)|
            DA_7(KEY_VALUE_2);
}

void Channel_9()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_2);
    P3OUT = DA_9(KEY_VALUE_1)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_2)|
            DA_7(KEY_VALUE_2);
}

void Channel_10()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_3);
    P3OUT = DA_9(KEY_VALUE_0)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_2)|
            DA_7(KEY_VALUE_2);
}

void Channel_11()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_1)|
            DA_7(KEY_VALUE_1);
}

void Channel_12()
{
    P2OUT = DA_2(KEY_VALUE_4)|
            DA_3(KEY_VALUE_5)|
            DA_8(KEY_VALUE_0);
    P3OUT = DA_9(KEY_VALUE_3)|
            DA_4(KEY_VALUE_2)|
            DA_6(KEY_VALUE_3)|
            DA_7(KEY_VALUE_0);
}

void SHDN_Сontrol (unsigned char activate)
{
    if(activate==1)
    {
        P4OUT |= BIT5;
    }
    else
    {
        P4OUT &= ~BIT5;
    }
}



//Методы для побитового сдвига

uint8_t DA_2(uint8_t key_value)
{
    return key_value;
}

uint8_t DA_3(uint8_t key_value)
{
    return key_value<<3;
}

uint8_t DA_4(uint8_t key_value)
{
    return key_value<<2;
}

uint8_t DA_6(uint8_t key_value)
{

    return key_value<<4;
}

uint8_t DA_7(uint8_t key_value)
{
    return key_value<<6;
}

uint8_t DA_8(uint8_t key_value)
{
    return key_value<<6;
}

uint8_t DA_9(uint8_t key_value)
{
    return key_value;
}




