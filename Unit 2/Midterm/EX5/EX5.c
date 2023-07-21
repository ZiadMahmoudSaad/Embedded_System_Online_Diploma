/*
 * EX5.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int ones(int num);
int main(void)
{
	int num;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%d",&num);
	printf("number of ones : %d",ones(num));
}
int ones(int num){
	int i,sum=0;
	for(i=0;i<32;i++)
	{
		if(num&(1<<i))
		{
			sum++;
		}
	}
	return sum;
}
