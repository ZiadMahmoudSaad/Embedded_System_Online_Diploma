/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "fifo.h"

void fifo_print_enqueue(FIFO_Buf_t* FIFO_UART,element_type item);
void fifo_print_dequeue(FIFO_Buf_t* FIFO_UART);
int main(void)
{
	element_type i ;
	FIFO_Buf_t FIFO_UART ;
	FIFO_buff_status fifo_error = FIFO_no_ERROR;

	/* FIFO initialization */
			/* uart */
	fifo_error = FIFO_init(&FIFO_UART, UART_buff, uart_width);
	if(fifo_error == FIFO_no_ERROR)
		printf("fifo init -----Done\n");
	else
		FIFO_PRINT_ERROR(fifo_error);

	for (i=0 ; i<uart_width;i++)
	{
		fifo_print_enqueue(&FIFO_UART, i);
	}

	FIFO_PRINT_ALL(&FIFO_UART);

	fifo_print_dequeue(&FIFO_UART);
	fifo_print_dequeue(&FIFO_UART);
	fifo_print_dequeue(&FIFO_UART);

	FIFO_PRINT_ALL(&FIFO_UART);

	fifo_print_enqueue(&FIFO_UART,(element_type) 5);
	fifo_print_enqueue(&FIFO_UART,(element_type) 6);
	fifo_print_enqueue(&FIFO_UART,(element_type) 7);
	fifo_print_enqueue(&FIFO_UART,(element_type) 8);

	FIFO_PRINT_ALL(&FIFO_UART);
}

void fifo_print_enqueue(FIFO_Buf_t* FIFO_UART,element_type item)
{
	FIFO_buff_status fifo_error = FIFO_no_ERROR;
	printf("FIFO Enqueue (%x)\n",item);
	fifo_error = FIFO_ENQUEUE(FIFO_UART, item);
	if(fifo_error == FIFO_no_ERROR)
		printf("fifo enqueue -----Done\n");
	else
		FIFO_PRINT_ERROR(fifo_error);
}

void fifo_print_dequeue(FIFO_Buf_t* FIFO_UART)
{
	element_type temp;
	FIFO_buff_status fifo_error = FIFO_no_ERROR;
	fifo_error = FIFO_DEQUEUE(FIFO_UART, &temp);
	if(fifo_error == FIFO_no_ERROR)
		printf("fifo dequeue %x-----Done\n",temp);
	else
		FIFO_PRINT_ERROR(fifo_error);
}
