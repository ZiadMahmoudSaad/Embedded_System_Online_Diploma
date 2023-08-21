/*
 * linked_list.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define Dprintf(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

#define Sstudent struct sstudent_t

/* Person_Information dData Type */
struct SDATA
{
	int ID ;
	char name[40] ;
	float height ;
};

/* Student Data Type */
struct sstudent_t
{
	struct SDATA student;
	struct sstudent_t* PNextStudent ;
};

/* APIs */
void Add_Student();
int Delete_Student();
void view_students();
void DeleteAll();
void fill_student_data(Sstudent* pNewStudent);
void GET_NOde();
int linked_length(Sstudent* pCurrenStudent);
void reverse_list();
void GET_END_node();

#endif /* LINKED_LIST_H_ */
