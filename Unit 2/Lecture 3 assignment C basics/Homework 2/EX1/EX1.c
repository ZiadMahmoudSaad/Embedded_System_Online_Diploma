/*
 * EX1.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	int x;
	printf("Enter an integer you want to chack: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&x);
	if(x%2==0)
		printf("%d is even.",x);
	else
		printf("%d is odd.",x);
}
