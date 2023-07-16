/*
 * EX1.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int isprime(int num);

int main(void)
{
	int num1,num2,i;
	again:
	printf("Enter two numbers(intervals): ");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	if (num1>=num2)
	{
		printf("\nerror, try again\n");
		goto again;
	}
	else
	{
		printf("Prime numbers between 10 and 30 are:");
		for(i=num1+1;i<num2;i++)
		{
			if(isprime(i))
				printf(" %d",i);
		}
	}
	return 0;
}

int isprime(int num)
{
	int i,j,arr[]={2,3,5,7};

	for(i=0;i<4;i++)
	{
		if((num%arr[i]||num==arr[i])&&num!=1)
			j=1;
		else
		{
			j=0;
			break;
		}
	}
	return j;
}
