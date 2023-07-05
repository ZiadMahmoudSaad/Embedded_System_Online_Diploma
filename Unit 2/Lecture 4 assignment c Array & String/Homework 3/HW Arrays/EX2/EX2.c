/*
 * EX2.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int main()
{
	float num[100],sum=0.0;
	int n, i;

	printf("Enter the numbers of data: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&n);

	while(n>100||n<1)
	{
		printf("Again, Enter the numbers of data:");
		fflush(stdin);	fflush(stdout);
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter number: ");
		fflush(stdin);	fflush(stdout);
		scanf("%f",&num[i]);
		sum+=num[i];
	}
	printf("Average = %.2f",sum/n);
}

