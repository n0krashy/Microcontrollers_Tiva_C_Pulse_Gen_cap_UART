#include "timer_capture_init.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "systick_init_header.h"

int main(void){ 
	int period_time;
	SYSCTL_RCGCGPIO_R |= 0x20;  // activate port F
  GPIO_PORTF_DIR_R |= 0x0E;   // make PF1, 2 and 3 out
  GPIO_PORTF_AFSEL_R &= ~0x0E;// disable alt funct on PF1, 2 and 3
  GPIO_PORTF_DEN_R |= 0x0E;   // enable digital I/O on PF1,2 and 3
  GPIO_PORTF_AMSEL_R = 0;     // disable analog functionality on PF  
	SysTick_Init();             // initialize SysTick timer
	Timer0Capture_init();
	while(1)
	{
		period_time = Timer0A_periodCapture();
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R^0x0E; // toggle PF
    SysTick_Wait(period_time/2);
		GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R^0x0E; // toggle PF
    SysTick_Wait(period_time/2);		
	}
}
