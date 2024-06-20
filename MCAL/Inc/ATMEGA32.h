/*
 * ATMEGA32.h
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_ATMEGA32_H_
#define MCAL_INC_ATMEGA32_H_


//========================================================
//						INCLUDES
//========================================================

#include "stdlib.h"
#include "stdint.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//			  Base Addresses for Peripherals
//========================================================
//GPIOs
#define PORTA_BASE  				(0x39)
#define PORTB_BASE		   			(0x36)
#define PORTC_BASE 					(0x33)
#define PORTD_BASE   				(0x30)

//EXTI
#define EXTI_BASE   				(0x54)



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//				    Peripheral Registers
//========================================================


//========================================================
//		    Peripheral Registers : GPIO
//========================================================


typedef struct
{
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;

}GPIO_TypeDef;



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//				    Peripheral Instants
//========================================================

//GPIOs
#define GPIOA					((GPIO_TypeDef*)PORTA_BASE)
#define GPIOB					((GPIO_TypeDef*)PORTB_BASE)
#define GPIOC					((GPIO_TypeDef*)PORTC_BASE)
#define GPIOD					((GPIO_TypeDef*)PORTD_BASE)


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------







#endif /* MCAL_INC_ATMEGA32_H_ */
