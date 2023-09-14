/*
 * Task 1 (8 LED).c
 *
 * Created: 9/10/2023 5:34:26 PM
 * Author : Ziad Mahmoud Saad
 */ 

#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	DDRA = 0xFF ;
	PORTA =0;
	sint8_t i;
    while (1) 
    {
		for (i= 0; i<8; i++)
		{
			PORTA |= (1<<i);
			_delay_ms(500);
		}
		for (i= 7; i>=0; i--)
		{
			PORTA &= ~(1<<i);
			_delay_ms(500);
		}
		
    }
}

