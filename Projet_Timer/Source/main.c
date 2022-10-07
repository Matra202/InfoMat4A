#include "stm32f10x.h"
#include "gpio.h"
#include "timers.h"

int main(void) {

	//TODO : TIM1 tous les modes de IRQN etc 
	//TODO : 5 et 6 du tuto timer 
	//premeir test avec tous les  irqn des TIM2-4 avec le timer.h qui semble bon
	extern int compteur;

	
	MyTimer_Struct_TypeDef MonTimer;
	MonTimer.Timer = TIM4;
	MonTimer.ARR = 10000-1;
	MonTimer.PSC = 3600-1;	
	
	MyTimer_Base_Init( &MonTimer);
	MyTimer_Active_IT( MonTimer.Timer, 10);
	MyTimer_Base_Start(MonTimer.Timer);
	//MyTimer_Base_Stop(MonTimer.Timer);
	
	
//500ms = 1/72MHZ * (PSC + 1) * (ARR +1);
	//36 000 000 = (PSC +1) * (ARR +1);
	// PSC = 9999;
	// ARR = 3599;
while(1){
}
}
