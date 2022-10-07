#include "stm32f10x.h"

int main( void )
{
  RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	GPIOA->CRH |= 4 << (5*4);
	GPIOA->CRH &= ~(0xB << (5*4));
	GPIOA->CRL |= 3 << (5*4);
	GPIOA->CRL &= ~(0xC << (5*4));
	GPIOC->CRH |= 4 << (6*4);
	GPIOC->CRH &= ~(0xB << (6*4));
	GPIOC->CRL |= 3 << (6*4);
	GPIOC->CRL &= ~(0xC << (6*4));
	GPIOA->ODR ^= 2 << 4;
	GPIOA->ODR ^= 2 << 4;
while (1) {
	if (!(GPIOC->IDR&(1<<13)))
		{
			GPIOA->ODR |= 1 << 5;
	}
	if (!(GPIOC->IDR&(1<<8)))
	{
		GPIOC->ODR |= 1 << 6;
	}

}
}
