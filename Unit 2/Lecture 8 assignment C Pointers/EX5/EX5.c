/*
 * EX5.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Ziad Mahmoud Saad
 */

/*
 * a program to show a pointer to an array
 * which contents are pointer to structure
 */

#include <stdio.h>

struct SEmployee{
	char name[10];
	int id;
};

int main()
{
	struct SEmployee emp1={"Alex",1002},emp2={"Ahmed",2202};
	struct SEmployee *arr[2]={&emp1,&emp2};
	struct SEmployee *(*pap)[2]=&arr;
	printf("Exmployee Name : %s\n",(*(*pap))->name);
	printf("Employee ID : %d",(*(*pap))->id);
	return 0;
}
