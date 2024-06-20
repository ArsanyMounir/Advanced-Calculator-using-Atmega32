/*
 * Calculator.h
 *
 *  Created on: May 14, 2024
 *      Author: Arsany
 */

#ifndef APP_INC_CALCULATOR_H_
#define APP_INC_CALCULATOR_H_

#include"LIFO.h"

int precedence(char symbol);
void evalInfix(char* expression,char* postfix);
int evalPostFix(char* expression);
int isdigit(char symbol);
void clearArr(char* Arr,int length);
int intToASCII(int number, char* Arr);
#endif /* APP_INC_CALCULATOR_H_ */
