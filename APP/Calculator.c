/*
 * Calculator.c
 *
 *  Created on: May 14, 2024
 *      Author: Arsany
 */
#include "Calculator.h"




/**================================================================
 * @Fn			-intToASCII
 * @brief		-Converts input Integer to it's ASCII Representation
 * @param [in] 	-number : integer input to be changed to ASCII
 * @param [in]	-Arr : Pointer to array  to add the number after converting to ASCII to.
 * @retval 		-return integer value of how many places taken by the number ,
 * 				ex: if the number is 12 it took to places in array one for the "1" and another for the "2"
 * Note 		-None
 */
int intToASCII(int number, char* Arr)
{
	int i=0,j,x;
	char temp[10];
	while(number>0)
	{
		x = number%10;
		temp[i++] = x +'0';
		number /=10;
	}
	for (j=0;j<i;j++)
	{
		Arr[j] = temp[(i-1)-j];
	}
	return i ;
}


/**================================================================
 * @Fn			-clearArr
 * @brief		-Clears array's data
 * @param [in] 	-arr : Pointer to array  that need to be cleared.
 * @param [in] 	-length : length of the array.
 * @retval 		-None
 * Note 		-None
 */

void clearArr(char* arr,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		arr[i]='\0';
	}
}

/**================================================================
 * @Fn			-isspace
 * @brief		-Checks if the character is space or not
 * @param [in] 	-space : the character to be checked
 * @retval 		-returns 1 if the character is a space , 0 if the character is not
 * Note 		-None
 */

int isspace(char space)
{
	if(space == ' ' || space == '\t' || space == '\n' || space == '\r' || space == '\v' || space == '\f'  )
		return 1;
	else
		return 0;
}


/**================================================================
 * @Fn			-isdigit
 * @brief		-Checks if the character is a digit in ASCII Representation
 * @param [in] 	-symbol : the character to be checked
 * @retval 		-returns 1 if the character is a number , 0 if the character is not
 * Note 		-None
 */
int isdigit(char symbol)
{
	if((symbol >= '0') && (symbol <='9'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**================================================================
 * @Fn			-precedence
 * @brief		-Checks Precedence of operation
 * @param [in] 	-symbol : the operation to check it's precedence
 * @retval 		-returns 2 if the character is division or multiply ,
 * 				-returns 1 if the character is addition or subtraction,
 * 				-returns 0 if not either
 * Note 		-None
 */

int precedence(char symbol)
{
	switch (symbol)
	{
	case '/' :
	case '*' : return 2;
	case '+' :
	case '-' : return 1;
	default : return 0;
	}
}


/**================================================================
 * @Fn			-evalInfix
 * @brief		-Converts InFix notation to PostFix notation
 * @param [in] 	-expression : Pointer to array of inFix to be converted
 * @param [in] 	-postfix : Pointer to array of postFix to save the postfix notation
 * @retval 		-None
 * Note 		-None
 */

void evalInfix(char* expression,char* postfix)
{
	LIFO_Buf_t stack ;
	LIFO_init(&stack,buffer,width);
	int i ,j=0;

	for (i=0;expression[i]!='=';i++)
	{
		if(isdigit(expression[i]))
		{
			while(isdigit(expression[i]))
			{
				postfix[j++]=expression[i];
				i++;
			}
			i--;
			postfix[j++]=' ';
		}
		else
		{
			while (stack.count !=0 && precedence(LIFO_TOP(&stack)) >= precedence(expression[i]))
			{
				LIFO_pop(&stack,&postfix[j]);
				j++;
				postfix[j++]=' ';
			}
			LIFO_push(&stack,expression[i]);
		}
	}
	while(stack.count != 0)
	{
		LIFO_pop(&stack,&postfix[j]);
		j++;
		postfix[j++]=' ';
	}
	postfix[j]='\0';


}

/**================================================================
 * @Fn			-evalPostFix
 * @brief		-Evaluates the postFix and returns the result of mathematical expression using Shunting yard alg.
 * @param [in] 	-expression : Pointer to array of postFix to be evaluated.
 * @retval 		-Value of the expression evaluated.
 * Note 		-None
 */

int evalPostFix(char* expression )
{
	LIFO_Buf_t stack ;
	LIFO_init(&stack,buffer,width);
	int i =0;
	int num =0;
	char symbol;
	while(expression[i])
	{
		if(isspace(expression[i]))
		{
			i++;
			continue;
		}

		else if (isdigit(expression[i]))
		{
			num =0;

			while(isdigit(expression[i]))
			{
				num = num * 10 + (int)(expression[i]-'0');
				i++;
			}
			i--;
			LIFO_push(&stack ,num);
		}
		else
		{
			if (symbol == '\0')
			{
				i++;
				continue;
			}
			symbol = expression[i];
			int operand_1;
			int operand_2;
			LIFO_pop(&stack,&operand_1);
			LIFO_pop(&stack,&operand_2);
			if (symbol=='+')
			{
				LIFO_push(&stack,(operand_2 + operand_1));
			}
			else if (symbol=='-')
			{
				LIFO_push(&stack,(operand_2 - operand_1));
			}
			else if (symbol=='*')
			{
				LIFO_push(&stack,(operand_2 * operand_1));
			}
			else if (symbol=='/')
			{
				if(operand_1 == 0)
				{
					return 'X';
				}
				else
				{
					LIFO_push(&stack,operand_2 / operand_1);
				}

			}

		}
		i++;
	}



	int Result=0;
	LIFO_pop(&stack , &Result);
	return Result;


}
