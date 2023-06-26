/*
 * EX5.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	char character;
	printf("Enter a character: ");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&character);

	if((character >= 'a'&& character <= 'z')||(character >= 'A'&& character <= 'Z'))
		printf("%c is an alphabet",character);
	else
		printf("%c is not an alphabet",character);
}
