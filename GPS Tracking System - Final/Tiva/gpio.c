#include "tm4c123gh6pm.h"

void RGBLED_Init(void) {

SYSCTL_RCGCGPIO_R |= 0x20; 
while((SYSCTL_PRGPIO_R&0x20) == 0){};
GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
GPIO_PORTF_CR_R |= 0x0E;
GPIO_PORTF_AMSEL_R &= ~0x0E;
GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
GPIO_PORTF_AFSEL_R &= ~0x0E;
GPIO_PORTF_DIR_R |= 0x0E;
GPIO_PORTF_DEN_R |= 0x0E;
GPIO_PORTF_DATA_R &= ~0X0E;
}


void RGB_Output (unsigned char data) {
GPIO_PORTF_DATA_R = data;
} 
