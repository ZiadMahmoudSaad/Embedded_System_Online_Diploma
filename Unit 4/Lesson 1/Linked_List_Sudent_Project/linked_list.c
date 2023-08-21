/*
 * linked_list.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "linked_list.h"

Sstudent* gpFirstStudent = NULL ;

/* Function to add student to the list */
void Add_Student()
{
	Sstudent* pLastStudent;
	Sstudent* pNewStudent ;

	/* initialization */
	/* if statemnt to check if its the firt time to add student */
	if(gpFirstStudent == NULL)
	{
		/* init first student in the list */
		pNewStudent =( Sstudent*)malloc( sizeof( Sstudent));
		gpFirstStudent = pNewStudent ;
	}
	else
	{
		/* init student in the list */
		pLastStudent = gpFirstStudent ;
		while(pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent ;

		pNewStudent =( Sstudent*)malloc( sizeof( Sstudent));
		pLastStudent->PNextStudent = pNewStudent ;
	}
	pNewStudent->PNextStudent = NULL ;

	/* Function to fill the data for the added student */
	fill_student_data(pNewStudent);
}

/* Function to delete student from the list */
int Delete_Student()
{
	int selected_id ;
	Dprintf("\nEnter Student ID to be deleted :");
	scanf("%d",&selected_id);

	/* check if the list is empty */
	if(gpFirstStudent)
	{
		Sstudent* pPrevStudent = NULL ;
		Sstudent* pSelectedStudent = gpFirstStudent ;

		/* while loop to find the Entered ID*/
		while(pSelectedStudent)
		{
			if(pSelectedStudent->student.ID == selected_id)
			{
				if(pPrevStudent)
					pPrevStudent->PNextStudent = pSelectedStudent->PNextStudent ;
				else
					gpFirstStudent = pSelectedStudent->PNextStudent ;

				/* free the allocated memory for that student*/
				free(pSelectedStudent) ;
				return 1 ;
			}
			pPrevStudent = pSelectedStudent ;
			pSelectedStudent = pSelectedStudent->PNextStudent ;
		}
	}else
		return 2 ;
	return 0 ;
}

/* Function to show all students in the list */
void view_students()
{
	Sstudent* pCurrenStudent = gpFirstStudent ;
	int count = 1 ;

	/* check if the list is empty */
	if(gpFirstStudent == NULL)
		Dprintf("\nEmpty list\n");

	while(pCurrenStudent)
		{
		Dprintf("\nRecord Numder %d",count);
		Dprintf("\nID: %d",pCurrenStudent->student.ID);
		Dprintf("\nName: %s",pCurrenStudent->student.name);
		Dprintf("\nHeight: %f\n",pCurrenStudent->student.height);

		pCurrenStudent = pCurrenStudent->PNextStudent ;
		count++;
		}
}

/*Function to delete all the list */
void DeleteAll()
{
	Sstudent* pCurrenStudent = gpFirstStudent ;

	/* check if the list is empty */
	if(pCurrenStudent == NULL)
	{
		Dprintf("\n Empty list");
	}
	else
	{
		while(pCurrenStudent)
		{
			Sstudent* pTemp = pCurrenStudent ;
			pCurrenStudent = pCurrenStudent->PNextStudent ;
			free(pTemp);
		}
		gpFirstStudent = NULL;
		Dprintf("\n<<<<<<<DELETE-LIST-DONE>>>>>>>>\n");
	}
}

/* Func to fill student's data */
void fill_student_data(Sstudent* pNewStudent)
{
	Dprintf("\nEnter the ID : ");
	scanf("%d",&(pNewStudent->student.ID));

	Dprintf("\nEnter Student Full Name : ");
	gets(pNewStudent->student.name);

	Dprintf("\nEnter height : ");
	scanf("%f",&(pNewStudent->student.height));
}

/* function to get a student at nth node */
void GET_NOde()
{
	Sstudent* pCurrenStudent = gpFirstStudent ;
	int count = 0,index = 0 ;

	/* check if the list is empty */
	if(gpFirstStudent == NULL)
	{
		Dprintf("\nEmpty list\n");
	}
	else
	{
		Dprintf("\nEnter node number: ");
		scanf("%d",&index);

		while(pCurrenStudent)
		{
			/* cheack if the current node is the entered node */
			if(count!= index)
			{
				pCurrenStudent = pCurrenStudent->PNextStudent ;
				count++ ;
			}
			else
			{
				Dprintf("\nstudent data at node %d",index);
				Dprintf("\nID: %d",pCurrenStudent->student.ID);
				Dprintf("\nName: %s",pCurrenStudent->student.name);
				Dprintf("\nHeight: %f",pCurrenStudent->student.height);
				break;
			}
		}
		/* check if the entered node is bigger than the list */
		if(!pCurrenStudent)
		{
			Dprintf("\nIndex bigger than the List");
		}
	}
}

/* Function to get the length of the list */
int linked_length(Sstudent* pCurrenStudent )
{
	/* check if the list is empty */
	if(pCurrenStudent == NULL)
	{
		return 0 ;
	}
	else
	{
		/* calc the length of the list in A Recursive Way*/
		return 1+ linked_length(pCurrenStudent->PNextStudent) ;
	}
}

/* Function to reverse list members */
void reverse_list()
{
	Sstudent* pPrevStudent = NULL ;
	Sstudent* pCurrenStudent = gpFirstStudent ;
	Sstudent* pTemp = NULL ;

	/* check if the list is empty */
	if(gpFirstStudent == NULL)
	{
		Dprintf("\nEmpty list\n");
	}
	else
	{
		pPrevStudent = pCurrenStudent ;
		pCurrenStudent = pCurrenStudent->PNextStudent ;
		/* while loop to let next student pointer in every element
		 * point to the previous student */
		while(pCurrenStudent)
		{
			pTemp = pCurrenStudent->PNextStudent ;
			pCurrenStudent->PNextStudent = pPrevStudent ;
			pPrevStudent = pCurrenStudent ;
			pCurrenStudent = pTemp ;
		}
		gpFirstStudent->PNextStudent = NULL ;
		gpFirstStudent = pPrevStudent ;

		Dprintf("\n<<<<<<<REVERSE-DONE>>>>>>>>\n");
	}
}

/* function to get a student at nth node from the END*/
void GET_END_node()
{
	Sstudent* pRefStudent = gpFirstStudent ;
	Sstudent* pMainStudent = gpFirstStudent ;
	int count = 0,index = 0 ;

	/* check if the list is empty */
	if(gpFirstStudent == NULL)
	{
		Dprintf("\nEmpty list\n");
	}
	else
	{
		Dprintf("\nEnter node number: ");
		scanf("%d",&index);

		/* check if the node is not less than 1 */
		if(index<1)
		{
			Dprintf("\nWrong node number\ncan't be less than 1");
		}else
		{
			while(pRefStudent)
			{
				if(count!=index)
				{
					pRefStudent = pRefStudent->PNextStudent ;
					count++;
				}
				else
				{
					pRefStudent = pRefStudent->PNextStudent ;
					pMainStudent = pMainStudent->PNextStudent;
				}
			}
			/* check if the entered node is not bigger than the list */
			if(count!=index)
			{
				Dprintf("\nIndex bigger than the List");
			}
			else
			{
				Dprintf("\nstudent data at node %d",index);
				Dprintf("\nID: %d",pMainStudent->student.ID);
				Dprintf("\nName: %s",pMainStudent->student.name);
				Dprintf("\nHeight: %f",pMainStudent->student.height);
			}
		}
	}
}
