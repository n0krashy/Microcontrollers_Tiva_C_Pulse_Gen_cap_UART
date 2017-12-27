//**** 0. Documentation Section
//  This program calculates the area of square shaped rooms
//  Author: Ramesh Yerraballi & Jon Valvano
//  Date: 5/24/2014
//
// 1. Pre-processor Directives Section
#include <stdio.h>  // Diamond braces for sys lib: Standard I/O
#include <stdint.h> // C99 variable types
#include "UART.h"
#include "pwm.h"


// 3. Subroutines Section
// MAIN: Mandatory routine for a C program to be executable
int main(void) {
	int cycles;
  UART_Init();
	PortB_Init_Send();
  while(1){
		UART_OutString("Enter frequency in Hz: ");
	cycles = UART_InUDec();
				UART_OutString("\n\r");
	PWM_Init(cycles-1);
  }
}
