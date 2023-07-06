/*
 * EX2.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

int main()
{
	char str[100];
	int i;
	printf("Enter a string: ");
	fflush(stdin);	fflush(stdout);
	gets(str);

	for(i=0;str[i]!='\0';i++);
	printf("Length of string: %d",i);
}
