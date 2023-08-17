/*
 * lifo.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "lifo.h"

LIFO_buff_status LIFO_init(LIFO_Buf_t* lifo,element_type* buff,uint32_t length)
{
	/* Check if pointer are valid */
	if(buff == NULL)
		return LIFO_null ;

	lifo->base = buff;
	lifo->head = buff;
	lifo->length = length;
	lifo->count = 0;

	return LIFO_no_ERROR ;
}

LIFO_buff_status LIFO_PUSH(LIFO_Buf_t* lifo,element_type item)
{
	/* Check if pointer are valid */
	if(!lifo->base || !lifo->head)
		return LIFO_null ;

	/* Check if Buffer not full */
	if(lifo->count == lifo->length)
		return LIFO_full ;

	*(lifo->head) = item ;
	lifo->head++ ;
	lifo->count++ ;

	return LIFO_no_ERROR ;
}

LIFO_buff_status LIFO_GET(LIFO_Buf_t* lifo,element_type* item)
{
	/* Check if pointer are valid */
	if(!lifo->base || !lifo->head)
		return LIFO_null ;

	/* Check if Buffer is empty */
	if(lifo->count == 0)
		return LIFO_empty ;

	lifo->head-- ;
	*item = *(lifo->head) ;
	lifo->count-- ;

	return LIFO_no_ERROR ;
}

void LIFO_PRINT_ERROR(LIFO_buff_status LIFO_ERROR)
{
	if(LIFO_ERROR==LIFO_empty)
	{
		printf("\nLIFO_Buff is Empty\n");
	}
	else if(LIFO_ERROR==LIFO_full)
	{
		printf("\nLIFO_Buff is Full\n");
	}
	else if(LIFO_ERROR==LIFO_null)
	{
		printf("\nLIFO_Buff is not valid\n");
	}
}
