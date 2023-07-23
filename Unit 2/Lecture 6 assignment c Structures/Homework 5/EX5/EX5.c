/*
 * EX5.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>
#define pi 3.14159
#define area(r) r*r*pi
int main(){
	float radius;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&radius);

	printf("Area=%.2f",area(radius));

	return 0;
}
