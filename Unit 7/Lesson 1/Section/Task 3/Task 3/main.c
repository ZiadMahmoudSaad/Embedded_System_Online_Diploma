/*
 * Task 3.c
 *
 * Created: 9/11/2023 8:16:56 AM
 * Author : Ziad Mahmoud Saad
 */ 

#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void GPIO_init();


int main(void)
{
	GPIO_init();
	sint8_t i,j,t,flag=5;
    while (1) 
    {
		//BUZZER
		if(READBIT(PIND,0)==1)
		{
			SETBIT(PORTD,4);
			_delay_ms(500);
			RESETBIT(PORTD,4);
			while(READBIT(PIND,0)==1);
		}
		
		//LED TOGGLE
		if(READBIT(PIND,1)==1)
		{
			if(flag!=8)
			{
				SETBIT(PORTD,flag);
				flag++;
			}
			else
			{
				RESETBIT(PORTD,5);
				RESETBIT(PORTD,6);
				RESETBIT(PORTD,7);
				flag=5;	
			}
			while(READBIT(PIND,1)==1);
		}
		
		//7segment
		if(READBIT(PIND,2)==1)
		{
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					for (t=0;t<10;t++)
					{
						PORTC = 0b1011 |(i<<4);
						_delay_ms(40);
						PORTC = 0b0111 |(j<<4);
						_delay_ms(40);
					}
					
				}
			}
			PORTC =0;
			while(READBIT(PIND,2)==1);
		}
    }
}

void GPIO_init()
{
	//set PORTD4,5,6,7 as an OUTPUT
	SETBIT(DDRD,4);
	SETBIT(DDRD,5);
	SETBIT(DDRD,6);
	SETBIT(DDRD,7);
	
	//set PORTD4,5,6,7 as an INPUT(PULL-UP)
	RESETBIT(DDRD,0);
	RESETBIT(DDRD,1);
	RESETBIT(DDRD,2);
	SETBIT(PORTD,0);
	SETBIT(PORTD,1);
	SETBIT(PORTD,2);
	
	//set PORTC2,3,4,5,6,7 as an OUTPUT
	SETBIT(DDRC,2);
	SETBIT(DDRC,3);
	SETBIT(DDRC,4);
	SETBIT(DDRC,5);
	SETBIT(DDRC,6);
	SETBIT(DDRC,7);
}