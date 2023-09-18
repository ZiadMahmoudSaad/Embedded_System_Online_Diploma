/*
 * KEYPAD.h
 *
 * Created: 9/15/2023 6:45:23 AM
 *  Author: Ziad Mahmoud Saad
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_



#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

#define KEYPAD_PORT	PORTC
#define KEYPAD_DATADir DDRC
#define KEYPAD_PIN PINC

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

void Keypad_init(void);
char Keypad_getkey(void);

#endif /* KEYPAD_H_ */