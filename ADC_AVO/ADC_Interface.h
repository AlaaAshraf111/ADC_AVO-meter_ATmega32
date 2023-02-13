/*
 * ADC_Interface.h
 *
 *  Created on: Dec 4, 2022
 *      Author: Alaa Ashraf
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_EN_PIN   ADEN
#define ADC_SC_PIN   ADSC
#define ADC_FALG     ADIF

#define N0  1
#define NC 0


void ADC_VidTnit(void);

void ADC_EnableINT(void);
void ADC_DisableINT(void);

u16 ADC_u16GetReading(u8 chId);

void ADC_StartConversion(u8 chId);
u16 ADC_GetConvertedDig(void);
void ADC_vidSetISR(void (*p)(void));
#endif /* ADC_INTERFACE_H_ */
