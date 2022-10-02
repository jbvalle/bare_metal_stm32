//#include <stdint.h>

#define	  P5 	5
#define	__IO 	volatile
#define uint32_t int


typedef struct RCC_t{
	__IO uint32_t RCC_CR;
	__IO uint32_t RCC_PLLCFGT;
	__IO uint32_t RCC_CFGR;
	__IO uint32_t RCC_CIR;
	__IO uint32_t RCC_AHB1RSTR;
	__IO uint32_t RCC_AHB2RSTR;
	__IO uint32_t res1[2];
	__IO uint32_t RCC_APB1RSTR;
	__IO uint32_t RCC_APB2RSTR;
	__IO uint32_t res2[2];
	__IO uint32_t RCC_AHB1ENR;
	__IO uint32_t RCC_AHB2ENR;
	__IO uint32_t res3[2];
	__IO uint32_t RCC_APB1ENR;
	__IO uint32_t RCC_APB2ENR;
	__IO uint32_t res4[2];
	__IO uint32_t RCC_AHB1LPENR;
	__IO uint32_t RCC_AHB2LPENR;
	__IO uint32_t res5[2];
	__IO uint32_t RCC_APB1LPENR;
	__IO uint32_t RCC_APB2LPENR;
	__IO uint32_t res6[2];
	__IO uint32_t RCC_BDCR;
	__IO uint32_t RCC_CSR;
	__IO uint32_t res7[2];
	__IO uint32_t RCC_SSCGR;
	__IO uint32_t RCC_PLLI2SCFGR;
	__IO uint32_t res8;
	__IO uint32_t RCC_DCKCFGR;
}RCC_t;

typedef struct GPIOx_t{
	__IO uint32_t GPIOx_MODER; 		//0x00
	__IO uint32_t GPIOx_OTYPER;		//0x04
	__IO uint32_t GPIOx_OSPEEDER;	//0x08
	__IO uint32_t GPIOx_PUPDR;		//0x0C
	__IO uint32_t GPIOx_IDR;			//0x10
	__IO uint32_t GPIOx_ODR;			//0x14
	__IO uint32_t GPIOx_BSRR;		//0x18
	__IO uint32_t GPIOx_LCKR;
	__IO uint32_t GPIOx_AFRL;
	__IO uint32_t GPIOx_AFRH;
}GPIOx_t;

void wait_ms(int time){
	for(volatile int i = 0; i < time; i++){
		for(volatile int j = 0; j < 1600; j++);
	}
}

GPIOx_t * const GPIOA = (GPIOx_t *)0x40020000;
GPIOx_t * const GPIOB = (GPIOx_t *)0x40020400;
RCC_t   * const RCC   = (RCC_t   *)0x40023800;

int main(void)
{
	// Enable GPIOA
	RCC->RCC_AHB1ENR |= 1;

	// Set GPIOA as OUTPUT
	GPIOA->GPIOx_MODER &= ~(3 << (P5 * 2));
	GPIOA->GPIOx_MODER |=  (1 << (P5 * 2));

	for(;;){
		GPIOA->GPIOx_ODR ^= (1 << P5);
		wait_ms(50);
	}
}
