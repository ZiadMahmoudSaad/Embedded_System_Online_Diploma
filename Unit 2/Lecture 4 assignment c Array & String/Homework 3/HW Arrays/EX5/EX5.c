/*
 * EX5.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int main()
{
	int n,num[100],i,ele;

	printf("Enter no of elements : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	printf("Enter the elements to be searched : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&ele);

	for(i=0;i<n;i++)
		if(num[i]==ele)
			break;

	if(i<n)
		printf("Number found at the location = %d",i+1);
	else
		printf("Number not found");
}
