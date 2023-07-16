/*
 * EX2.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ziad Mahmoud Saad
 */
int factorial(int num);

#include <stdio.h>

int main(void)
{
	int num,f;

	printf("Enter an positive integer: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&num);
	f=factorial(num);

	if(f)
		printf("Factorial of %d = %d\n",num,f);
	else
		printf("Error!!! Factorial of negative number doesn't exist\n");
}

int factorial(int num)
{
	if(num>0)
		return num*factorial(num-1);
	else if(num==0)
		return 1;
	else
		return 0;
}

