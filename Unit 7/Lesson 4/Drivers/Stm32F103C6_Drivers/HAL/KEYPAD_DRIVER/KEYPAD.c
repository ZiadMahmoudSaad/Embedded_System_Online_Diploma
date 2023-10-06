/*
 * KEYPAD.c
 *
 *  Created on: Sep 22, 2023
 *      Author: Ziad Mahmoud Saad
 */


#include "KEYPAD.h"

int Keypad_Row[] = {R0, R1, R2, R3};
int Keypad_Col[] = {C0, C1, C2, C3};

void Keypad_init(void)
{
	PINConf.pin_mode = GPIO_MODE_Output_PUSH_PULL ;
	PINConf.pin_speed = GPIO_SPEED_10MHz ;
	PINConf.pin_number = R0 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = R1 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = R2 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = R3 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = C0 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = C1 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = C2 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;

	PINConf.pin_number = C3 ;
	GPIO_Init(KEYPAD_PORT, &PINConf) ;


	GPIO_WritePort(KEYPAD_PORT, 0xFF) ;
}

char Keypad_getkey(void)
{
	int i,j;
	//KEYPAD_PORT |=(1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
	GPIO_WritePin(KEYPAD_PORT, C0,GPIO_PIN_SET);
	GPIO_WritePin(KEYPAD_PORT, C1,GPIO_PIN_SET);
	GPIO_WritePin(KEYPAD_PORT, C2,GPIO_PIN_SET);
	GPIO_WritePin(KEYPAD_PORT, C3,GPIO_PIN_SET);
	for(i=0;i<4;i++)
	{
		//KEYPAD_PORT &= ~(1<<Keypad_Col[i]);
		GPIO_WritePin(KEYPAD_PORT, Keypad_Col[i],GPIO_PIN_RESET);
		for (j=0;j<4;j++)
		{
			if (GPIO_ReadPin(KEYPAD_PORT, Keypad_Row[j]) == 0)
			{
				while(GPIO_ReadPin(KEYPAD_PORT, Keypad_Row[j]) == 0);
				switch(i)
				{
				case 0:
					if(j==0) return '7';
					else if(j==1) return '4';
					else if(j==2) return '1';
					else if(j==3) return '?';
					break;
				case 1:
					if(j==0) return '8';
					else if(j==1) return '5';
					else if(j==2) return '2';
					else if(j==3) return '0';
					break;
				case 2:
					if(j==0) return '9';
					else if(j==1) return '6';
					else if(j==2) return '3';
					else if(j==3) return '=';
					break;
				case 3:
					if(j==0) return '/';
					else if(j==1) return '*';
					else if(j==2) return '-';
					else if(j==3) return '+';
					break;
				}
			}
		}
		GPIO_WritePin(KEYPAD_PORT, Keypad_Col[i],GPIO_PIN_SET);
	}
	return 'A';
}
