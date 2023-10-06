/*
 * Stm32F103x6.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Ziad Mahmoud Saad
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-*-*-*-*-*
//	Includes
//-*-*-*-*-*

#include <stdlib.h>
#include <stdint.h>


//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Base addresses for Memories
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define FLASH_Mem_BASE							0x08000000UL
#define SYSTEM_Mem_BASE 						0x1FFFF800UL
#define SRAM_BASE								0x20000000UL
#define Peripherals_BASE						0x40000000UL
#define Cortex_M3_internal_Peripherals_BASE		0xE0000000UL
#define NVIC_BASE								(Cortex_M3_internal_Peripherals_BASE+0x0000E100UL)

#define NVIC_ISER0								*(volatile uint32_t *) (NVIC_BASE + 0x000)
#define NVIC_ISER1								*(volatile uint32_t *) (NVIC_BASE + 0x004)
#define NVIC_ISER2								*(volatile uint32_t *) (NVIC_BASE + 0x008)
#define NVIC_ICER0								*(volatile uint32_t *) (NVIC_BASE + 0x080)
#define NVIC_ICER1								*(volatile uint32_t *) (NVIC_BASE + 0x084)
#define NVIC_ICER2								*(volatile uint32_t *) (NVIC_BASE + 0x088)


//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Base addresses for BUS Peripherals
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-----------------------------
//	Base addresses for AHB Peripherals
//-----------------------------

// RCC
#define RCC_BASE 								( Peripherals_BASE + 0x00021000UL )


//-----------------------------
//	Base addresses for APB2 Peripherals
//-----------------------------

// GPIOs
// All Packages: 		A fully included
#define GPIOA_BASE								( Peripherals_BASE + 0x00010800UL )

// VFQFPN36 Package:		B partial included
// Other Packages: 		B fully included
#define GPIOB_BASE 								( Peripherals_BASE + 0x00010C00UL )

// LQFP48 Package: 		C partial included
// VFQFPN36 Package:		C not included
// Other Packages:		C fully included

#define GPIOC_BASE 								( Peripherals_BASE + 0x00011000UL )

// LQFP48 Package: 		D partial included
// LFBGA100 Package:		D fully included
// UFBG100 Package:		D fully included
// LQFP100 Package:		D fully included
// TFBGA64 Package: 		D partial included
// LQFP64 Package: 		D pin 2 only included
// VFQFPN36 Package: 	D pin 0,1 only included
#define GPIOD_BASE								( Peripherals_BASE + 0x00011400UL )

// LFBGA100 Package:		E fully included
// UFBG100 Package:		E fully included
// LQFP100 Package:		E fully included
// Other Packages:		E not included
#define GPIOE_BASE 								( Peripherals_BASE + 0x00011800UL )

// AFIO
#define AFIO_BASE								( Peripherals_BASE + 0x00010000UL )

// EXTI
#define EXTI_BASE								( Peripherals_BASE + 0x00010400UL )


//-----------------------------
//	Base addresses for APB1 Peripherals
//-----------------------------


//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//	Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*


//------------------
//	Peripheral register: RCC
//------------------

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;


//------------------
//	Peripheral register: GPIO
//------------------

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;


//------------------
//	Peripheral register: AFIO
//------------------

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;


//------------------
//Peripheral register: EXTI
//------------------

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;


//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

//------------------
//		GPIO
//------------------

#define GPIOA 		((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB 		((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD 		((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE 		((GPIO_TypeDef *) GPIOE_BASE)


//------------------
//		RCC
//------------------

#define RCC 		((RCC_TypeDef *) RCC_BASE)



//------------------
//		AFIO
//------------------

#define AFIO 		((AFIO_TypeDef *) AFIO_BASE)


//------------------
//		EXTI
//------------------

#define EXTI 		((EXTI_TypeDef *) EXTI_BASE)


//------------------
//		IVT
//------------------
//EXTI
#define EXTI0_IRQ				6
#define EXTI1_IRQ				7
#define EXTI2_IRQ				8
#define EXTI3_IRQ				9
#define EXTI4_IRQ				10
#define EXTI5_IRQ				23
#define EXTI6_IRQ				23
#define EXTI7_IRQ				23
#define EXTI8_IRQ				23
#define EXTI9_IRQ				23
#define EXTI10_IRQ				40
#define EXTI11_IRQ				40
#define EXTI12_IRQ				40
#define EXTI13_IRQ				40
#define EXTI14_IRQ				40
#define EXTI15_IRQ				40



//=========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//Enable AFIO clock
#define RCC_AFIO_CLK_EN()		( RCC->APB2ENR |= 1<<0 )

//Enable GPIOs clock
#define RCC_GPIOA_CLK_EN()		( RCC->APB2ENR |= 1<<2 )
#define RCC_GPIOB_CLK_EN()		( RCC->APB2ENR |= 1<<3 )
#define RCC_GPIOC_CLK_EN()		( RCC->APB2ENR |= 1<<4 )
#define RCC_GPIOD_CLK_EN()		( RCC->APB2ENR |= 1<<5 )
#define RCC_GPIOE_CLK_EN()		( RCC->APB2ENR |= 1<<6 )

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IQR enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_IRQ6_EXTI0_ENABLE			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_ENABLE			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_ENABLE			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_ENABLE			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_ENABLE			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_ENABLE		(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_ENABLE		(NVIC_ISER1 |= 1<<8)


#define NVIC_IRQ6_EXTI0_DISABLE			(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_DISABLE			(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_DISABLE			(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_DISABLE			(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_DISABLE		(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_DISABLE		(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_DISABLE	(NVIC_ICER1 |= 1<<8)

#endif /* INC_STM32F103X6_H_ */
