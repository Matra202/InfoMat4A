#include "stm32f10x.h"
#include "gpio.h"

int main(void) {

	
MyGPIO_Struct_TypeDef  MyGPIOA;
MyGPIO_Struct_TypeDef MyGPIOC;
MyGPIOA.GPIO = GPIOA;
MyGPIOA.GPIO_Pin= 5;
MyGPIOA.GPIO_Conf=Out_Ppull;

MyGPIOC.GPIO = GPIOC;
MyGPIOC.GPIO_Pin= 13;
MyGPIOC.GPIO_Conf=In_PullDown;
	
	
MyGPIO_Init ( &MyGPIOA ) ;
MyGPIO_Init ( &MyGPIOC ) ;
MyGPIO_Set ( GPIOA , 5 );
MyGPIO_Set ( GPIOA , 6 );
MyGPIO_Reset ( GPIOA , 5 );
MyGPIO_Toggle (GPIOA ,5);
MyGPIO_Toggle (GPIOA ,5);
MyGPIO_Toggle (GPIOC ,13);
	
	
	
//if (!(MyGPIO_Read (  GPIOC , 13 ))) {
//MyGPIO_Set ( GPIOA , 5 );
//	}
while(1);
}


