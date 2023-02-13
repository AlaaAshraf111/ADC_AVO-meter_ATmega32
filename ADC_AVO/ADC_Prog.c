/*
 * ADC_Prog.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Alaa Ashraf
 */

#include<stdio.h>
#include "types.h"
#include "BIT_MATH.h"
#include "avr/interrupt.h"

#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

#include "LCD_Interface.h"

static void (*ADC_ISR_PTR) (void);

void ADC_VidTnit()
{


	//Enable global interrupt
	SET_BIT(SREG,7);
	ADMUX_REG= ((ADC_VREF <<REFS_PIN ) | (REG_ADJ <<ADLAR_PIN ));
	 //0b11010111   with prescalar 128 = 111 and set ADC_Enable pin with 1 and set ADC_Interrupt pin with 0 and set ADC_StartConvrsion pin with 1
	ADCSRA_REG=(1<<ADC_EN_PIN)|(1<<2)|(1<<1)|(1<<0);


#if (ADC_MOD == ADC_INT)
	ADCSRA_REG |= (1<<3);
#endif
//SET_BIT(ADCSRA_REG_REG,0);
//SET_BIT(ADCSRA_REG,1);
//SET_BIT(ADCSRA_REG,2);
}


void ADC_EnableINT(void)
{
	ADCSRA_REG |= (1<<ADC_INT);
}

void ADC_DisableINT(void)
{
	ADCSRA_REG &=~(1<<ADC_INT);
}

u16 ADC_u16GetReading(u8 chId){

	chId = chId & 0b00000111;
	ADMUX_REG = (ADMUX_REG & 0xF8) | chId;

	ADCSRA_REG = (1<< ADC_SC_PIN)|(1<<ADC_EN_PIN ) | 0b00000111;

	//while(GET_BIT(ADCSRA_REG,4) == 0){
	while(! (ADCSRA_REG &(1<<4))){
	LCD_voidSendChar('d');
	}


	return ADC_REG;

}


#if (ADC_MOD == ADC_INT)
void ADC_StartConversion(u8 chId)
{
	chId = chId & 0b00000111;
	ADMUX_REG = (ADMUX_REG & 0xF8) | chId;

	ADCSRA_REG |= (1<< ADC_SC_PIN);
}

u16 ADC_GetConvertedDig(void){

	return ADC_REG;
}


void ADC_vidSetISR(void (*p)(void))
{
	ADC_ISR_PTR=p;
}

ISR(ADC_vect)
{
	ADC_ISR_PTR();
}
#endif

