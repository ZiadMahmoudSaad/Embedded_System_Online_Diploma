/*
 * EX1.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
int sum;
int sum_all(int num);
int main(void)
{
	int num,sum;
	printf("Enter number : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&num);
	sum=sum_all(num);
	printf("Sum of all digits is : %d",sum);

}
int sum_all(int num)
{

	if(num!=0)
	{
		sum+=num%10;
		sum_all(num/10);
	}else return 0;
	return sum;

}
