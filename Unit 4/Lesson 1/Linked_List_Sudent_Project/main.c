/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "linked_list.h"

extern Sstudent* gpFirstStudent ;
int main(void)
{
	int num,delete;
	while(1)
	{
		Dprintf("\n=======================");
		Dprintf("\n\t\t Choose on of the following options\n");
		Dprintf("\n1: AddStudent");
		Dprintf("\n2: Delete Student");
		Dprintf("\n3: view students");
		Dprintf("\n4: Delete all students");
		Dprintf("\n5: Get student at node");
		Dprintf("\n6: Get student at node from the end");
		Dprintf("\n7: number of students");
		Dprintf("\n8: reverse student list");
		Dprintf("\nEnter option Number: ");
		scanf("%d",&num);
		Dprintf("\n=======================");

		switch(num)
		{
		case 1:
			Add_Student();
			break;
		case 2:
			delete =Delete_Student();
			if(delete==1)
			{
				Dprintf("\n<<<<<<<DELETE-STUDENT-DONE>>>>>>>>\n");
			}else if(delete ==2)
			{
				Dprintf("\nEmpty list\n");
			}else
			{
				Dprintf("cannot find student ID.");
			}
			break;
		case 3:
			view_students();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			GET_NOde();
			break;
		case 6:
			GET_END_node();
			break;
		case 7:
			printf("\nStudents number : %d",linked_length(gpFirstStudent));
			break;
		case 8:
			reverse_list();
			break;
		default:
			Dprintf("\n wrong option");
		}

	}
}

