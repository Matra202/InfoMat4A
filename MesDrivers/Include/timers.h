#ifndef TIMERS_H
#define TIMERS_H
#include "stm32f10x.h"

typedef struct
{
	TIM_TypeDef * Timer; // TIMI à TIM4
	unsigned short ARR;
	unsigned short PSC; 
} MyTimer_Struct_TypeDef;
/*
@brief
@param -> Paramètre sous forme d'une structure (son adresse) contenant les informations de base
@Note > Fonction à lancer systématiquement avant d'aller plus en détail dans les conf plus fines (PWM, codeur inc...) */

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Tim);
#define MyTimer_Base_Start(Timr)(Timr ->CR1|=TIM_CR1_CEN) 
#define MyTimer_Base_Stop(Timr)(Timr ->CR1 &= ~TIM_CR1_CEN)
#endif
