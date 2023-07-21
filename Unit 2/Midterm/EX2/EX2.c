/*
 * EX2.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
#include <math.h>


int main(void)
{
	float num;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%f",&num);
	printf("Square root of %.3f is %.3f",num,sqrt(num));
}
