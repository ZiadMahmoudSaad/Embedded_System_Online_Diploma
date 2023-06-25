/*
 * EX5.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	char x;
	printf("Enter a character: ");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c = %d",x,x);
}
