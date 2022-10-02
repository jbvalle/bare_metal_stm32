#include "blink.h"

GPIOx_t * const GPIOA = (GPIOx_t *)0x40020000;
GPIOx_t * const GPIOB = (GPIOx_t *)0x40020400;
RCC_t   * const RCC   = (RCC_t   *)0x40023800;


void wait_ms(int time){
	for(volatile int i = 0; i < time; i++){
		for(volatile int j = 0; j < 1600; j++);
	}
}

void blink_init(){
	// Enable GPIOA
	RCC->RCC_AHB1ENR |= 1;

	// Set GPIOA as OUTPUT
	GPIOA->GPIOx_MODER &= ~(3 << (P5 * 2));
	GPIOA->GPIOx_MODER |=  (1 << (P5 * 2));
}

void blink(){
	GPIOA->GPIOx_ODR ^= (1 << P5);
	wait_ms(50);
}