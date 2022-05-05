/*******************************************
 * byte_operations.h
 *
 *  Created on: 9.11.2021
 *      Author: Mikhail Leksin <LinKrik>
 *
 * this file makes it easier to work with bit operations
 *******************************************/

#ifndef INCLUDE_BYTE_OPERATIONS_H_
#define INCLUDE_BYTE_OPERATIONS_H_


/************************************************************
* STANDARD BITS
************************************************************/
#define BIT_0                   (0x0001)
#define BIT_1                   (0x0002)
#define BIT_2                   (0x0004)
#define BIT_3                   (0x0008)
#define BIT_4                   (0x0010)
#define BIT_5                   (0x0020)
#define BIT_6                   (0x0040)
#define BIT_7                   (0x0080)
#define BIT_8                   (0x0100)
#define BIT_9                   (0x0200)
#define BIT_A                   (0x0400)
#define BIT_B                   (0x0800)
#define BIT_C                   (0x1000)
#define BIT_D                   (0x2000)
#define BIT_E                   (0x4000)
#define BIT_F                   (0x8000)


/************************************************************
* ACTIVE BITS
************************************************************/
#define ACTIVE_BITS_0           (0x0000)    //0000 0000 0000 0000
#define ACTIVE_BITS_1           (0x0001)    //0000 0000 0000 0001
#define ACTIVE_BITS_2           (0x0003)    //0000 0000 0000 0011
#define ACTIVE_BITS_3           (0x0007)    //0000 0000 0000 0111
#define ACTIVE_BITS_4           (0x000F)    //0000 0000 0000 1111
#define ACTIVE_BITS_5           (0x001F)    //0000 0000 0001 1111
#define ACTIVE_BITS_6           (0x003F)    //0000 0000 0011 1111
#define ACTIVE_BITS_7           (0x007F)    //0000 0000 0111 1111
#define ACTIVE_BITS_8           (0x00FF)    //0000 0000 1111 1111
#define ACTIVE_BITS_9           (0x01FF)    //0000 0001 1111 1111
#define ACTIVE_BITS_10          (0x03FF)    //0000 0011 1111 1111
#define ACTIVE_BITS_11          (0x07FF)    //0000 0111 1111 1111
#define ACTIVE_BITS_12          (0x0FFF)    //0000 1111 1111 1111
#define ACTIVE_BITS_13          (0x1FFF)    //0001 1111 1111 1111
#define ACTIVE_BITS_14          (0x3FFF)    //0011 1111 1111 1111
#define ACTIVE_BITS_15          (0x7FFF)    //0111 1111 1111 1111
#define ACTIVE_BITS_16          (0xFFFF)    //1111 1111 1111 1111


/************************************************************
* LEFT ACTIVE BITS for mask (16bit)
************************************************************/

#define LEFT_ACTIVE_BITS_1_OF_16BIT            (~ACTIVE_BITS_15)    //1000 0000 0000 0000
#define LEFT_ACTIVE_BITS_2_OF_16BIT            (~ACTIVE_BITS_14)    //1100 0000 0000 0000
#define LEFT_ACTIVE_BITS_3_OF_16BIT            (~ACTIVE_BITS_13)    //1110 0000 0000 0000
#define LEFT_ACTIVE_BITS_4_OF_16BIT            (~ACTIVE_BITS_12)    //1111 0000 0000 0000
#define LEFT_ACTIVE_BITS_5_OF_16BIT            (~ACTIVE_BITS_11)    //1111 1000 0000 0000
#define LEFT_ACTIVE_BITS_6_OF_16BIT            (~ACTIVE_BITS_10)    //1111 1100 0000 0000
#define LEFT_ACTIVE_BITS_7_OF_16BIT            (~ACTIVE_BITS_9 )    //1111 1110 0000 0000
#define LEFT_ACTIVE_BITS_8_OF_16BIT            (~ACTIVE_BITS_8 )    //1111 1111 0000 0000
#define LEFT_ACTIVE_BITS_9_OF_16BIT            (~ACTIVE_BITS_7 )    //1111 1111 1000 0000
#define LEFT_ACTIVE_BITS_10_OF_16BIT           (~ACTIVE_BITS_6 )    //1111 1111 1100 0000
#define LEFT_ACTIVE_BITS_11_OF_16BIT           (~ACTIVE_BITS_5 )    //1111 1111 1110 0000
#define LEFT_ACTIVE_BITS_12_OF_16BIT           (~ACTIVE_BITS_4 )    //1111 1111 1111 0000
#define LEFT_ACTIVE_BITS_13_OF_16BIT           (~ACTIVE_BITS_3 )    //1111 1111 1111 1000
#define LEFT_ACTIVE_BITS_14_OF_16BIT           (~ACTIVE_BITS_2 )    //1111 1111 1111 1100
#define LEFT_ACTIVE_BITS_15_OF_16BIT           (~ACTIVE_BITS_1 )    //1111 1111 1111 1110


/************************************************************
* LEFT ACTIVE BITS for mask (8bit)
************************************************************/

#define LEFT_ACTIVE_BITS_1_OF_8BIT            (~ACTIVE_BITS_7)    //1000 0000
#define LEFT_ACTIVE_BITS_2_OF_8BIT            (~ACTIVE_BITS_6)    //1100 0000
#define LEFT_ACTIVE_BITS_3_OF_8BIT            (~ACTIVE_BITS_5)    //1110 0000
#define LEFT_ACTIVE_BITS_4_OF_8BIT            (~ACTIVE_BITS_4)    //1111 0000
#define LEFT_ACTIVE_BITS_5_OF_8BIT            (~ACTIVE_BITS_3)    //1111 1000
#define LEFT_ACTIVE_BITS_6_OF_8BIT            (~ACTIVE_BITS_2)    //1111 1100
#define LEFT_ACTIVE_BITS_7_OF_8BIT            (~ACTIVE_BITS_1)   //1111 1110




#endif /* INCLUDE_BYTE_OPERATIONS_H_ */
/*******************************************
 * End of file attenuators.h
 ******************************************/
