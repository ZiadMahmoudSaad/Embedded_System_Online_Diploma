/*
 * state.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

/* macro to generate state function */
#define STATE_define(StateFun) void st_##StateFun()
/* macro to call state function */
#define STATE(StateFun) st_##StateFun


/* Connections */
/* Carrying the interfaces between states */
void US_Get_distance(int distance);
void Set_DC_motor(int speed);

#endif /* STATE_H_ */
