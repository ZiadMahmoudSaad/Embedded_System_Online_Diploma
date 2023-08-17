/*
 * lifo.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

/* USER configuration */
/* select element type */
#define element_type uint8_t

/* Create LIFO_Buffer */
/* uart buffer */
#define uart_width 5
element_type UART_buff[uart_width];

/* LIFO Data type */
typedef struct
{
	unsigned int length	;
	unsigned int count 	;
	unsigned int* base	;
	unsigned int* head	;
}LIFO_Buf_t;

/* LIFO status */
typedef enum
{
	LIFO_no_ERROR,
	LIFO_full,
	LIFO_empty,
	LIFO_null
}LIFO_buff_status;

/* APIs */
LIFO_buff_status LIFO_init(LIFO_Buf_t* lifo,element_type* buff,uint32_t length);
LIFO_buff_status LIFO_PUSH(LIFO_Buf_t* lifo,element_type item);
LIFO_buff_status LIFO_GET(LIFO_Buf_t* lifo,element_type* item);
void LIFO_PRINT_ERROR(LIFO_buff_status LIFO_ERROR);

#endif /* LIFO_H_ */
