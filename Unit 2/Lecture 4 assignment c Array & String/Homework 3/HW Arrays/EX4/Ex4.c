/*
 * Ex4.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int main()
{
	int n,num[100],i,ele,l;

	printf("Enter no of elements : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&n);

	while(n>100||n<1)
	{
		printf("Again, Enter no of elements : ");
		fflush(stdin);	fflush(stdout);
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	printf("Enter the element to be inserted : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&ele);

	printf("Enter the location : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&l);
	--l;

	for(i=n;i>l;i--)
	{
		num[i]=num[i-1];
	}

	num[l]=ele;

	for(i=0;i<n+1;i++)
	{
		printf("%d ",num[i]);
	}

}
