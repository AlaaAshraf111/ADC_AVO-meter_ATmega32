/*
 * DIO1_Interface.h
 *
 *  Created on: Nov 18, 2022
 *      Author: Alaa Ashraf
 */
#include<stdio.h>
#ifndef DIO1_INTERFACE_H_
#define DIO1_INTERFACE_H_


/************************************************************************************/
/********************************Public Functions************************************/
/************************************************************************************/

/************************************************************************************
 * Description       : This function is used to set pin value to digital Low/High
 * Scope             : Public
 * Inputs(Arguments) : u8 PortId -> index of port number, Range :  [PORTA~PORTD]
 *                     u8 PinId -> index of Pin number in port, Range : [Pin0~Pin7]
 *                     u8 val   -> High/Low
 * Return            : void
 ************************************************************************************/
void DIO_vidSetPinVal(u8 PortId, u8 PinId, u8 val);
/************************************************************************************
 * Description       : This function is used to set pin direction to digital input/output
 * Scope             : Public
 * Inputs(Arguments) : u8 PortId -> index of port number, Range :  [PORTA~PORTD]
 *                     u8 PinId -> index of Pin number in port, Range : [Pin0~Pin7]
 *                     u8 dir   -> High/Low
 * Return            : void
 ************************************************************************************/
void DIO_vidSetPinDir(u8 PortId, u8 PinId, u8 dir);
/************************************************************************************
 * Description       : This function is used to set port value  high/low
 * Scope             : Public
 * Inputs(Arguments) : u8 PortId -> index of port number, Range :  [PORTA~PORTD]
 *                     u8 PinId -> index of Pin number in port, Range : [Pin0~Pin7]
 *                     u8 val   -> High/Low
 * Return            : void
 ************************************************************************************/
void DIO_vidSetPortval(u8 PortId, u8 val);
/************************************************************************************
 * Description       : This function is used to set port direction input/output port
 * Scope             : Public
 * Inputs(Arguments) : u8 PortId -> index of port number, Range :  [PORTA~PORTD]
 *                     u8 PinId -> index of Pin number in port, Range : [Pin0~Pin7]
 *                     u8 dir   -> High/Low
 * Return            : void
 ************************************************************************************/
void DIO_vidSetPortDir(u8 PortId, u8 dir);
/************************************************************************************
 * Description       : This function gets pin value to digital Low/High
 * Scope             : Public
 * Inputs(Arguments) : u8 PortId -> index of port number, Range :  [PORTA~PORTD]
 *                     u8 PinId -> index of Pin number in port, Range : [Pin0~Pin7]
 * Return            : u8
 ************************************************************************************/
u8 DIO_u8GetPinVal (u8 PortId, u8 PinId);



/************************************************************************************/
/********************************Public MACROs***************************************/
/************************************************************************************/
//Port definitions
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//Pins definitions
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//Digital Values
#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define PORT_HIGH 0xFF
#define PORT_OUT 0xFF



#endif /* DIO1_INTERFACE_H_ */
