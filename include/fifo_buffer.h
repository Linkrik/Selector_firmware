/*******************************************
 * fifo_buffer.h
 *
 *  Created on: 02.12.2021 13:28:12
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/
#ifndef INCLUDE_FIFO_BUFFER_H_
#define INCLUDE_FIFO_BUFFER_H_

/*******************************************
 * Include
 *******************************************/
#include "driverlib.h"


/*******************************************
 * Defines
 ******************************************/
#define SIZE_ARRAY(x)                       (sizeof(x) / sizeof((x)[0]))


/*******************************************
 * Typedefs
 ******************************************/

/********************************************/
/*---The structure does not use a COUNTer---*/
/********************************************/
typedef struct {
    uint8_t *buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t sizeBuf;
} fifo_buf_s;

typedef fifo_buf_s* fifo_buf_p;


/******************************************/
/*---   The structure use a COUNTer    ---*/
/******************************************/
typedef struct {
    uint8_t *buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t sizeBuf;
    uint16_t count;
} fifo_buf_count_s;

typedef fifo_buf_count_s* fifo_buf_count_p;


/*******************************************
 * Public function prototypes
 ******************************************/
bool fifo_buf_write (fifo_buf_p buf_struct, uint8_t data);
bool fifo_buf_read (fifo_buf_p buf_struct, uint8_t *data);
bool fifo_buf_write_cnt (fifo_buf_count_p buf_struct, uint8_t data);
bool fifo_buf_read_cnt (fifo_buf_count_p buf_struct, uint8_t *data);
bool dataReady (fifo_buf_p buf_struct);

#endif /* INCLUDE_FIFO_BUFFER_H_ */
/*******************************************
 * End of file fifo_buffer.h
 *******************************************/
