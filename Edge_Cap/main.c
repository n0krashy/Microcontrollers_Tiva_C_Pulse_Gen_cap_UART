//**** 0. Documentation Section
//  This program calculates the area of square shaped rooms
//  Author: Ramesh Yerraballi & Jon Valvano
//  Date: 5/24/2014
//
// 1. Pre-processor Directives Section
#include <stdio.h>  // Diamond braces for sys lib: Standard I/O
#include <stdint.h> // C99 variable types
#include "UART.h"
#include "timer_capture_init.h"

// 2. Global Declarations section
int32_t side; // room wall meters
int32_t area; // size squared meters
// Function Prototypes

// 3. Subroutines Section
// MAIN: Mandatory routine for a C program to be executable
int main(void) {
	int freq;
  UART_Init();
	Timer0Capture_init();
  while(1){
	freq = Timer0A_periodCapture();
	UART_OutString("Recieved frequency: ");
	UART_OutUDec(freq);
	UART_OutString("\n\r");
  }
}
