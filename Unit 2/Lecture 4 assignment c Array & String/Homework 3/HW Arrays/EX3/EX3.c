/*
 * EX3.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include<stdio.h>

int main()
{
	int m[100][100],t[100][100],i,j,r,c;

	printf("Enter rows and column of matrix: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d",&r,&c);

	while(r>100||r<1||c>100||c<1)
	{
		printf("Again, Enter rows and column of matrix: ");
		fflush(stdin);	fflush(stdout);
		scanf("%d %d",&r,&c);
	}

	printf("\nEnter elements of matrix:\n");

	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("Enter elements a%d%d: ",i+1,j+1);
			fflush(stdin);	fflush(stdout);
			scanf("%d",&m[i][j]);
			t[j][i]=m[i][j];
		}

	printf("\nEntered Matrix:\n");

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d  ",m[i][j]);
		}
		printf("\n\n");
	}

	printf("\nTranspose of Matrix:\n");

	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d  ",t[i][j]);
		}
		printf("\n\n");
	}
}
