/*
 * EX3.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	float a,b,c;
	printf("Enter three numbers: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f %f %f",&a,&b,&c);
	if(a>b)
		if(a>c)
			printf("Largest number = %2.2f",a);
		else
			printf("Largest number = %2.2f",c);
	else
		if(b>c)
			printf("Largest number = %2.2f",b);
		else
			printf("Largest number = %2.2f",c);
}
