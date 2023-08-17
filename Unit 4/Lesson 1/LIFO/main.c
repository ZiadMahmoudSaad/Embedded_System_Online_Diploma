/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "lifo.h"
#define I2c_width 5

int main(void)
{
	element_type i, temp = 0 ;
	LIFO_Buf_t uart_lifo, I2C_lifo ;
	LIFO_buff_status lifo_error = LIFO_no_ERROR;
	element_type* I2c_buff= (element_type*) malloc(I2c_width * sizeof(element_type));

	/* LIFO initialization */
	/* uart */
	LIFO_init(&uart_lifo, UART_buff, uart_width);
	/* I2C */
	LIFO_init(&I2C_lifo, I2c_buff, I2c_width);

	for(i=0; i<uart_width +2; i++)
	{
		lifo_error = LIFO_PUSH(&uart_lifo , i);
		if(lifo_error==LIFO_no_ERROR)
			printf("UART_LIFO PUSH : %d\n",i);
		else
			LIFO_PRINT_ERROR(lifo_error);
	}

	for(i=0; i<uart_width+3 ; i++)
	{
		lifo_error = LIFO_GET(&uart_lifo , &temp);
		if(lifo_error==LIFO_no_ERROR)
			printf("UART_LIFO GET : %d\n",temp);
		else
			LIFO_PRINT_ERROR(lifo_error);
	}
}
