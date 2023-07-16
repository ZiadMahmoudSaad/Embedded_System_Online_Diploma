/*
 * EX4.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int power(int a,int b);
int main(void)
{
	int num;
	int exp;
	printf("Enter base number: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&num);

	printf("Enter power number(positive integer): ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&exp);

	printf("%d^%u = %d",num,exp,power(num,exp));
}

int power(int a,int b)
{
	if(b!=0)
		return a*power(a,b-1);
	else
		return 1;
}
