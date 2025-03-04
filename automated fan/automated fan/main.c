/*
 * interfacing workshop1.c
 *
 * Created: 3/4/2025 1:43:43 AM
 * Author : Ahmad abdullatif
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"
#include "pwm0_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "DIO_interface.h"




int main(void)
{
	u16 local_u16AdcLogicalValue = 0, local_u16AdcAnalogValue = 0;
	
	//initializing modules
	PWM0_voidInit();
	LCD_voidInit();
	ADC_voidInit(ADC_AVCC);
	
	//configuring ADC pins
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
	//configuring H-bridge pins
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT); //H-bridge IN1
	DIO_voidSetPinValue    (DIO_PORTB,DIO_PIN1,DIO_LOW);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT); //H-bridge IN2
	DIO_voidSetPinValue    (DIO_PORTB,DIO_PIN2,DIO_HIGH);   
	
	//configuring PWM pins
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	
    while (1) 
    {
		//getting temperature logical value
		local_u16AdcLogicalValue = ADC_u16GetAdcResult(ADC_ADC0);
		
		//calculating analog value of temperature 
		local_u16AdcAnalogValue  = ((u32)local_u16AdcLogicalValue * 500)/1024;
		
		//displaying temperature on LCD
		LCD_voidDisplayString("temperature:");
		LCD_voidDisplayNumber(local_u16AdcAnalogValue);
		LCD_voidDisplayString("C");
		_delay_ms(500);
		LCD_voidClearLCD();
		
		//setting fan(DC motor) speed accroding to temperature
		if(local_u16AdcAnalogValue < 20){
			PWM0_voidStop();//50 75 85 100
		}
		else if(local_u16AdcAnalogValue >20 && local_u16AdcAnalogValue <25){
			PWM0_voidStart(50);
		}
		else if(local_u16AdcAnalogValue >25 && local_u16AdcAnalogValue <30){
			PWM0_voidStart(75);
		}
		else if(local_u16AdcAnalogValue >30 && local_u16AdcAnalogValue <35){
			PWM0_voidStart(85);
		}
		else if(local_u16AdcAnalogValue >35){
			PWM0_voidStart(100);
		}
		
		
    }
}

