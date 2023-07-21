/*
 * EX7.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int n;
int sum(int num);
int main(void)
{
	printf("sum from 1 to 100 is %d",sum(100));
}
int sum(int num)
{
	if(num!=0)
	{
		n+=num;
		sum(num-1);
	}
	return n;
}
