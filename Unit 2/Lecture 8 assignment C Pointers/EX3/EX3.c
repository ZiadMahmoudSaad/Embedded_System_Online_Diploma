/*
 * EX3.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Ziad Mahmoud Saad
 */

/*
 * Write a program to print a string in reverse using a pointer
 */

#include <stdio.h>
#include<string.h>

int main()
{
	char str[50],temp;
	char *pstr=NULL,*prev=NULL;
	int i;
	printf("Pointer : Print a string in reverse order : \n");
	printf("------------------------\n");

	pstr=str;
	printf("Input a string : ");
	fflush(stdout);
	scanf("%s",pstr);

	prev=&str[strlen(str)];
	*prev='\0';
	prev--;

	for(i=0;i<(strlen(str)/2);i++)
	{
		temp=*pstr;
		*pstr=*prev;
		*prev=temp;
		pstr++;
		prev--;
	}

	pstr=str;
	printf("Reverse of the string is : %s",pstr);

	return 0;
}
