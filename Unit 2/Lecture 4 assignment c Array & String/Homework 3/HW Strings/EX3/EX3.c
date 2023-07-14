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
	char str[100];
	char temp;
	int i,j=0;

	printf("Enter the string  : ");
	fflush(stdin);	fflush(stdout);
	gets(str);

	for(i=strlen(str)-1;i>=strlen(str)/2;i--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		printf("%s\n",str);
		j++;
	}

	printf("Reverse string is : %s", str);
}
