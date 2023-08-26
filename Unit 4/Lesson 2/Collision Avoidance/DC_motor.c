/*
 * DC_motor.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */


#include "DC_motor.h"

/* DC motor variables */
unsigned int speed =0;

/* init DC_motor */
void DC_init()
{
	printf("DC_init\n");
}

void Set_DC_motor(int s)
{
	speed = s;
	DC_state=STATE(DC_busy) ;
	printf("CA  -> -> -> DC  DC_motor(%d)\n",speed);
}

/* define states */
STATE_define(DC_idle)
{
	/* state name */
	DC_state_id = DC_idle ;
	/* state action */
	printf("DC_idle state : speed=%d\n\n",speed);
}

STATE_define(DC_busy)
{
	/* state name */
	DC_state_id = DC_busy;
	/* state action */
	printf("DC_busy state : speed=%d\n\n",speed);
	DC_state=STATE(DC_idle);
}




