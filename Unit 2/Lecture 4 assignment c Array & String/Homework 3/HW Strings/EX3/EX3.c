/*
 * EX3.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
#include<string.h>

int main()
{
	char str[100],rev[100];
	int i,j=0;

	printf("Enter the string  : ");
	fflush(stdin);	fflush(stdout);
	gets(str);

	for(i=strlen(str);i>0;i--)
	{
		rev[j]=str[i-1];
		j++;
	}
	rev[j]='\0';
	printf("Reverse string is : %s", rev);
}
