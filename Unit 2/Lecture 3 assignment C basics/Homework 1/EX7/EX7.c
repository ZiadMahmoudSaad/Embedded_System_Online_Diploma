/*
 * EX7.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	int a,b;
	printf("Enter value of a: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&a);

	printf("Enter value of b: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&b);

	a=a*b;
	b=a/b;
	a=a/b;

	printf("\nAfter swapping, value of a = %d",a);
	printf("\nAfter swapping, value of b = %d",b);

}
