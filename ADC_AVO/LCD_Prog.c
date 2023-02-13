/*
 * LCD_Prog.c
 *
 *  Created on: Nov 25, 2022
 *      Author: Alaa Ashraf
 */

#include<stdlib.h>
#include <string.h>
#include <avr/delay.h>
#include "types.h"
#include "BIT_MATH.h"

/* LCD */
#include "LCD_Interface.h"
#include "LCD_Config.h"

/* DIO */
#include"DIO1_Interface.h"


void LCD_voidInit(void)
{
	//Software Initialization of LCD
	_delay_ms(100);
	LCD_voidSendCMD(LCD_FUNCSET_8BIT);                //reset Lcd
	_delay_ms(2);                                     //according to datasheet we should wait until lcd excuates command
	LCD_voidSendCMD(LCD_DISPON_CURSONOFF);
	_delay_ms(2);
	LCD_voidSendCMD(LCD_CLR);
	_delay_ms(2);
	LCD_voidSendCMD(LCD_ENTRYMODE_LtoR);

}
void LCD_voidSendCMD(u8 u8cmd)
{
	//RS LOW
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	//COMMAND Sending to LCD
	DIO_vidSetPortval(LCD_DATA_PORT,u8cmd);
	//ENABLE
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);



}

void LCD_voidSendChar(u8 u8char)
{
	//RS HIGH
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	//DATA Sending to LCD
	DIO_vidSetPortval(LCD_DATA_PORT,u8char);
	//ENABLE
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}




void LCD_voidwriteStr(u8* pu8str){
	u16 i=0;

	while(pu8str[i] != 0){
	LCD_voidSendChar(pu8str[i]);
	i++;


}}


void LCD_vidTnttoStr(u16 d){

	u8 b[(sizeof (int))*5+1];
	itoa(d,b,10);
	LCD_voidwriteStr(b);


}



//void LCD_vidTnttoStr(u32 d){
//	//LCD_voidSendChar('r');
//	u8 b[sizeof(long int)*7+1];
//
////
////	sprintf(b, "%d", d);
//
//	ltoa(d,b,10);
//
//
//	LCD_voidwriteStr(b);
//
//
//}

void LCD_vidFloattoStr(f32 d){

	u16 x =(u16)d;
	f32 f =d-x;
	u8 b[sizeof(long int)*4+1];
	u16 i=0;

	//gcvt(d,6,b);

//    int decimal, sign;
//    char *buffer = ecvt(d, 11, &decimal, &sign);
	if(f==0.0)
	{
		LCD_vidTnttoStr(x);
	}else
	{
		u32 digit = (u32)(d*100);
		ltoa(digit,b,10);
			i=strlen(b);
			for(u16 j=0;j<i;j++){
				if((i-j)==2){
					while(i!=j){
						b[i]=b[i-1];
						i--;
					}
					b[j]='.';
				}
			}

			LCD_voidwriteStr(b);
	}


}





void LCD_vidGetPosition(u8 Row , u8  Col)
{
	u8 Address ;
	if(Row < 2 && Col <16)
	{
		Address = (0x40 * Row) + Col+ 0x80;
		//Address|=(1<<7);
		LCD_voidSendCMD(Address);
	}
//
//	if (Row == 0){
//						LCD_voidSendCMD(Col | 0x80);
//					}else if (Row ==1){
//						Col|=0x40;
//						LCD_voidSendCMD(Col | 0x80);
//					}
}


