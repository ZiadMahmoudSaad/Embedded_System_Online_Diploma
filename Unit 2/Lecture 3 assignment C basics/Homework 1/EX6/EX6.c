/*
 * EX6.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	float a,b,temp;
	printf("Enter value of a: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&a);

	printf("Enter value of b: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&b);

	temp=a;
	a=b;
	b=temp;

	printf("\nAfter swapping, value of a = %1.2f",a);
	printf("\nAfter swapping, value of b = %1.2f",b);
}
