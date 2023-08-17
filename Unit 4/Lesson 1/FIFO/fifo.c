/*
 * fifo.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "fifo.h"

/* FIFO initialization FUNC*/
FIFO_buff_status FIFO_init(FIFO_Buf_t* fifo,element_type* buff,uint32_t length)
{
	/* Check if pointer are valid */
	if(buff == NULL)
		return FIFO_null ;

	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	fifo->length = length;
	fifo->count = 0 ;

	return FIFO_no_ERROR ;
}

/* FIFO PUSH FUNC */
FIFO_buff_status FIFO_ENQUEUE(FIFO_Buf_t* fifo,element_type item)
{
	/* Check if pointer are valid */
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null ;

	/* Check if fifo buffer is full */
	if(fifo->count == fifo->length)
		return FIFO_full ;

	*(fifo->head) = item ;
	fifo->count++ ;

	/* CHeck if fifo head at the end of he buffer */
	if(fifo->head ==(fifo->base+(fifo->length * sizeof(element_type))))
		fifo->head = fifo->base ;
	else
		fifo->head++ ;

	return FIFO_no_ERROR ;
}

/* FIFO GET FUNC */
FIFO_buff_status FIFO_DEQUEUE(FIFO_Buf_t* fifo,element_type* item)
{
	/* Check if pointer are valid */
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null ;

	/* CHeck if fifo is empty */
	if(fifo->count == 0)
		return FIFO_empty ;

	*item = *(fifo->tail) ;
	fifo->count-- ;

	/* CHeck if fifo tail at the end of the buffer */
	if(fifo->tail == (fifo->base+(fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base ;
	else
		fifo->tail++ ;

	return FIFO_no_ERROR ;
}

/* FIFO PRINT ERROR FUNC */
void FIFO_PRINT_ERROR(FIFO_buff_status FIFO_ERROR)
{
	if(FIFO_ERROR == FIFO_empty)
	{
		printf("\nFIFO_Buff is Empty\n") ;
	}
	else if(FIFO_ERROR == FIFO_full)
	{
		printf("\nFIFO_Buff is Full\n") ;
	}
	else if(FIFO_ERROR == FIFO_null)
	{
		printf("\nFIFO_Buff is not valid\n") ;
	}
}

/* FIFO PRINT ALL Buffer FUNC */
void FIFO_PRINT_ALL(FIFO_Buf_t* fifo)
{
	element_type* temp ;
	int i;
	if(fifo->count == 0)
		printf("fifo is empty\n") ;
	else
	{
		temp=fifo->tail ;

		printf("\n =============fifo_print=============\n");
		for(i=0; i<fifo->count; i++)
		{
			printf("\t %X \n",*temp) ;
			if(temp == (fifo->base + (fifo->length * sizeof(element_type))))
				temp = fifo->base ;
			else
				temp++ ;
		}
		printf("===================\n") ;
	}
}
