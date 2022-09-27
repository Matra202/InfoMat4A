#include "stm32f10x.h"
#include "gpio.h"
#include "timers.h"

int main(void) {

//	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
//	TIM2->ARR = 10000-1; //auto reload register
//	TIM2->PSC = 3600-1; //prescaler register
//	TIM2-> CNT = 0; //counter register
//	TIM2 -> CR1 |= 1; // CEN = 1; counter enable
//	
	
	
	//TEST TIMERS.C
	
	MyTimer_Struct_TypeDef MonTimer;
	MonTimer.Timer = TIM2;
	MonTimer.ARR = 10000-1;
	MonTimer.PSC = 3600-1;	
	
	MyTimer_Base_Init( &MonTimer);
	MyTimer_Base_Start(MonTimer.Timer);
	MyTimer_Base_Stop(MonTimer.Timer);
	
	
//500ms = 1/72MHZ * (PSC + 1) * (ARR +1);
	//36 000 000 = (PSC +1) * (ARR +1);
	// PSC = 9999;
	// ARR = 3599;
while(1){
}
}
