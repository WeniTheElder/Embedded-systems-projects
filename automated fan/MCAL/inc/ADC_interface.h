/*
 * ADC_interface.h
 *
 * Created: 2/15/2025 3:01:22 PM
 *  Author: Ahmad abdullatif
 */


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//ADC module is depending on manual initialization


//macros for reference voltage select
#define ADC_AREF          0
#define ADC_AVCC          1
#define ADC_INTERNAL_VREF 2

//macros for analog channels
#define ADC_ADC0 0
#define ADC_ADC1 1
#define ADC_ADC2 2
#define ADC_ADC3 3
#define ADC_ADC4 4
#define ADC_ADC5 5
#define ADC_ADC6 6
#define ADC_ADC7 7

void ADC_voidInit       (u8 copy_u8VrefType);
u16  ADC_u16GetAdcResult(u8 copy_u8AdcChannelId);





#endif /* ADC_INTERFACE_H_ */
