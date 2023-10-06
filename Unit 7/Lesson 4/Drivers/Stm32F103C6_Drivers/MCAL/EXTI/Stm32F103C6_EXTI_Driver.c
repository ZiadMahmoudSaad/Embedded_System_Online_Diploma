/*
 * Stm32F103C6_GPIO_Driver.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

//-*-*-*-*-*
//	Includes
//-*-*-*-*-*

#include "Stm32F103C6_EXTI_Driver.h"
#include "Stm32F103C6_GPIO_Driver.h"

//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Generic Variables
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void (* GP_IRQ_CallBack[16])(void) ;

//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Generic Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define AFIO_EXTI_Mapping(x)		(	(x==GPIOA)?0:\
										(x==GPIOB)?1:\
										(x==GPIOC)?2:\
										(x==GPIOD)?3:\
										(x==GPIOE)?4:0	)




//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Generic Functions
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


void ENABLE_NVIC (uint16_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE ;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE ;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_ENABLE ;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE ;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE ;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_ENABLE ;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_ENABLE ;
		break;
	}

}

void DISABLE_NVIC (uint16_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE ;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE ;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE ;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE ;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE ;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_DISABLE ;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_DISABLE ;
		break;
	}
}


void UPDATE_EXTI(EXTI__PIN_Config_t* EXTI_Config)
{
	//	Configure GPIO to be floating input
	GPIO_PIN_Config PINcfg ;
	PINcfg.pin_number	= EXTI_Config->EXTI_PIN.GPIO_PIN ;
	PINcfg.pin_mode		= GPIO_MODE_Floating_Input ;

	GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PINcfg);

	//-----------------------------
	//	UPDATE AFIO to route between EXTI Line

	uint8_t AFIO_EXTICR_Index		=  EXTI_Config->EXTI_PIN.EXTI_InputLineNumber / 4 ;
	uint8_t AFIO_EXTICR_Postion		=  (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber % 4) * 4 ;

	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Postion) ;

	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_PORT) & 0xF) << AFIO_EXTICR_Postion );

	//-----------------------------
	//	UPDATE RISING and FALLING Reg

	EXTI->RTSR &= ~( EXTI_Config->EXTI_PIN.GPIO_PIN ) ;
	EXTI->FTSR &= ~( EXTI_Config->EXTI_PIN.GPIO_PIN ) ;

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN ;

	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN ;

	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->RTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN ;
		EXTI->FTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN ;

	}

	//-----------------------------
	//	UPDATE IRQ Handling CallBack

	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack ;

	//-----------------------------
	//ENABLE and DISABLE IRQ

	if(EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE )
	{
		EXTI->IMR |= EXTI_Config->EXTI_PIN.GPIO_PIN ;
		ENABLE_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber ) ;
	}
	else
	{
		EXTI->IMR &= ~( EXTI_Config->EXTI_PIN.GPIO_PIN ) ;
		DISABLE_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber ) ;
	}



}



//-------------------------
//	ISR Functions
//-------------------------

void EXTI0_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= 1<<0 ;
	//	CALL IRQ CallBack
	GP_IRQ_CallBack[0]();

}

void EXTI1_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= ( 1 << 0 ) ;
	//	CALL IRQ CallBack
	GP_IRQ_CallBack[0]() ;

}

void EXTI2_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= ( 1 << 1 ) ;
	//	CALL IRQ CallBack
	GP_IRQ_CallBack[1]() ;
}

void EXTI3_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= ( 1 << 2 ) ;
	//	CALL IRQ CallBack
	GP_IRQ_CallBack[2]() ;
}

void EXTI4_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= ( 1 << 3 ) ;
	//	CALL IRQ CallBack
	GP_IRQ_CallBack[3]() ;
}

void EXTI9_5_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	//	CALL IRQ CallBack
	if(EXTI->PR & 1<<5){	EXTI->PR |= ( 1 << 5 ) ;	GP_IRQ_CallBack[5]() ; }
	if(EXTI->PR & 1<<6){	EXTI->PR |= ( 1 << 6 ) ;	GP_IRQ_CallBack[6]() ; }
	if(EXTI->PR & 1<<7){	EXTI->PR |= ( 1 << 7 ) ;	GP_IRQ_CallBack[7]() ; }
	if(EXTI->PR & 1<<8){	EXTI->PR |= ( 1 << 8 ) ;	GP_IRQ_CallBack[8]() ; }
	if(EXTI->PR & 1<<9){	EXTI->PR |= ( 1 << 9 ) ;	GP_IRQ_CallBack[9]() ; }
}

void EXTI15_10_IRQHandler(void)
{
	//Pending register (EXTI_PR)
	//	This bit is cleared by writing a ‘1’ into the bit.
	//	CALL IRQ CallBack
	if(EXTI->PR & 1<<10){	EXTI->PR |= ( 1 << 10 ) ;	GP_IRQ_CallBack[10]() ; }
	if(EXTI->PR & 1<<11){	EXTI->PR |= ( 1 << 11 ) ;	GP_IRQ_CallBack[11]() ; }
	if(EXTI->PR & 1<<12){	EXTI->PR |= ( 1 << 12 ) ;	GP_IRQ_CallBack[12]() ; }
	if(EXTI->PR & 1<<13){	EXTI->PR |= ( 1 << 13 ) ;	GP_IRQ_CallBack[13]() ; }
	if(EXTI->PR & 1<<14){	EXTI->PR |= ( 1 << 14 ) ;	GP_IRQ_CallBack[14]() ; }
	if(EXTI->PR & 1<<15){	EXTI->PR |= ( 1 << 15 ) ;	GP_IRQ_CallBack[15]() ; }
}




//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	APIs Supported by "MCAL GPIO DRIVER"
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


/* @Fn			-EXTI_GPIO_DeInit
* @brief 		-Reset EXTI registers and NVIC Corresponding IRQ MASK
* @retval 		-none
* Note			-none
*/

