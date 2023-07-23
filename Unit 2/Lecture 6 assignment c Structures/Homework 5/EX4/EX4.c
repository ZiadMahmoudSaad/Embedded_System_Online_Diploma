/*
 * EX4.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

struct SStudent{
	char name[20];
	int marks;
};

int main(){
	struct SStudent student[10];
	int i;
	printf("Enter information of students:\n");
	for(i=0;i<10;i++)
	{
		printf("\nFor roll number %d\n",i+1);
		printf("Enter name:");
		fflush(stdout);
		scanf("%s",student[i].name);
		printf("Enter marks:");
		fflush(stdout);
		scanf("%d",&student[i].marks);
	}
	printf("Displaying information of students:\n");
	for(i=0;i<10;i++)
		{
			printf("\nInformation for roll number %d:\n",i+1);
			printf("Name: %s\n",student[i].name);
			printf("Marks: %d\n",student[i].marks);
		}
	return 0;
}
