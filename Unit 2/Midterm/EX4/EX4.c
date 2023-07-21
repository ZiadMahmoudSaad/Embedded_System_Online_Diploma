/*
 * EX4.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
int result;
int rev(int num);
int main(void)
{
	int num;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%d",&num);
	printf("The reverse number is %d",rev(num));
}
int rev(int num)
{
	if(num!=0)
	{
		result*=10;
		result+=num%10;
		rev(num/10);
	}
	return result;
}
