/*
 * EX3.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
#include <string.h>

void rev(char str[],char rev[],int str_len);

int main(void)
{
	char str[100],reve[100];
	//ziad mahmoud saadEldeen
	printf("Enter a sentence: ");
	fflush(stdin);	fflush(stdout);
	gets(str);
	rev(str,reve,strlen(str)-1);

	printf("%s",reve);

}

void rev(char str[100],char reve[100],int str_len)
{
	reve[0]=str[str_len];
	if(str_len!=0)
		rev(str,reve+1,str_len-1);
}
