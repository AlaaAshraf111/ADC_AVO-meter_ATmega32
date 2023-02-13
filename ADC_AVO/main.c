/*
 * main.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Alaa Ashraf
 */


#include <stdio.h>
#include<util/delay.h>
#include "types.h"
#include "BIT_MATH.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "DIO1_Interface.h"
#include "LCD_Interface.h"

#include "ADC_Interface.h"

void ADC_ISRFunc(void);

u16 Digital=0;
u8 flag;
int main(void){

	u16 p = 0;
	u16 Temp;

	u8 s5v[18]="Volt Range  0:5";
	u8 s10v[18]="Volt Range 0:10";
	f32 volt=0.0;
	//Initialization PORT Pins
	DIO_vidSetPortDir(DIO_PORTD,PORT_OUT);             /*D0 to D7 connected to PORTD*/
	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);

	/*Initialization Port_A pins connected to the relay and the switch_mode*/
	DDRB |= (1<<2);
	DDRB &=(~(1<<1));
//	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_INPUT);    //pin0 connected to the switch_mode --> input
	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN1,DIO_INPUT);    //pin1 connected to the p0 pin in relay (ADC input) --> input, "it can be not initialized"
//	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);   //pin2 connected to the

	LCD_voidInit();


	ADC_VidTnit();


	ADC_vidSetISR(ADC_ISRFunc);

	while(1){

	ADC_StartConversion(1);

//		if(((PINB >>1) & 1 )== 1)
//		{
//			PORTB |= (1<<2);
//			SET_BIT(PORTB,2);
//	        flag=N0;
//		}else if(((PINB >>1) & 1 )== 0)
//		{
//			PORTB &=(~(1<<2));
//			CLR_BIT(PORTB,2);
//            flag=NC;
//      }

//	if (DIO_u8GetPinVal(DIO_PORTB,DIO_PIN1)==DIO_HIGH){
//
//		DIO_vidSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
//		flag=N0;
//
//	}else if (DIO_u8GetPinVal(DIO_PORTB,DIO_PIN1)==DIO_LOW){
//
//		DIO_vidSetPinVal(DIO_PORTB,DIO_PIN2,DIO_LOW);
//		flag=NC;
//	}

	if (((PINB >>1) & 1 )==0){

		//TOGGLE(DIO_PORTB,DIO_PIN2);
		_delay_ms(10);
		while(((PINB >>1) & 1 )==0);
		PORTB ^=(1<<2);
		flag ^=1;
		volt=0.0;

	}

//	if (DIO_u8GetPinVal(DIO_PORTB,DIO_PIN1)==DIO_LOW){
//
//		//TOGGLE(DIO_PORTB,DIO_PIN2);
//		_delay_ms(10);
//		while(DIO_u8GetPinVal(DIO_PORTB,DIO_PIN1)==DIO_LOW);
//		flag ^=1;
//		DIO_vidSetPinVal(DIO_PORTB,DIO_PIN2,flag);
//		//PORTB ^=(1<<2);
//
//	}

	//convert ADC steps to voltage
	volt = (float)((u32)Digital*5)/(float)1024;
	//LCD_vidTnttoStr(volt);
	if(flag==NC){
		LCD_vidGetPosition(0,0);
		LCD_voidwriteStr(s5v);
		LCD_vidGetPosition(1,0);
		LCD_voidwriteStr("The Value = ");
		//LCD_voidwriteStr("here we try ");
		LCD_vidFloattoStr(volt);
	}
	else if(flag==N0){
		volt =volt*2;
		LCD_vidGetPosition(0,0);
		LCD_voidwriteStr(s10v);
		LCD_vidGetPosition(1,0);
		LCD_voidwriteStr("The Value = ");
		LCD_vidFloattoStr(volt);
	}

//	_delay_ms(1000);
//	LCD_voidSendCMD(LCD_CLR);
//	_delay_ms(200);

	}

	return 0;
}



void ADC_ISRFunc(void)
{
	Digital = ADC_GetConvertedDig();

}
