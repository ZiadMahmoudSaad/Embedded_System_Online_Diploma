/*
 * EX3.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ziad Mahmoud Saad
 */
#include <stdio.h>

struct SComplex{
	float real;
	float img;
};

struct SComplex add(struct SComplex c1,struct SComplex c2);
int main(void){
	struct SComplex c1,c2,sum;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&c1.real,&c1.img);

	printf("\nFor 2nd complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&c2.real,&c2.img);
	sum=add(c1,c2);
	printf("Sum=%.1f+%.1fi",sum.real,sum.img);

	return 0;
}

struct SComplex add(struct SComplex c1,struct SComplex c2)
{
	struct SComplex sum;
	sum.real=c1.real+c2.real;
	sum.img=c1.img+c2.img;
	return sum;
}
