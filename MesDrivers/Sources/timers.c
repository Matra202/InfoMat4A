#include "stm32f10x.h"
#include "timers.h"

int compteur = 0;

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


void MyTimer_Active_IT ( TIM_TypeDef * Timer , char Prio ) {
	if (Timer == TIM1) {
		TIM1->DIER |= NVIC_ISER_SETENA_0 | NVIC_ISER_SETENA_1 | NVIC_ISER_SETENA_2 |
NVIC_ISER_SETENA_3 | NVIC_ISER_SETENA_4 | NVIC_ISER_SETENA_6;		
		NVIC_SetPriority(TIM1_CC_IRQn,Prio);
		NVIC_EnableIRQ(TIM1_CC_IRQn);
		
	}
	else if (Timer == TIM2) {
		TIM2->DIER |= NVIC_ISER_SETENA_0 | NVIC_ISER_SETENA_1 | NVIC_ISER_SETENA_2 |
NVIC_ISER_SETENA_3 | NVIC_ISER_SETENA_4 | NVIC_ISER_SETENA_6;		
		NVIC_SetPriority(TIM2_IRQn,Prio);
		NVIC_EnableIRQ(TIM2_IRQn);
		
	}
	else if (Timer == TIM3) {
		TIM3->DIER |= NVIC_ISER_SETENA_0 | NVIC_ISER_SETENA_1 | NVIC_ISER_SETENA_2 |
NVIC_ISER_SETENA_3 | NVIC_ISER_SETENA_4 | NVIC_ISER_SETENA_6;		
		NVIC_SetPriority(TIM3_IRQn,Prio);
		NVIC_EnableIRQ(TIM3_IRQn);
		
	}
	else if (Timer == TIM4) {
		TIM4->DIER |= NVIC_ISER_SETENA_0 | NVIC_ISER_SETENA_1 | NVIC_ISER_SETENA_2 |
NVIC_ISER_SETENA_3 | NVIC_ISER_SETENA_4 | NVIC_ISER_SETENA_6;
		NVIC_SetPriority(TIM4_IRQn,Prio);		
		NVIC_EnableIRQ(TIM4_IRQn);
		
	}
}
void TIM2_IRQHandler(void) {
	/*TIM2->DIER |= NVIC_ICPR_CLRPEND_8;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_9;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_10;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_11;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_12;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_14;*/
	TIM2->SR &= 0x1110; 
	compteur++;
}
void TIM3_IRQHandler(void) {
	TIM3->SR &= 0x1110; 
	compteur++;
}
void TIM4_IRQHandler(void) {
	TIM4->SR &= 0x1110; 
	compteur++;
}
