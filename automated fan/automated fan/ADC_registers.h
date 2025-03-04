/*
 * ADC_registers.h
 *
 * Created: 2/15/2025 3:01:13 PM
 *  Author: Ahmad abdullatif
 */


#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_


#define ADMUX_REGISTER    (*(volatile u8*)0x27)   //ADC multiplexer selection register
#define ADCSRA_REGISTER   (*(volatile u8*)0x26)   //ADC Control and Status Register A
#define ADC_DATA_REGISTER (*(volatile u16*)0x24)
#define SFIOR_REGISTER    (*(volatile u8*)0x50)   //special function I/O register

//ADMUX bits macros
#define ADC_MUX0_BIT  0  //ADC analog channel and gain selection bits
#define ADC_MUX1_BIT  1
#define ADC_MUX2_BIT  2
#define ADC_MUX3_BIT  3
#define ADC_MUX4_BIT  4
#define ADC_ADLAR_BIT 5  //ADC left adjust result
#define ADC_REFS0_BIT 6  //ADC reference select bits
#define ADC_REFS1_BIT 7

//ADCSRA bits macros
#define ADC_ADPS0_BIT  0  //ADC prescaler selelct bits
#define ADC_ADPS1_BIT  1
#define ADC_ADPS2_BIT  2
#define ADC_ADIE_BIT   3  //ADC interrupt enable
#define ADC_ADIF_BIT   4  //ADC interrupt flag
#define ADC_ADATE_BIT  5  //ADC auto trigger enable
#define ADC_ADSC_BIT   6  //ADC start conversion
#define ADC_ADEN_BIT   7  //ADC enable

//SFIOR bits macros
#define ADC_ADTS0_BIT  5
#define ADC_ADTS1_BIT  6
#define ADC_ADTS2_BIT  7























#endif /* ADC_REGISTERS_H_ */
