/*
 * UART.h
 *
 * Created: 10/7/2023 3:32:18 PM
 *  Author: Ziad Mahmoud Saad
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

//#define UDR_t *((volatile char *) 0x2C)
//#define UCSRA_t *((volatile char *) 0x2B)
//#define UCSRB_t *((volatile char *) 0x2A)
//#define UCSRC_t *((volatile char *) 0x40)
//#define UBRRL_t *((volatile char *) 0x29)
//#define UBBRH_t *((volatile char *) 0x40)

void UART_Init();
void UART_Send(uint8_t data);
uint8_t UART_Receive();
void UART_Receive_String(char * buf);
void UART_Send_Number(uint32_t num);
uint32_t UART_Receive_Number();

#endif /* UART_H_ */