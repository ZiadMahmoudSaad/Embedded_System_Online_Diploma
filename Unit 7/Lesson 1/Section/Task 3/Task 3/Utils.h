/*
 * Utils.h
 *
 * Created: 9/10/2023 6:33:07 PM
 *  Author: Ziad Mahmoud Saad
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define SETBIT(reg,bit) reg |= (1<<bit)
#define RESETBIT(reg,bit) reg &= ~(1<<bit)
#define TOGGLEBIT(reg,bit) reg ^= (1<<bit)
#define READBIT(reg,bit) ((reg>>bit)&1)

#endif /* UTILS_H_ */