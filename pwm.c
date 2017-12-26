#include <stdint.h>
#include "tm4c123gh6pm.h"



void PortB_Init(void){
		SYSCTL_RCGCTIMER_R |= 1;     /* enable clock to Timer Block 0 */
    SYSCTL_RCGCGPIO_R |= 2;      /* enable clock to PORTB */
    GPIO_PORTB_DIR_R &= ~0x40;        /* make PB6 an input pin */
    GPIO_PORTB_DEN_R |= 0x40;         /* make PB6 as digital pin */
    GPIO_PORTB_AFSEL_R |= 0x40;       /* use PB6 alternate function */
    GPIO_PORTB_PCTL_R &= ~0x0F000000;  /* configure PB6 for T0CCP0 */
		GPIO_PORTB_PCTL_R |= 0x07000000;
}


void PWM_Init(int cycleTime){
	TIMER0_CTL_R &= ~1; // disable timer
	TIMER0_CFG_R = 0x00000004; // configuration
	TIMER0_TAMR_R |= 0x2; // set MR
	TIMER0_TAMR_R |= (1<<3); //set AMS
	TIMER0_TAMR_R &= ~(1<<2); // clear CMR
	TIMER0_TAILR_R = cycleTime; // set Timer start value to the passed cycleTime value
	TIMER0_TAMATCHR_R = cycleTime/2; // keep timer running until match half the cycleTime
	TIMER0_CTL_R |= 1; // enable timer
}

int main(void){
		PortB_Init();
}