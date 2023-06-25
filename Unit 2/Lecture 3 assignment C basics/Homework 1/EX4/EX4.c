/*
 * EX4.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	float num1,num2;
	printf("Enter two numbers: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f %f",&num1,&num2);
	printf("Product: %f",num1*num2);
}
