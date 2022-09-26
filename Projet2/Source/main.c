#include "stm32f10x.h"
#include "gpio.h"

int main(void) {

	
MyGPIO_Struct_TypeDef  MyGPIOA;
MyGPIOA.GPIO = GPIOA;
MyGPIOA.GPIO_Pin= 5;
MyGPIOA.GPIO_Conf=Out_Ppull;
	
MyGPIO_Init ( &MyGPIOA ) ;

	
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


