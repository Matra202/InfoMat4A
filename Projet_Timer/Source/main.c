#include "stm32f10x.h"
#include "gpio.h"
#include "timers.h"

void compt(void);
extern int compteur;

int main(void) {

	//TODO : TIM1 tous les modes de IRQN etc 
	//TODO : 5 et 6 du tuto timer 
	//premeir test avec tous les  irqn des TIM2-4 avec le timer.h qui semble bon
	MyGPIO_Struct_TypeDef  MyGPIOA;
	MyGPIO_Struct_TypeDef  MyGPIOAPWM;
	MyTimer_Struct_TypeDef MonTimer;
	MyTimer_Struct_TypeDef MonTimerPWM;
	MonTimerPWM.Timer = TIM3;
	
	MyGPIOA.GPIO = GPIOA;
	MyGPIOA.GPIO_Pin= 5;
	MyGPIOA.GPIO_Conf=AltOut_Ppull;
	MyGPIOAPWM.GPIO = GPIOA;
	MyGPIOAPWM.GPIO_Pin= 7;
	MyGPIOAPWM.GPIO_Conf=AltOut_Ppull;

	
	MyGPIO_Init ( &MyGPIOAPWM ) ;
	MyGPIO_Init ( &MyGPIOA ) ;
	MonTimer.Timer = TIM4;
	MonTimer.ARR = 10000-1;
	MonTimer.PSC = 3600-1;	
	
	MyTimer_Base_Init( &MonTimer);
	MyTimer_Base_Init( &MonTimerPWM);

	//MyTimer_Active_IT( MonTimer.Timer, 10,compt);
	//MyTimer_Base_Start(MonTimer.Timer);
	MyTimer_Base_Start(MonTimerPWM.Timer);
	//MyTimer_Base_Stop(MonTimer.Timer);
	
	
	MyTimer_PWM( MonTimerPWM.Timer , 2 );
	PWM_init(MonTimerPWM.Timer ,9999, 3599);
	PWM_rapport( MonTimerPWM.Timer , 2,  10 ) ;
//500ms = 1/72MHZ * (PSC + 1) * (ARR +1);
	//36 000 000 = (PSC +1) * (ARR +1);
	// PSC = 9999;
	// ARR = 3599;
while(1){
}
}

void compt(void){

	compteur++;
	MyGPIO_Toggle (GPIOA ,5);
	
}
