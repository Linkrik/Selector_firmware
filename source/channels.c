/*******************************************
 * channels.c
 *
 *  Created on: 25.04.2022 11:05:42
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

/*******************************************
 * Include
 *******************************************/
#include "channels.h"

/*******************************************
 * Global variables
 ******************************************/

/*******************************************
 * Private variables
 *******************************************/

/*******************************************
 * Private function
 ******************************************/
void Channel_1();    //0.01-0.2  GHz
void Channel_2();    //0.2-0.3   GHz
void Channel_3();    //0.3-0.6   GHz
void Channel_4();    //0.6-1.0   GHz
void Channel_5();    //1.0-1.4   GHz
void Channel_6();    //1.4-1.8   GHz
void Channel_7();    //1.8-2.4   GHz
void Channel_8();    //2.4-3.0   GHz
void Channel_9();    //3.0-4.4   GHz
void Channel_10();   //4.4-6.0   GHz
void Channel_11();   //6.0-9.0   GHz
void Channel_12();   //9.0-20    GHz

uint8_t DA_2(uint8_t key_value);
uint8_t DA_3(uint8_t key_value);
uint8_t DA_4(uint8_t key_value);
uint8_t DA_6(uint8_t key_value);
uint8_t DA_7(uint8_t key_value);
uint8_t DA_8(uint8_t key_value);
uint8_t DA_9(uint8_t key_value);



/******************************************
 * Switch channels in MHz
 ******************************************/
void switch_channels_mhz(uint16_t MHz){

    /* Channel [1]       0.01-0.2  GHz */
    if( (10 <= MHz) && (MHz <= 200) ){
        Channel_1();
    }

    /* Channel [2]       0.2-0.3   GHz */
    else if( (200 <= MHz) && (MHz <= 300) ){
        Channel_2();
    }

    /* Channel [3]       0.3-0.6   GHz */
    else if( (300 <= MHz) && (MHz <= 600) ){
        Channel_3();
    }

    /* Channel [4]       0.6-1.0   GHz */
    else if( (600 <= MHz) && (MHz <= 1000) ){
        Channel_4();
    }

    /* Channel [5]       1.0-1.4   GHz */
    else if( (1000 <= MHz) && (MHz <= 1400) ){
        Channel_5();
    }

    /* Channel [6]       1.4-1.8   GHz */
    else if( (1400 <= MHz) && (MHz <= 1800) ){
        Channel_6();
    }

    /* Channel [7]       1.8-2.4   GHz */
    else if( (1800 <= MHz) && (MHz <= 2400) ){
        Channel_7();
    }

    /* Channel [8]       2.4-3.0   GHz */
    else if( (2400 <= MHz) && (MHz <= 3000) ){
        Channel_8();
    }

    /* Channel [9]       3.0-4.4   GHz */
    else if( (3000 <= MHz) && (MHz <= 4400) ){
        Channel_9();
    }

    /* Channel [10]      4.4-6.0   GHz */
    else if( (4400 <= MHz) && (MHz <= 6000) ){
        Channel_10();
    }

    /* Channel [11]      6.0-9.0   GHz */
    else if( (6000 <= MHz) && (MHz <= 9000) ){
        Channel_11();
    }

    /* Channel [12]      9.0-20    GHz */
    else if( (9000 <= MHz) && (MHz <= 20000) ){
        Channel_12();
    }

    /* out of range */
    else{
        return;
    }
}


/******************************************
 * Channels
 * ****************************************/
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


/******************************************
 * DA keys
 * ****************************************/
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



/*******************************************
 * End of file channels.c
 *******************************************/
