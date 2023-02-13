/*
 * ADC_Private.h
 *
 *  Created on: Dec 4, 2022
 *      Author: Alaa Ashraf
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define   ADC_REG    *((volatile u16*) 0x24)
#define   ADMUX_REG      *((volatile u8*) 0x27)
#define   ADCSRA_REG     *((volatile u8*) 0x26)



#define INTERNAL    3
#define AVCC        1
#define EXTERNAL    0

#define RIGHT       0
#define LEFT        1

#define ADLAR_PIN   5
#define REFS_PIN   6


// ADCSRA register pins
#define ADEN   7
#define ADSC   6
#define ADIF   5


#define ADC_INT  1
#define ADC_POLL 0

#endif /* ADC_PRIVATE_H_ */
