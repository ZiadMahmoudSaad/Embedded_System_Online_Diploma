/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */


#include "CA.h"
#include "us_sensor.h"
#include "DC_motor.h"

void setup()
{
	/* init all drivers
	 * init UltraSonic driver
	 * init DC driver
	 */
	US_init();
	DC_init();
	/* setting state pointers for each state */
	CA_state = STATE(CA_waiting) ;
	US_state = STATE(US_reading) ;
	DC_state = STATE(DC_idle) ;
}

int main(void)
{
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
	}
}
