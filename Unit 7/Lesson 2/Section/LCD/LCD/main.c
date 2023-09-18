/*
 * LCD.c
 *
 * Created: 9/15/2023 12:29:58 AM
 * Author : Ziad Mahmoud Saad
 */ 

#include "LCD_Driver/LCD.h"
int main(void)
{
	char str[]="Ziad Mahmoud Saad";
	LCD_init();
    while (1) 
    {
		LCD_WRITE_CHAR('A');
		_delay_ms(500);
		LCD_WRITE_CHAR('B');
		_delay_ms(500);
		LCD_clear_screen();
		_delay_ms(1000);
		LCD_WRITE_STRING(str);
		_delay_ms(1000);
		LCD_clear_screen();
		_delay_ms(1000);
		
    }
}

