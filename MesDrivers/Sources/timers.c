#include "stm32f10x.h"
#include "timers.h"

int compteur = 0;
void (*ptr_fun)(void) ; 

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


void MyTimer_Active_IT ( TIM_TypeDef * Timer , char Prio,void (* IT_function ) ( void ) ) {
	ptr_fun= IT_function ;
	if (Timer == TIM1) {
		TIM1->DIER |= TIM_DIER_UIE;		
		NVIC_SetPriority(TIM1_UP_IRQn,Prio);
		NVIC_EnableIRQ(TIM1_UP_IRQn);
		
	}
	else if (Timer == TIM2) {
		TIM2->DIER |= TIM_DIER_UIE;		
		NVIC_SetPriority(TIM2_IRQn,Prio);
		NVIC_EnableIRQ(TIM2_IRQn);
		
	}
	else if (Timer == TIM3) {
		TIM3->DIER |= TIM_DIER_UIE;			
		NVIC_SetPriority(TIM3_IRQn,Prio);
		NVIC_EnableIRQ(TIM3_IRQn);
		
	}
	else if (Timer == TIM4) {
		TIM4->DIER |= TIM_DIER_UIE;	
		NVIC_SetPriority(TIM4_IRQn,Prio);		
		NVIC_EnableIRQ(TIM4_IRQn);
		
	}
}
void TIM1_UP_IRQHandler(void){
	TIM1->SR	&=  ~TIM_SR_UIF; 
	ptr_fun();
}

void TIM2_IRQHandler(void) {
	/*TIM2->DIER |= NVIC_ICPR_CLRPEND_8;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_9;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_10;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_11;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_12;
	TIM2->DIER |= NVIC_ICPR_CLRPEND_14;*/
	TIM2->SR &= ~TIM_SR_UIF;
	ptr_fun();
}
void TIM3_IRQHandler(void) {
	TIM3->SR &=  ~TIM_SR_UIF; 
	ptr_fun();
	//compteur++;
}
void TIM4_IRQHandler(void) {
	TIM4->SR &= ~TIM_SR_UIF; 
	ptr_fun();
	//compteur++;
}


void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ){

	if (Channel == 1) {
			Timer->CCER |= TIM_CCER_CC1E;
			Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
	}
	else if (Channel == 2) {
			Timer->CCER |= TIM_CCER_CC2E;
			Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
			Timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	}
	else if (Channel == 3) {
		Timer->CCER |= TIM_CCER_CC3E;
		Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
		Timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;
	
	}
	else if (Channel == 4) {
		Timer->CCER |= TIM_CCER_CC4E;
		Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
		Timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;
	}

}

void PWM_init( TIM_TypeDef * Timer ,int arr, int psc){
	Timer->ARR = arr;
	Timer->PSC = psc;

}
void PWM_rapport( TIM_TypeDef * Timer , char Channel, int rapport ){
		if (Channel == 1) {
		Timer->CCR1 = (int) (rapport * Timer->ARR) /100;
	}
	else if (Channel == 2) {
		Timer->CCR2 = (int) (rapport * Timer->ARR) /100;
	}
	else if (Channel == 3) {
		Timer->CCR3 = (int) (rapport * Timer->ARR) /100;
	}
	else if (Channel == 4) {
		Timer->CCR4 = (int) (rapport * Timer->ARR) /100;
	}
}
