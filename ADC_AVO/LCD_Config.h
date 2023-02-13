/*
 * LCD_Config.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Alaa Ashraf
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Description: LCD Data Port Config*/
/*Range: DIO_u8PORTA ~ DIO_u8PORTD*/
#define LCD_DATA_PORT DIO_PORTD

/*Description: LCD Control Port Config*/
/*Range: DIO_u8PORTA ~ DIO_u8PORTD*/

#define LCD_CONTROL_PORT    DIO_PORTA

#define LCD_RS_PIN      DIO_PIN6

//#define LCD_RW_PIN      DIO_PIN6

#define LCD_E_PIN      DIO_PIN7

#endif /* LCD_CONFIG_H_ */
