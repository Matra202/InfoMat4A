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
void MyTimer_Active_IT ( TIM_TypeDef * Timer , char Prio,void (* IT_function ) (void) ) ;
/**
* @bri f
* @param . . . .
* @Note Activele channel spécifié suTimerr le timer spécifié
* l a g e s ti o n de l a c o n fi g u r a ti o n I /O n ’ e s t pas f a i t e dans c e t t e f o n c ti o n
* ni l e r é gl a ge de l a pé ri o d e de l a PWM (ARR, PSC)
*/
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) ;
void PWM_init( TIM_TypeDef * Timer ,int arr, int psc);
void PWM_rapport( TIM_TypeDef * Timer , char Channel, int rapport ) ;

#define MyTimer_Base_Start(Timr)(Timr ->CR1|=TIM_CR1_CEN) 
#define MyTimer_Base_Stop(Timr)(Timr ->CR1 &= ~TIM_CR1_CEN)
#endif
