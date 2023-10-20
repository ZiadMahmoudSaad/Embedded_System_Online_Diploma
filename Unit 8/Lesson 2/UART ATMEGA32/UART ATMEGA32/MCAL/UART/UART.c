/*
 * UART.c
 *
 * Created: 10/7/2023 3:32:30 PM
 *  Author: Ziad Mahmoud Saad
 */ 

#include "UART.h"


void UART_Init()
{
	UBRRL = 51 ;
	
	UCSRA &= ~(1<<U2X) ;
	
	UCSRB |=1<<TXEN;
	UCSRB |=1<<RXEN;
}

void UART_Send(uint8_t data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data ;
}

uint8_t UART_Receive()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR ;
}

void UART_Receive_String(char * buf)
{
	*buf = UART_Receive();
	while (*buf != '\r') {
		buf++;
		*buf = UART_Receive();
	}
	*buf = '\0';
}

void UART_Send_Number(uint32_t num)
{
	uint8_t *p=&num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);


}
uint32_t UART_Receive_Number()
{
	uint32_t num;
	uint8_t *p=&num;

	p[0]=UART_Receive();
	p[1]=UART_Receive();
	p[2]=UART_Receive();
	p[3]=UART_Receive();

	return num;


}