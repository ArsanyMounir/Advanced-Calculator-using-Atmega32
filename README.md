# Advanced Calculator with Atmega32 MCU

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Hardware Requirements](#hardware-requirements)
4. [Operating Instructions](#operating-instructions)
5. [Example Usage](#example-usage)


## Introduction

This project implements an advanced calculator using the ATMEGA32 microcontroller. It allows users to input mathematical expressions via a 4x4 keypad, displays the input on a 16x2 LCD, converts infix expressions to reverse polish notation (RPN), and evaluates them using a stack-based approach. The calculator supports chain equations and includes safety features such as division by zero protection. The project also includes custom-developed drivers for GPIO, LCD, and Keypad interfacing.

## Features

- **Mathematical Expression Evaluation:** Handles basic arithmetic operations (+, -, *, /) with correct operator precedence.
- **Chain Equations:** Continues calculations with the result of the previous expression using "ANS".
- **Division by Zero Protection:** Safeguards against invalid operations.
- **Clear Functionality:** Clears the LCD and resets internal data.
- **Infix to RPN Conversion:** Efficiently processes and evaluates expressions.
- **Custom Drivers:** Includes drivers for GPIO, LCD, and Keypad.

## Hardware Requirements

- ATMEGA32 Microcontroller
- 16x2 LCD Display
- 4x4 Keypad

## Operating Instructions

- **Input Expressions:** Use the keypad to input mathematical expressions. The input will be displayed on the LCD.
- **Evaluate:** After entering the expression, press the '=' key to evaluate.
- **Chain Calculations:** After evaluation, you can start a new operation using "+", "-", "*", or "/" which will use the previous result as "ANS".
- **Clear:** Press the 'C' button to clear the LCD and reset the calculator.

## Example Usage

1. **Basic Calculation:**
   - **Input:** `12+34`
   - **Output:** `46`
2. **Operator Precedence:**
   - **Input:** `1+8*4`
   - **Output:** `33` (evaluates as `1 + (8 * 4)`)
3. **Chain Calculation:**
   - After `33` is displayed, input: `*2`, which displays as `ANS*2`
   - **Output:** `66`
4. **Division by Zero Protection:**
   - **Input:** `12/0`
   - **Output:** `Error`
5. **Clear Screen:**
   - **Input:** `ON/C`
   - **Output:** Clears Screen and data

## Hardware Implementation 
<img src = "https://github.com/ArsanyMounir/Advanced-Calculator-using-Atmega32/blob/main/Hardware%20Implementation.gif" alt="Atmega32 Calculator" width="1080" height="500" >
