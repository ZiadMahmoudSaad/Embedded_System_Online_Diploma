/*
 * EX1.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Ziad Mahmoud Saad
 */

/* Write a Program to demonstrate how to
 * handle the pointers in the program
 */

#include <stdio.h>

int main()
{
	int m=29;
	int *ab;

	printf("Address of m : 0x%x\n",&m);
	printf("Value of m : %d\n",m);

	ab=&m;
	printf("\nNow ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%x\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	m=34;
	printf("\nThe value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%x\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	*ab=7;
	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of pointer m : 0x%x\n",&m);
	printf("Content of pointer m : %d\n",m);

	return 0;
}
