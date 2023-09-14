/*
 * platform_types.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*Unsigned Data Types*/
typedef unsigned char				boolean;
typedef unsigned char				uint8_t;
typedef unsigned long 				uint32_t;
typedef unsigned long long 			uint64_t;

/*Signed Data Types*/
typedef signed char					sint8_t;
typedef signed short 				sint16_t;
typedef signed long 				sint32_t;
typedef signed long long 			sint64_t;

/*Volatile Unsigned Data Types*/
typedef volatile unsigned char		vuint8_t;
typedef volatile unsigned short 	vuint16_t;
typedef volatile unsigned long 		vuint32_t;
typedef volatile unsigned long long vuint64_t;

/*Volatile Signed Data Types*/
typedef volatile signed char		vsint8_t;
typedef volatile signed short 		vsint16_t;
typedef volatile signed long 		vsint32_t;
typedef volatile signed long long 	vsint64_t;

#endif /* PLATFORM_TYPES_H_ */
