/*
 * EX1.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

struct SStudent{
	char name[50];
	int roll;
	float marks;
};

int main(void)
{
	struct SStudent student;
	printf("Enter information of students:\n\nEnter name: ");
	fflush(stdout);
	scanf("%s",student.name);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&student.roll);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&student.marks);
	printf("\nDisplaying Information\nname: %s\nRoll: %d\nMarks: %.2f",
			student.name,
			student.roll,
			student.marks);
}
