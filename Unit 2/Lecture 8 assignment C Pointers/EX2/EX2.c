/*
 * EX2.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Ziad Mahmoud Saad
 */

/* Write program to print all the alphabets using a pointer.*/
#include <stdio.h>

int main()
{
	char a[26];
	char *Pchr;
	int i;
	Pchr=a;

	for(i=0;i<26;i++,Pchr++)
		*Pchr=i+'A';

	Pchr=a;
	printf("THe Alphabets are :\n");
	for(i=0;i<26;i++,Pchr++)
		printf(" %c ",*Pchr);
	return 0;
}
