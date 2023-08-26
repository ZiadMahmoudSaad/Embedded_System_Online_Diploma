/*
 * us_sensor.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"

/* Define states */
enum{
	US_reading
}US_state_id;

/* global pointer to function */
void(* US_state)();

/* prototypes */
void US_init();
STATE_define(US_reading);
int US_Get_distance_random (int l,int h, int count) ;


#endif /* US_SENSOR_H_ */
