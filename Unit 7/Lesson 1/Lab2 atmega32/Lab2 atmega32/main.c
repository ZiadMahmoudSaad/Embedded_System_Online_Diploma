/*
 * Lab2 atmega32.c
 *
 * Created: 9/9/2023 4:56:30 AM
 * Author : Ziad Mahmoud Saad
 */ 
#include "platform_types.h"

#define IO_BASE	0x20
#define PORTD_R		*((vuint8_t*)(IO_BASE+0x12))
#define DDRD_R	*((vuint8_t*)(IO_BASE+0x11))
#define PIND_R		*((vuint8_t*)(IO_BASE+0x10))


void GPIO_init();
void wait(vuint32_t time);
int main(void)
{
	GPIO_init();
	while (1)
	{
		PORTD_R |= 1<<5 ;
		wait(100);
		PORTD_R &= ~(1<<5) ;
		
		PORTD_R |= 1<<6 ;
		wait(100);
		PORTD_R &= ~(1<<6) ;
		
		PORTD_R |= 1<<7 ;
		wait(100);
		PORTD_R &= ~(1<<7) ;
		
		PORTD_R |= 1<<4 ;
		wait(100);
		PORTD_R &= ~(1<<4) ;
	}
}

void GPIO_init()
{
	//pin_D4
	DDRD_R	|=	1<<4 ;
	PORTD_R &= ~(1<<4) ;
	//pin_D5
	DDRD_R	|=	1<<5 ;
	PORTD_R &= ~(1<<5) ;
	//pin_D6
	DDRD_R	|=	1<<6 ;
	PORTD_R &= ~(1<<6) ;
	//pin_D7
	DDRD_R	|=	1<<7 ;
	PORTD_R &= ~(1<<7) ;
}

void wait(vuint32_t time)
{
	vuint32_t i,j;
	for(i=0;i<time;i++)
	for(j=0;j<255;j++);
}