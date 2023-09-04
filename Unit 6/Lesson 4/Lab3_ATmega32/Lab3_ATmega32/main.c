/*
 * main.c
 *
 * Created: 9/4/2023 1:38:45 AM
 *  Author: Ziad Mahmoud Saad
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#define IO_BASE	0x20

#define MCUCR_R	*((volatile unsigned char*)(IO_BASE+0x35))
#define MCUCSR_R *((volatile unsigned char*)(IO_BASE+0x34))
#define GICR_R *((volatile unsigned char*)(IO_BASE+0x3B))
#define GIFR_R *((volatile unsigned char*)(IO_BASE+0x3A))
#define SREG_R *((volatile unsigned char*)(IO_BASE+0x3F))

void interrupt_init()
{
	MCUCR_R	|=(0b1101<<0);
	MCUCSR_R	&=~(0b1<<6);
	
	GICR_R	|=(0b111<<5);
	SREG_R |= 1<<7;
	
}

int main(void)
{
	interrupt_init();
	DDRD |= (0b111<<5) ; 
    while(1)
	{
		PORTD &= ~(0b111<<5);
	}
}

ISR(INT0_vect)
{
	PORTD |= 1<<5;
	_delay_ms(100);
}

ISR(INT1_vect)
{
	PORTD |= 1<<6;
	_delay_ms(100);
}

ISR(INT2_vect)
{
	PORTD |= 1<<7 ;
	_delay_ms(100);

}