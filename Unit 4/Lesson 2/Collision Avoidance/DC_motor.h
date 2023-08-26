/*
 * DC_motor.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

/* Define states */
enum{
	DC_idle,
	DC_busy
}DC_state_id;

/* global pointer to function */
void (* DC_state)();

/* prototypes */
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

void (* DC_state)();

#endif /* DC_MOTOR_H_ */
