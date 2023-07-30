/*
 * EX4.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Ziad Mahmoud Saad
 */

/*
 * Program to print the elements of an array in reverse order
 */

#include <stdio.h>

int main()
{
	int num[15],n,i;
	int *Pnum=0;

	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdout);
	scanf("%d",&n);

	Pnum=num;
	printf("Input %d number of elements in the array :\n",n);
	for(i=0;i<n;i++,Pnum++)
	{
		printf("element - %d :",i+1);
		fflush(stdout);
		scanf("%d",Pnum);
	}

	Pnum--;
	printf("The elements of array in reverse order are :\n");
	for(i=n;i>0;i--)
		printf("element - %d : %d\n",i,*Pnum--);

	return 0;
}
