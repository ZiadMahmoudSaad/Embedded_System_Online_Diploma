/*
 * LCD_KEYPAD.c
 *
 * Created: 9/15/2023 6:41:14 AM
 * Author : Ziad Mahmoud Saad
 */ 

#include "LCD_Driver/LCD.h"
#include "KEYPAD_Driver/KEYPAD.h"

int main(void)
{
	unsigned char pressed;
	LCD_init();
	Keypad_init();
	_delay_ms(50);
    while (1) 
    {
		pressed=Keypad_getkey();
		switch(pressed)
		{
			case 'A':
			break;
			case '?':
				LCD_clear_screen();
			break;
			default:
			LCD_WRITE_CHAR(pressed);
			break;
		}
		_delay_ms(50);
    }
}

