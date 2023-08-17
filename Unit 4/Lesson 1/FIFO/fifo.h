/*
 * fifo.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"

/* USER configuration */
/* select element type */
#define element_type uint8_t

/* Create FIFO_Buffer */
/* uart buffer */
#define uart_width 5
element_type UART_buff[uart_width];


/* FIFO Data type */
typedef struct
{
	unsigned int length	;
	unsigned int count 	;
	element_type* base	;
	element_type* head	;
	element_type* tail	;
}FIFO_Buf_t;

/* fifo status */
typedef enum
{
	FIFO_no_ERROR,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_buff_status;

/* APIs */
FIFO_buff_status FIFO_init(FIFO_Buf_t* fifo,element_type* buff,uint32_t length);
FIFO_buff_status FIFO_ENQUEUE(FIFO_Buf_t* fifo,element_type item);
FIFO_buff_status FIFO_DEQUEUE(FIFO_Buf_t* fifo,element_type* item);
void FIFO_PRINT_ERROR(FIFO_buff_status FIFO_ERROR);
void FIFO_PRINT_ALL(FIFO_Buf_t* fifo);


#endif /* FIFO_H_ */