void EXTI_GPIO_DeInit(void)
{
	EXTI->IMR		=	0x00000000 ;
	EXTI->EMR		=	0x00000000 ;
	EXTI->RTSR		=	0x00000000 ;
	EXTI->FTSR		=	0x00000000 ;
	EXTI->SWIER 	=	0x00000000 ;
	//	This bit  is cleared by writing a ‘1’ into the bit.
	EXTI->PR		=	0xFFFFFFFF ;

	//Disable EXTI ISQ from NVIC
	NVIC_IRQ6_EXTI0_DISABLE;
	NVIC_IRQ7_EXTI1_DISABLE;
	NVIC_IRQ8_EXTI2_DISABLE;
	NVIC_IRQ9_EXTI3_DISABLE;
	NVIC_IRQ10_EXTI4_DISABLE;
	NVIC_IRQ23_EXTI5_9_DISABLE;
	NVIC_IRQ40_EXTI10_15_DISABLE;
}

//***********************************

/* @Fn			-EXTI_GPIO_Init
* @brief 		-Used to initialize EXTI from specific GPIO PIN ,MASK Condition ,Trigger Condition ,and IRQ CallBack Function
* @param [in] 	-EXTI_Config: Set based on @red EXTI_Define ,  @ref EXTI_Trigger_Define ,and @red EXTI_IRQ_Define
* @retval 		-none
* Note			-none
*/


void EXTI_GPIO_Init(EXTI__PIN_Config_t* EXTI_Config)
{
	UPDATE_EXTI(EXTI_Config) ;
}


//***********************************

/* @Fn			-EXTI__GPIO_Update
* @brief 		-Used to UPDATE EXTI from specific GPIO PIN ,MASK Condition ,Trigger Condition ,and IRQ CallBack Function
* @param [in] 	-EXTI_Config: Set based on @red EXTI_Define ,  @ref EXTI_Trigger_Define ,and @red EXTI_IRQ_Define
* @retval 		-none
* Note			-none
*/


void EXTI__GPIO_Update(EXTI__PIN_Config_t* EXTI_Config)
{
	UPDATE_EXTI(EXTI_Config) ;
}
