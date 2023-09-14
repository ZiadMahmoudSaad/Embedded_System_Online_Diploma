/*
 * Task 2 (3 LED TOGGLE).c
 *
 * Created: 9/11/2023 3:10:59 AM
 * Author : Ziad Mahmoud Saad
 */ 

#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	SETBIT(DDRA,0);
	SETBIT(DDRA,1);
	SETBIT(DDRA,2);
	PORTA =0;
	SETBIT(DDRC,0);
	SETBIT(PORTC,0);
	sint8_t i=0;
	while (1)
	{
		if (READBIT(PINC,0)==0)
		{
			TOGGLEBIT(PORTA,i);
			while(READBIT(PINC,0)==0);
			if(i==2)
				i=0;
			else
				i++;
		}
		
		
		
	}
}

