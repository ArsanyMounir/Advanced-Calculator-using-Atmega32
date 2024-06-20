/*
 * main.c
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */
#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "Calculator.h"

extern void wait_ms(uint32_t time);


int main(void)
{
	HAL_LCD_Init();
	HAL_LCD_WRITE_STR("Calculator Init");
	wait_ms(300);
	HAL_LCD_CLEAR();
	HAL_KEYPAD_Init();
	HAL_LCD_WRITE_STR("Keypad Init");
	wait_ms(300);
	HAL_LCD_CLEAR();
	char input;
	char inFix[16];
	char postFix[50];
	int prevOperationFlag=0;
	int result;
	int i=0,j=0;
	while(1)
	{
		input = HAL_KEYPAD_GetChar();
		if (input == 'N');
		else if(input == '!')
		{
			HAL_LCD_CLEAR();
			clearArr(inFix,j);
			clearArr(postFix,j*2);
			j=0;
			i=0;
		}
		else if (input == '=')
		{
			if(!prevOperationFlag){
				HAL_LCD_WRITE_CHAR(input);
				i++;
				inFix[j]=input;
				evalInfix(inFix,postFix);
				HAL_LCD_GOTO_XY(2,0);
				result = evalPostFix(postFix);
				if (result == 'X')
				{
					HAL_LCD_CLEAR();
					HAL_LCD_WRITE_STR("MATH ERROR");
					HAL_LCD_GOTO_XY(2,0);
					HAL_LCD_WRITE_STR("Div By Zero");
					wait_ms(500);
					clearArr(inFix,j);
					clearArr(postFix,j*2);
					j=0;
					i=0;
					HAL_LCD_CLEAR();
				}
				else
				{
					HAL_LCD_WRITE_NUMBER(result);
					prevOperationFlag = 1;
				}
			}
			else
			{
				HAL_LCD_CLEAR();
				HAL_LCD_WRITE_STR("Error");
				wait_ms(500);
				clearArr(inFix,j);
				clearArr(postFix,j*2);
				j=0;
				i=0;
				HAL_LCD_CLEAR();
				prevOperationFlag = 0;
			}

		}
		else
		{
			if (!prevOperationFlag)
			{
				HAL_LCD_WRITE_CHAR(input);
				i++;
				inFix[j++]=input;
			}
			else
			{
				if(isdigit(input))
				{
					HAL_LCD_CLEAR();
					clearArr(inFix,j);
					clearArr(postFix,j*2);
					j=0;
					i=0;
					HAL_LCD_WRITE_CHAR(input);
					i++;
					inFix[j++]=input;
					prevOperationFlag = 0;
				}
				else
				{
					HAL_LCD_CLEAR();
					clearArr(inFix,j);
					clearArr(postFix,j*2);
					j=0;
					i=0;
					HAL_LCD_WRITE_STR("ANS");
					i=i+2;
					j = j + intToASCII(result,inFix);
					HAL_LCD_WRITE_CHAR(input);
					i++;
					inFix[j++]=input;
					prevOperationFlag = 0;
				}

			}
		}
		if(i==16)
		{
			HAL_LCD_GOTO_XY(2,0);
		}
		else if (i==32)
		{
			HAL_LCD_CLEAR();
			HAL_LCD_GOTO_XY(1,0);
			i=0;
		}


	}

	return 0;
}


