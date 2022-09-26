#include "stm32f10x.h"
#include "gpio.h"

int main(void) {
/*
	INIT
	
  RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	GPIOA->CRH |= 4 << (5*4);
	GPIOA->CRH &= ~(0xB << (5*4));
	
	
	
	GPIOA->CRL |= 3 << (5*4);
	GPIOA->CRL &= ~(0xC << (5*4));
	GPIOC->CRH |= 4 << (6*4);
	GPIOC->CRH &= ~(0xB << (6*4));
	GPIOC->CRL |= 3 << (6*4);
	GPIOC->CRL &= ~(0xC << (6*4));
	//GPIOA->ODR ^= 2 << 4;
	
	*/
	
MyGPIO_Struct_TypeDef  MyGPIOA;
MyGPIOA.GPIO = GPIOA;
MyGPIOA.GPIO_Pin= 5;
MyGPIOA.GPIO_Conf=Out_Ppull;
	
MyGPIO_Init (  &MyGPIOA ) ;

	
MyGPIO_Struct_TypeDef MyGPIOC;
MyGPIOC.GPIO = GPIOC;
MyGPIOC.GPIO_Pin= 13;
MyGPIOC.GPIO_Conf=In_Floating;

	
MyGPIO_Init ( &MyGPIOC ) ;

if (!(MyGPIO_Read (  GPIOC , 13 ))) {
	MyGPIO_Set ( GPIOA , '5' );
	}
while(1);
}


