/*
 * EX8.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	char operator;
	float num1, num2, sum;

	try_again:
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&operator);

	printf("Enter two operands: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f %f", &num1, &num2);

	switch(operator)
	{
	case '+':
		sum= num1+ num2;
		break;
	case '-':
		sum= num1 - num2;
		break;
	case '*':
		sum= num1 * num2;
		break;
	case '/':
		sum=num1 / num2;
		break;
	default:
		printf("Wrong operator, try again.\n");
		goto try_again;
		break;
	}
	printf("%f %c %f = %f", num1, operator, num2, sum);
}
