/*
 * us_sensor.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "us_sensor.h"

/*UltraSonic variables */
unsigned int distance =0;

/* init ultrasonic sensor */
void US_init()
{
	printf("US_init\n");
}

/* define state */
STATE_define(US_reading)
{
	/* state name */
	US_state_id = US_reading ;
	/* read from the us */
	distance = US_Get_distance_random (45,55,1);

	printf("US_reading state : distance=%d\n",distance);
	US_Get_distance(distance);

	US_state = STATE(US_reading);
}

/* function to get random variables between l and r*/
int US_Get_distance_random (int l,int r, int count)
{
	int i ,rand_num;
	for (i=0;i<count;i++)
	{
		rand_num = (rand() % (r - l + 1)) + l ;
	}
	return rand_num ;
}
