/*
 * LCD.h
 *
 *  Created on: Apr 16, 2024
 *      Author: Arsany
 */

#ifndef HAL_INC_LCD_H_
#define HAL_INC_LCD_H_

//========================================================
//						INCLUDES
//========================================================

#include "ATMEGA32_GPIO_Driver.h"
#include "stdio.h"
//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			Ports Connections Configurations
//========================================================

#define LCD_CTRL						GPIOA


#define RS_SWITCH						GPIO_PIN_1
#define EN_SWITCH						GPIO_PIN_2


//========================================================
//			LCD Operation Mode Configurations
//========================================================

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define DATA_SHIFT 						3


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			Macros Configuration References
//========================================================

//@ref LCD Commands
#define LCD_FUNCTION_8BIT_2LINES   		(0x38)
#define LCD_FUNCTION_4BIT_2LINES   		(0x28)
#define LCD_MOVE_DISP_RIGHT       		(0x1C)
#define LCD_MOVE_DISP_LEFT   			(0x18)
#define LCD_MOVE_CURSOR_RIGHT   		(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  		(0x10)
#define LCD_DISP_OFF   					(0x08)
#define LCD_DISP_ON_CURSOR   			(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   		(0x0F)
#define LCD_DISP_ON_BLINK   			(0x0D)
#define LCD_DISP_ON   					(0x0C)
#define LCD_ENTRY_DEC   				(0x04)
#define LCD_ENTRY_DEC_SHIFT   			(0x05)
#define LCD_ENTRY_INC_   				(0x06)
#define LCD_ENTRY_INC_SHIFT   			(0x07)
#define LCD_BEGIN_AT_FIRST_ROW			(0x80)
#define LCD_BEGIN_AT_SECOND_ROW			(0xC0)
#define LCD_CLEAR_SCREEN				(0x01)
#define LCD_ENTRY_MODE					(0x06)


//------------------------------------------
//@ref LCD LINES
#define FIRST_LINE						1
#define SECOND_LINE						2


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "HAL LCD DRIVER"
//========================================================


void HAL_LCD_Init(void);
void HAL_LCD_WRITE_COMMAND(uint8_t command);
void HAL_LCD_WRITE_CHAR(int8_t data);
void HAL_LCD_WRITE_STR(int8_t* data);
void HAL_LCD_isbusy(void);
void HAL_LCD_CLEAR(void);
void HAL_LCD_GOTO_XY(uint8_t line , uint8_t position);
void HAL_LCD_WRITE_NUMBER(int Number);




#endif /* HAL_INC_LCD_H_ */
