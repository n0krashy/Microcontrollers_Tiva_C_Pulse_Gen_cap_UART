#include <stdint.h>
#include "tm4c123gh6pm.h"



void PortB_Init_Send(void){
		SYSCTL_RCGCTIMER_R |= 2;     /* enable clock to Timer Block 1 */
    SYSCTL_RCGCGPIO_R |= 2;      /* enable clock to PORTB */
    GPIO_PORTB_DIR_R |= 0x10;        /* make PB4 an output pin */
    GPIO_PORTB_DEN_R |= 0x10;         /* make PB4 as digital pin */
    GPIO_PORTB_AFSEL_R |= 0x10;       /* use PB4 alternate function */
    GPIO_PORTB_PCTL_R &= ~0x000F0000;  /* configure PB4 for T1CCP0 */
		GPIO_PORTB_PCTL_R |= 0x00070000;
}


void PWM_Init(int cycleTime){
	TIMER1_CTL_R &= ~1; // disable timer
	TIMER1_CFG_R = 0x00000004; // configuration
	TIMER1_TAMR_R |= 0x2; // set MR
	TIMER1_TAMR_R |= (1<<3); //set AMS
	TIMER1_TAMR_R &= ~(1<<2); // clear CMR
	TIMER1_TAILR_R = cycleTime; // set Timer start value to the passed cycleTime value
	TIMER1_TAMATCHR_R = cycleTime/2; // keep timer running until match half the cycleTime
	TIMER1_CTL_R |= 1; // enable timer
}
