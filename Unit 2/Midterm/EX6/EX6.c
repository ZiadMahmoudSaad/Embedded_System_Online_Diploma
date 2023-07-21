/*
 * EX6.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int uniq(int num[],int size);
int main(void)
{
	int num[100],size,i;
	printf("Enter the size of array : ");
	fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++)
		{
			printf("Enter number: ");
			fflush(stdout);
			scanf("%d",&num[i]);
		}
	printf("The unique number : %d",uniq(num,size));
}
int uniq(int num[],int size)
{
	int i,unique;
	for(i=0;i<size;i++)
	{
		unique^=num[i];
	}
	return unique;
}
