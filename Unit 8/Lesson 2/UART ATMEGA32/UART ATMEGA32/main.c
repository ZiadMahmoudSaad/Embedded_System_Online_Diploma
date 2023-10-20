/*
 * UART ATMEGA32.c
 *
 * Created: 10/7/2023 3:30:01 PM
 * Author : Ziad Mahmoud Saad
 */ 

#include "MCAL/UART/UART.h"
#include "HAL/LCD/LCD.h"

int main(void)
{
	char x;
	char txt[100];
	UART_Init();
	LCD_init();
	UART_Send('Z');
	UART_Send('i');
	UART_Send('a');
	UART_Send('d');
	LCD_WRITE_STRING("ziad");
    /* Replace with your application code */
    while (1) 
    {
		UART_Receive_String(txt);
		LCD_WRITE_STRING(txt);
    }
}

