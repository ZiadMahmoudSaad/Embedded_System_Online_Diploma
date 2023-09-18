/*
 * LCD.c
 *
 * Created: 9/15/2023 12:40:10 AM
 *  Author: Ziad Mahmoud Saad
 */ 
#include "LCD.h"

void LCD_clear_screen(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN)	;
}

void LCD_kick(){
	LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(1);
	LCD_CTRL &= ~(1 << EN_SWITCH);
}

void LCD_init()
{
	_delay_ms(20);
	LCD_CTRL_DATADir |=(1<<EN_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH) ;
	LCD_CTRL &=~((1<<EN_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH)) ;
	LCD_DATA_DATADir = 0xFF ;
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
	_delay_ms(10);
	#ifdef EIGHT_BIT_MODE
		LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_isbusy()
{
	LCD_DATA_DATADir &= ~(0xFF<<DATA_SHIFT);
	LCD_CTRL |= 1<<RW_SWITCH ;
	LCD_CTRL &= ~(1<<RS_SWITCH);
	LCD_kick();
	LCD_DATA_DATADir |= (0xFF<<DATA_SHIFT);
	LCD_CTRL &= ~(1 << RW_SWITCH);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT_MODE
		LCD_DATA = command ;
		LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_DATA =  (LCD_DATA & 0x0F) | (command & 0xF0) ;
		LCD_kick();
		LCD_DATA =  (LCD_DATA & 0x0F) | (command << 4) ;
		LCD_kick();
	#endif

	
}

void LCD_WRITE_CHAR(char character)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT_MODE
		LCD_CTRL |= 1<<RS_SWITCH ;
		LCD_DATA = character ;
		LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_CTRL |= 1<<RS_SWITCH ;
	LCD_DATA =  (LCD_DATA & 0x0F) | (character & 0xF0) ;
	LCD_kick();
	LCD_DATA =  (LCD_DATA & 0x0F) | (character << 4) ;
	LCD_kick();
	#endif
}

void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if(line==1 && position>=0 && position<16)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
	}else if(line==2)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);	
	}
}

void LCD_WRITE_STRING(char* string)
{
	int count=0;
	while(*string!=0)
	{
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count=0;
		}
	}
}