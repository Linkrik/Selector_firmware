/*******************************************
 * fifo_buffer.c
 *
 *  Created on: 02.12.2021 13:29:13
 *      Author: Mikhail Leksin <LinKrik>
 *******************************************/

/*******************************************
 * Include
 *******************************************/
#include "fifo_buffer.h"

/******************************************/
/*---The methods does not use a COUNTer---*/
/******************************************/

/*******************************************
 * write to buffer "fifo_buf_p" 1 byte "data";
 ******************************************/
bool fifo_buf_write (fifo_buf_p buf_struct, uint8_t data)
{
    int next;
    next = ((buf_struct->head + 1) % buf_struct->sizeBuf);

    if (next == buf_struct->tail) {
        return false;
    }

    buf_struct->buffer[buf_struct->head] = data;
    buf_struct->head = next;
    return true;
}

/*******************************************
 * read of buffer "fifo_buf_p" 1 byte "data";
 ******************************************/
bool fifo_buf_read (fifo_buf_p buf_struct, uint8_t *data)
{
    if (buf_struct->head == buf_struct->tail) {
        return false;
    }

    *data = buf_struct -> buffer[buf_struct->tail];
    buf_struct->tail = (buf_struct->tail + 1) % buf_struct->sizeBuf;;
    return true;
}


/*******************************************
 * data is ready to read
 ******************************************/
bool dataReady (fifo_buf_p buf_struct){
    if (buf_struct->head == buf_struct->tail) {
        return false;
    }
    return true;
}


/******************************************/
/*---    The methods use a COUNTer     ---*/
/******************************************/

/*******************************************
 * write to buffer "fifo_buf_count_p" 1 byte "data";
 ******************************************/
bool fifo_buf_write_cnt (fifo_buf_count_p buf_struct, uint8_t data)
{
    if (buf_struct->sizeBuf == buf_struct->count) return false;
    buf_struct->count ++;
    buf_struct->buffer[buf_struct->head] = data;
    buf_struct->head = ((buf_struct->head + 1) % buf_struct->sizeBuf);

    return true;
}

/*******************************************
 * read of buffer "fifo_buf_count_p" 1 byte "data";
 ******************************************/
bool fifo_buf_read_cnt (fifo_buf_count_p buf_struct, uint8_t *data)
{
    if (0 == buf_struct->count) return false;
    buf_struct->count --;
    *data = buf_struct -> buffer[buf_struct->tail];
    buf_struct->tail = (buf_struct->tail + 1) % buf_struct->sizeBuf;
    return true;
}


/*******************************************
 * End of file fifo_buffer.c
 *******************************************/
