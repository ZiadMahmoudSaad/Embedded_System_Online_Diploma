/*
 * CA.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#include "CA.h"
#define CA_threshold 50

/* CA variables */
unsigned int CA_speed = 0 ;
unsigned int CA_distance = 0 ;


void US_Get_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state=STATE(CA_waiting)):(CA_state= STATE(CA_driving));
	printf("US-----distance = %d----->CA\n",CA_distance);
}

/* define states */
STATE_define(CA_waiting)
{
	/* state name */
	CA_state_id = CA_waiting;
	/* state action */
	CA_speed = 0;
	printf("CA_waiting state: distance=%d------speed = %d\n",CA_distance,CA_speed);
	Set_DC_motor(CA_speed);
}

STATE_define(CA_driving)
{
	/* state name */
	CA_state_id = CA_driving;
	/* state action */
	CA_speed = 30;
	printf("CA_driving state: distance=%d------speed = %d\n",CA_distance,CA_speed);
	Set_DC_motor(CA_speed);
}




