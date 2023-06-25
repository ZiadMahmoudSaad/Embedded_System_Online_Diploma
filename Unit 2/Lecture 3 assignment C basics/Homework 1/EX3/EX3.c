/*
 * EX3.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	int num1, num2;
	printf("Enter two integers: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d", &num1, &num2);
	printf("Sum: %d", num1+num2);
}
