/*
 * CA.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

/* Define states */
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

/* global pointer to function */
void (* CA_state)();

/* prototypes */
STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
