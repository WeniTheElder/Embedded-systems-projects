/*
 * motorControl.c
 *
 * Created: 3/6/2025 10:18:40 PM
 * Author : Ahmad abdullatif
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "keyPad_interface.h"
#include "std_types.h"
#include "bit_math.h"
#include "pwm1_interface.h"

#define KEY_NOT_PRESSED 10

int main(void)
{
	u8 local_u8PressedKey = KEY_NOT_PRESSED;
    DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	KEYPAD_voidInit();
	PWM1_voidInit();
	LCD_voidInit();
	LCD_voidDisplayString("1)0 2)90 3)-90");
	PWM1_voidStart(10,50);
    while (1) 
    {

		KEYPAD_voidGetPressedKey(&local_u8PressedKey);
		if(local_u8PressedKey != KEY_NOT_PRESSED){
			switch(local_u8PressedKey){
				case '1':
				PWM1_voidStart(7.5,50);
				break;
				case '2':
				PWM1_voidStart(10,50);
				break;
				case '3':
				PWM1_voidStart(5,50);
				break;
				default:
				LCD_voidClearDisplay();
				LCD_voidDisplayString("invalid choice");
				_delay_ms(1000);
				LCD_voidClearDisplay();
				LCD_voidDisplayString("1)0 2)90 3)-90");
			}
			local_u8PressedKey = KEY_NOT_PRESSED;
		}
		
    }
}

