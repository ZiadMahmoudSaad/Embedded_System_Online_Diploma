/*
 * EX9.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
#include <string.h>
void rev_str(char str[],int len);
int main(void)
{
	char str[50];
	printf("Enter string :");
	fflush(stdout);
	gets(str);
	rev_str(str,strlen(str));
	printf("%s",str);
}
void rev_str(char str[],int len)
{
	char str2[50];
	int i,j,y,x=0;
	for(i=len-1;i>=0;i--)
	{
		if(str[i]==' ')
		{
			for(j=i+1;j<len;j++)
			{
				str2[x]=str[j];
				x++;
			}
			str2[x]=' ';
			x++;
		}else if(i==0)
		{
			for(y=0;str[y]!=' ';y++)
			{
				str2[x]=str[y];
				x++;
			}
		}
	}
	for(i=0;i<len;i++)
	{
		str[i]=str2[i];
	}
}
