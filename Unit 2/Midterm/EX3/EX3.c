/*
 * EX3.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
int isprime(int num);
int main(void){
	int num1,num2,i;
	again:
	printf("Enter two numbers : ");
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	if(num1>num2)
	{
		printf("Error!!!\n");
		goto again;
	}
	for(i=num1;i<=num2;i++)
	{
		if(isprime(i))
			printf("%d ",i);
	}
	return 0;
}

int isprime(int num){
	int i,j,arr[]={2,3,5,7};
	for(i=0;i<4;i++)
	{
		if(num%arr[i]||num==arr[i])
			j=1;
		else
		{
			j=0;
			break;
		}
	}
	return j;
}
