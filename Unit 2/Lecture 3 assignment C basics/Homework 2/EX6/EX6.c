/*
 * EX6.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "stdio.h"

void main()
{
	unsigned int n, sum=0;
	int i;

	printf("Enter a integer: ");
	fflush(stdin);	fflush(stdout);
	scanf("%u",&n);

	for(i=1;i<=n;i++)
		sum+=i;

	printf("sum = %u",sum);
}
