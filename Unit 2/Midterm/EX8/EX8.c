/*
 * EX8.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
void rev(int arr[],int size);
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
	rev(num,size);
	printf("reverse array is\n");
	for(i=0;i<size;i++)
		printf("%d ",num[i]);
}
void rev(int arr[],int size)
{
	int temp,i,j;
	for(i=0,j=size-1;i<j;i++,j--)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}
