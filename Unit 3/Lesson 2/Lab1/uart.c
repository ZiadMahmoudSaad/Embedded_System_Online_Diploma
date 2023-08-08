#include "uart.h"
#define UART0_DR *((volatile unsigned int* const)((unsigned int *)0x101f1000))

void uart_send_str(unsigned char* p_str)
{
	while(*p_str!='\0')
	{
		UART0_DR = (unsigned int)(*p_str);
		p_str++;
	}
}