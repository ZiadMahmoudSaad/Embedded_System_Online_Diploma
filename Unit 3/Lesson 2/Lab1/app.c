#include "uart.h"

unsigned char str[100]="Learn-in-depth";
unsigned char const str2[100]="Learn-in-depth";

void main(void)
{
	uart_send_str(str);
}