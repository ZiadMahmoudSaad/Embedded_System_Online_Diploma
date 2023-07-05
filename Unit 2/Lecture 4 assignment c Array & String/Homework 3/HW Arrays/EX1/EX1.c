/*
 * EX1.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int main()
{
	float ab[2][2][2], sum[2][2];
	char mat_name[]={'a','b'};
	int x, i, j;

	for(x=0;x<2;x++)
	{
		printf("Enter the elements of %dst matrix\n",x+1);

		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("Enter %c%d%d: ",mat_name[x],i+1,j+1);
				fflush(stdin);fflush(stdout);
				scanf("%f",&ab[x][i][j]);
			}

		}
	}
	printf("\nSum of Matrix:\n");

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum[i][j]=ab[0][i][j]+ab[1][i][j];
			printf("%.1f\t",sum[i][j]);
			if(j==1)
				printf("\n");
		}
	}
}
