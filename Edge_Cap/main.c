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

// 3. Subroutines Section
void Delay_ms(long t){
	  long i , j;
	   i = 0;
	   j = 0;
	  while(i<t){
       while(j<3180){
				 j++;
			 //Do Nothing
			 }
			 i++;
	  }
}

// MAIN: Mandatory routine for a C program to be executable
int main(void) {
	int freq;
	SYSCTL_RCGCGPIO_R |= 0x20;  // activate port F
  GPIO_PORTF_DIR_R |= 0x0E;   // make PF1, 2 and 3 out
  GPIO_PORTF_AFSEL_R &= ~0x0E;// disable alt funct on PF1, 2 and 3
  GPIO_PORTF_DEN_R |= 0x0E;   // enable digital I/O on PF1,2 and 3
  GPIO_PORTF_AMSEL_R = 0;     // disable analog functionality on PF 
  UART_Init();
	Timer0Capture_init();
  while(1){
	if( (!(GPIO_PORTF_DATA_R&0x01)) || (!(GPIO_PORTF_DATA_R&0x10)) ){
		Delay_ms(30000);
		freq = Timer0A_periodCapture();
		UART_OutString("Recieved frequency: ");
		UART_OutUDec(freq);
		UART_OutString("\n\r");
	}
  }
}
