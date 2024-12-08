#include "stm32f4xx.h"  // Include the STM32 HAL headers

void delay(volatile uint32_t delay_time);

void SystemInit(void){

}

int main(void) {
    // Enable the GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Set PA5 as output mode
    GPIOA->MODER &= ~(0x3 << (5 * 2));  // Clear mode bits for PA5
    GPIOA->MODER |= (0x1 << (5 * 2));   // Set mode to output

    // Set PA5 output type to push-pull
    GPIOA->OTYPER &= ~(1 << 5);

    // Set PA5 output speed to high
    GPIOA->OSPEEDR |= (0x3 << (5 * 2));

    // Disable pull-up/pull-down for PA5
    GPIOA->PUPDR &= ~(0x3 << (5 * 2));

    while (1) {
        // Toggle the LED
        GPIOA->ODR ^= (1 << 5);

        // Add a delay
        delay(5000000);
    }
}

// Simple delay function
void delay(volatile uint32_t delay_time) {
    while (delay_time--) {
        __asm("nop");
    }
}	


