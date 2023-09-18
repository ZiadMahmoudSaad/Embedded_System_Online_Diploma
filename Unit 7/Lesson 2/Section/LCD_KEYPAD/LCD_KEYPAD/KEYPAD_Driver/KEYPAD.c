/*
 * KEYPAD.c
 *
 * Created: 9/15/2023 6:45:05 AM
 *  Author: Ziad Mahmoud Saad
 */ 
#include "KEYPAD.h"

int Keypad_Row[] = {R0, R1, R2, R3};
int Keypad_Col[] = {C0, C1, C2, C3};

void Keypad_init(void)
{
	KEYPAD_DATADir &= ~(0xF);
	KEYPAD_DATADir |= 0xF0;
	KEYPAD_PORT =0xFf;
}
char Keypad_getkey(void)
{
	int i,j;
	KEYPAD_PORT |=(1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
	for(i=0;i<4;i++)
	{
		KEYPAD_PORT &= ~(1<<Keypad_Col[i]);
		for (j=0;j<4;j++)
		{
			if (!(KEYPAD_PIN & (1 << Keypad_Row[j])))
			{
				while(!(KEYPAD_PIN & (1 << Keypad_Row[j])));
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
		KEYPAD_PORT &= ~(1<<Keypad_Col[i]);
	}
	return 'A';
}