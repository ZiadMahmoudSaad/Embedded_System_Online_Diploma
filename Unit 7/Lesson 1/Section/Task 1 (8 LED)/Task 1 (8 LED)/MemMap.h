/*
 * MemMap.h
 *
 * Created: 9/10/2023 5:36:18 PM
 *  Author: Ziad Mahmoud Saad
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "platform_types.h"

#define PORTA	(*(vuint8_t *)0x3B)
#define DDRA	(*(vuint8_t *)0x3A)
#define PINA	(*(vuint8_t *)0x39)

#define PORTB	(*(vuint8_t *)0x38)
#define DDRB	(*(vuint8_t *)0x37)
#define PINB	(*(vuint8_t *)0x36)

#define PORTC	(*(vuint8_t *)0x35)
#define DDRC	(*(vuint8_t *)0x34)
#define PINC	(*(vuint8_t *)0x33)

#define PORTD	(*(vuint8_t *)0x32)
#define DDRD	(*(vuint8_t *)0x31)
#define PIND	(*(vuint8_t *)0x30)



#endif /* MEMMAP_H_ */