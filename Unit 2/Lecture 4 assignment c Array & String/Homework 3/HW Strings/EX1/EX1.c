/*
 * EX1.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
#include <string.h>
int main()
{
	char str[100],ch;
	int i,freq=0;

	printf("Enter a string: ");
	fflush(stdin);	fflush(stdout);
	gets(str);

	printf("Enter a character to find frequency: ");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&ch);

	for(i=0;i<strlen(str);i++)
		if(str[i]==ch)
			freq++;

	printf("Frequency of %c = %d", ch, freq);
}
