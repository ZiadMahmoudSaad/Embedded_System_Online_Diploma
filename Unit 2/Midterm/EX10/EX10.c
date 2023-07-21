/*
 * EX10.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
int max_ones(int num);
int main(void)
{
	int num;
	printf("Enter num: ");
	fflush(stdout);
	scanf("%d,",&num);
	printf("max ones : %d",max_ones(num));
	return 0;
}
int max_ones(int num)
{
	int count=0,max_count=0,i;
	for(i=0;i<32;i++)
	{
		if(num&(1<<i))
			count++;
		else
			count=0;
		if(count>max_count)
			max_count=count;
	}
	return max_count;
}
