/*
 * EX2.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include <stdio.h>

struct SDistance{
	int feet;
	float inch;
};
int main(void)
{
	struct SDistance d1,d2,sum;
	printf("Enter information for 1st distance\nEnter feet: ");
	fflush(stdout);
	scanf("%d",&d1.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d1.inch);

	printf("\nEnter information for 2nd distance\nEnter feet: ");
	fflush(stdout);
	scanf("%d",&d2.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d2.inch);

	sum.feet=d1.feet+d2.feet;
	sum.inch=d1.inch+d2.inch;
	for(;sum.inch>12;sum.inch-=12)
		sum.feet++;
	printf("\nSum of distances=%d\'-%.1f\"",sum.feet,sum.inch);
	return 0;
}
