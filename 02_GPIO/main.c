#include "stm32f4xx.h"  // Include the STM32 HAL headers
#include "stdint.h"


#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)

#define PIN5		(1U<<5)
#define PIN13		(1U<<13)

#define LED_PIN		PIN5
#define BTN_PIN		PIN13


void SystemInit(void){}

int main(void) {
	// Enable port C for push button
	RCC->AHB1ENR |= GPIOCEN;
	// Enable port A for led
	RCC->AHB1ENR |= GPIOAEN;

	// Set PA5 as output pin
	GPIOA->MODER |=(1U<<10);
	GPIOA->MODER &=~(1U<<11);

	// Set PC15 as input pin
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);

	while(1)
	{
		// If button is pressed - active low
		if(GPIOC->IDR & BTN_PIN)
		{
			//turn on led
			GPIOA->BSRR = LED_PIN;
		}
		else{
			//turn off led
			GPIOA->BSRR = (1U<<21);
		}

		
	}
}
