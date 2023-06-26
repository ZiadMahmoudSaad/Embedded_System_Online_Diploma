/*
 * EX4.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	float num;

	printf("Enter a number: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&num);

	if(num>0)
		printf("%6.2f is positive.",num);
	else if(num<0)
		printf("%6.2f is negative.",num);
	else
		printf("You entered zero");
}
