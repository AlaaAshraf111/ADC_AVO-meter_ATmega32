/*
 * LCD_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Alaa Ashraf
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/************************************************************************************/
/********************************Public MACROs***************************************/
/************************************************************************************/

#define LCD_CLR               0x01        //replace all characters with ASCII 'space'
#define LCD_HOME              0x02        //return cursor to the first position or first line
#define LCD_ENTRYMODE_LtoR    0x06        //shift cursor to from left to right on read/write
#define LCD_DISPOFF           0x08        //turn display off

#define LCD_DISPON_CURSON     0x0E        //display on, curson off, don't blink character
#define LCD_FUNCRESET         0x30		  //reset lcd
#define LCD_FUNCSET_8BIT      0x38        // 8-bit data, 2line display, 5x7 font
#define LCD_SETCURSOR         0x80        //set cursor position
#define LCD_DISPON_CURSBLINK  0x0F        //display on, cursor blinking

#define LCD_DISPON_CURSONOFF  0x0C        //display on, curson off





/************************************************************************************/
/********************************Public Functions***************************************/
/************************************************************************************/

void LCD_voidInit(void);

void LCD_voidSendCMD(u8 u8cmd);

void LCD_voidSendChar(u8 u8char);

void LCD_voidwriteStr(u8* pu8str);

void LCD_voidGoToXY(u8 x, u8 y);


void LCD_vidTnttoStr(u16 d);

void LCD_vidFloattoStr(f32 d);

void LCD_vidGetPosition(u8 Row , u8  Col);

#endif /* LCD_INTERFACE_H_ */
