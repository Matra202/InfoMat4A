#include "stm32f10x.h"
#include "timers.h"


void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Tim){
	
	if (Tim -> Timer == TIM1) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;
	}
	else if (Tim -> Timer == TIM2) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
	}
	else if (Tim -> Timer == TIM3) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN ;
	}
	else if (Tim -> Timer == TIM4) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN ;
	}
	Tim->Timer->ARR = Tim->ARR; //auto reload register
	Tim->Timer->PSC = Tim->PSC; //prescaler register
}
